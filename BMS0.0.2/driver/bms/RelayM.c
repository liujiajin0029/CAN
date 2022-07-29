#include "RelayM.h"
#include "derivative.h"

typedef enum _Hv_ChannelType
{
    RELAYM_ACTSTATE,
    RELAYM_CONTROLSTATE,
    RELAYM_ONTIMEACTSTATE,
    RELAYM_OFFTIMESTATE,
    RELAYM_RESSTATE,
    RELAYM_FNCLOSE_RELAY,/*闭合继电器*/
    RELAYM_DISCONNECT_RELAY,/*断开继电器*/
} RELAYM_STATEMSGTYPE;


typedef enum _RELAYM_STATERETVAL
{
    RELAYM_STATERETVALON,
    RELAYM_STATERETVALOFF,
}RELAYM_STATERETVAL;


typedef enum _RELAYM_ChannelType
{
    RELAYM_CHANNEL_0,
    RELAYM_CHANNEL_1,
    RELAYM_CHANNEL_2,
    RELAYM_CHANNEL_3,
    RELAYM_CHANNEL_4,
    RELAYM_CHANNEL_5,
    RELAYM_CHANNEL_6,
    RELAYM_CHANNEL_7,
    RELAYM_CHANNEL_8,
} RELAYM_ChannelType;

//----------------------------------------------------

typedef struct _RelayM_ControlType
{
    uint8 Ctl;      /*¼ÌµçÆ÷Êä³öµÄ¿ØÖÆ×´Ì¬*/
    uint8 OnTime;   /*¼ÌµçÆ÷Êä³öµÄ±ÕºÏÊ±¼ä*/
    uint8 OffTime;  /*¼ÌµçÆ÷Êä³öµÄ¶Ï¿ªÊ±¼ä*/
    uint8 Res;      /*¼ÌµçÆ÷µÄÄÚ×èÊ±¼ä*/
    uint8 passage;
}RelayM_Fn_Type;


/*Êµ¼Ê×´Ì¬ÐÅÏ¢£¬ÐèÒª¶ÁÈ¡µÄ×´Ì¬*/
typedef struct _RelayM_ActureType
{
    uint8 (*Act)(uint8 pas);/*¼ÌµçÆ÷Êä³öµÄÊµ¼Ê×´Ì¬*/
    uint8 (*Ctl)(uint8 pas);/*¼ÌµçÆ÷Êä³öµÄ¿ØÖÆ×´Ì¬*/
    uint8 (*OnTime)(uint8 pas);/*¼ÌµçÆ÷Êä³öµÄ±ÕºÏÊ±¼ä*/
    uint8 (*OffTime)(uint8 pas);/*¼ÌµçÆ÷Êä³öµÄ¶Ï¿ªÊ±¼ä*/
    uint8 (*Res)(uint8 pas);/*¼ÌµçÆ÷µÄÄÚ×èÊ±¼ä*/
    uint8    passage;
}RelayM_ActureType;

/*¿ØÖÆ×´Ì¬£¬ÐèÒªÉèÖÃµÄ×´Ì¬*/
typedef struct _RelayM_CtlType
{
    uint8 (*Ctl)(uint8 ctl ,uint8 pas);/*¼ÌµçÆ÷¿ØÖÆ×´Ì¬*/
    uint8 (*OnTime)(uint8 time ,uint8 pas);/*¼ÌµçÆ÷¿ØÖÆ±ÕºÏÊ±¼ä*/
    uint8 (*OffTime)(uint8 time ,uint8 pas);/*¼ÌµçÆ÷¿ØÖÆ¶Ï¿ªÊ±¼ä*/
    uint8 (*Res)(uint8 res,uint8 pas);/*¼ÌµçÆ÷ÄÚ×èÉèÖÃ*/
    uint8    passage;
}RelayM_CtlType;


typedef struct _RelayM_MsgCfgType
{
    uint8    passage;
    RelayM_ActureType *get;
    RelayM_CtlType *ctl;
}RelayM_MsgCfgType;

typedef struct _RelayM_CtlCfgType
{
    uint8    passage;
    RelayM_CtlType *ctl;
}RelayM_CtlCfgType;


typedef struct _RelayM_ActCfgType
{
    uint8    passage;
    RelayM_ActureType *get;
}RelayM_ActCfgType;



typedef struct _RelayM_ActureCallType
{
    uint8 Act;      /*¼ÌµçÆ÷Êä³öµÄÊµ¼Ê×´Ì¬*/
    uint8 Ctl;      /*¼ÌµçÆ÷Êä³öµÄ¿ØÖÆ×´Ì¬*/
    uint8 OnTime;   /*¼ÌµçÆ÷Êä³öµÄ±ÕºÏÊ±¼ä*/
    uint8 OffTime;  /*¼ÌµçÆ÷Êä³öµÄ¶Ï¿ªÊ±¼ä*/
    uint8 Res;      /*¼ÌµçÆ÷µÄÄÚ×èÊ±¼ä*/
    uint8 passage;
}RelayM_ActureCallType;


RelayM_ActureType  RelayM_ActureData[10] =
{
    {RelayM_GetOnTime,RelayM_GetOnTime,RelayM_GetOnTime,RelayM_GetOnTime,RelayM_GetOnTime},
};

RelayM_CtlType   RelayM_ControlData[10]=
{
    {RelayM_SetOnTime,RelayM_SetOnTime,RelayM_SetOnTime,RelayM_SetOnTime},
};


RelayM_MsgCfgType RelayM_StateData[10]  =
{
   {0,&RelayM_ActureData[0],&RelayM_ControlData[0]},
   {1,&RelayM_ActureData[1],&RelayM_ControlData[1]},
};

int RelayM_SetOnTime(uint8 ctl ,uint8 pas)
 {
 
 }
    
    
void RelayM_Change(unsigned char Switch)            //    开关切换函数
{
    if (Switch == RELAYM_PRESWITCHON)
    {
        RelayM_Control(RELAYM_PRE_IOON,1);
    }
    else if (Switch == RELAYM_PRESWITCHOFF)
    {
        RelayM_Control(RELAYM_PRE_IOOFF,0);
    }
    else if (Switch == RELAYM_CLOSEDTOTALON)
    {
        RelayM_Control(RELAYM_PRE_IOOFF,0);
        RelayM_Control(RELAYM_CLOSEDTOTALIO,1);
    }
    else
    {

    }
}

void RelayM_Control(unsigned char Pre_switch,unsigned char  state)
{
   if (RELAYM_PRE_IOON == Pre_switch)
   {

   }
}


RELAYM_STATERETVAL  RelayM_OnTimeCtlWrite(RelayM_Fn_Type *msg)
{
    uint8 data;
    RELAYM_STATERETVAL retval;
    data = msg->OnTime;
    if(1)
    {
        return retval;
    }
    else
    {

    }
}

RELAYM_STATERETVAL  RelayM_OffTimeCtlWrite(RelayM_Fn_Type *msg)
{
    uint8 data;
    RELAYM_STATERETVAL retval;
    data = msg->OffTime;
    if(1)
    {
        return retval;
    }
    else
    {

    }
}
RELAYM_STATERETVAL  RelayM_ResCtlWrite(RelayM_Fn_Type *msg)
{
    uint8 data;
    RELAYM_STATERETVAL retval;
    data = msg->Res;
    if(1)
    {
        return retval;
    }
    else
    {

    }
}



RELAYM_STATERETVAL RelayM_FunctionControl(RelayM_FnType fn, RelayM_CtlType ctl)
{

}



/*Ð´Èë¼ÌµçÆ÷ÅäÖÃÐÅÏ¢*/
uint8 RelayM_GetActure(uint8 pas)
{
    return  0;
}
/*Ð´Èë¼ÌµçÆ÷ÅäÖÃÐÅÏ¢*/
uint8 RelayM_GetControL(uint8 pas)
{
     return  0;
}

uint8 RelayM_GetOnTime(uint8 pas)
{
    return  0;
}

uint8 RelayM_GetOffTime(uint8 pas)
{
    return  0;
}

uint8 RelayM_GetResTime(uint8 pas)
{
    return  0;
}

RelayM_InterruptOFF()
{

}

RelayM_InterruptON()
{

}
RelayM_ActureCallType RelayM_ReadAllData(uint8 pra)
{
    uint8 i;
    RelayM_ActureCallType retval;
    /**/
    RelayM_InterruptOFF();
    retval.Act = RelayM_StateData[pra].get -> Act(pra);
    retval.Ctl = RelayM_StateData[pra].get -> Ctl(pra);
    retval.OnTime = RelayM_StateData[pra].get -> OnTime(pra);
    retval.OffTime = RelayM_StateData[pra].get -> OffTime(pra);
    retval.Res = RelayM_StateData[pra].get -> Res(pra);
    retval.passage = RelayM_StateData[pra].get->passage;
    RelayM_InterruptON();
    return retval;
}



uint8 RelayM_ReadAloneData(uint8 pra ,RELAYM_STATEMSGTYPE state)
{
    uint8 retval;
    /**/
    RelayM_InterruptOFF();
    switch ( state )
    {
        case RELAYM_ACTSTATE:
        retval = RelayM_StateData[pra].get -> Act(pra);
        break;

        case RELAYM_CONTROLSTATE:
        retval = RelayM_StateData[pra].get -> Ctl(pra);
        break;

        case RELAYM_ONTIMEACTSTATE:
        retval = RelayM_StateData[pra].get -> OnTime(pra);
        break;

        case RELAYM_OFFTIMESTATE:
        retval = RelayM_StateData[pra].get -> OffTime(pra);
        break;

        case RELAYM_RESSTATE:
         retval = RelayM_StateData[pra].get -> Res(pra);
        break;
    }
    RelayM_InterruptON();

    return retval;
}

