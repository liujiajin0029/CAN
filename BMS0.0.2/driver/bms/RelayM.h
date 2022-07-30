#ifndef __RELAYM_H
#define __RELAYM_H

#include "hidef.h"
#include "derivative.h"
#include "VBAT.h"


#define RELAYM_PRESWITCHON      (1U)
#define RELAYM_PRESWITCHOFF     (0U)
#define RELAYM_PRE_IOON         (1U)
#define RELAYM_PRE_IOOFF        (1U)
#define RELAYM_CLOSEDTOTALON    (5U)
#define RELAYM_CLOSEDTOTALOFF   (0U)
#define RELAYM_CLOSEDTOTALIO    (1U)


#define RELAYM_RES_SUPPORT FALSE
#define RELAYM_SET_SUPPORT TRUE
#define RELAYM_STATERETVAL3 TRUE

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
}Relaym_StateRetvalType;


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

typedef enum RELAYM_HaveAttribute
{
    RELAYM_HAVE_CTL,
    RELAYM_NOT_HAVE_CTL,
    RELAYM_HAVE_RES,
    RELAYM_NOT_HAVE_RES,
    RELAYM_HAVE_ONTIME,
    RELAYM_NOT_HAVE_ONTIME,
    RELAYM_HAVE_OFFTIME,
    RELAYM_NOT_HAVE_OFFTIME,
}RELAYM_Attribute;


typedef struct _RelayM_ControlType
{
    RELAYM_Attribute Ctl;      /*¼ÌµçÆ÷Êä³öµÄ¿ØÖÆ×´Ì¬*/
    RELAYM_Attribute OnTime;   /*¼ÌµçÆ÷Êä³öµÄ±ÕºÏÊ±¼ä*/
    RELAYM_Attribute OffTime;  /*¼ÌµçÆ÷Êä³öµÄ¶Ï¿ªÊ±¼ä*/
    RELAYM_Attribute Res;      /*¼ÌµçÆ÷µÄÄÚ×èÊ±¼ä*/
    RELAYM_Attribute passage;
}RelayM_FnType;


typedef struct _RelayM_DataCfgType
{
    uint8 Ctl;      /*¼ÌµçÆ÷Êä³öµÄ¿ØÖÆ×´Ì¬*/
    uint8 OnTime;   /*¼ÌµçÆ÷Êä³öµÄ±ÕºÏÊ±¼ä*/
    uint8 OffTime;  /*¼ÌµçÆ÷Êä³öµÄ¶Ï¿ªÊ±¼ä*/
    uint8 Res;      /*¼ÌµçÆ÷µÄÄÚ×èÊ±¼ä*/
    uint8 passage;
}RelayM_DataCfgType;


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
    uint8 (*Ctl)(RelayM_DataCfgType *cfg);/*¼ÌµçÆ÷¿ØÖÆ×´Ì¬*/
    uint8 (*OnTime)(RelayM_DataCfgType *cfg);/*¼ÌµçÆ÷¿ØÖÆ±ÕºÏÊ±¼ä*/
    uint8 (*OffTime)(RelayM_DataCfgType *cfg);/*¼ÌµçÆ÷¿ØÖÆ¶Ï¿ªÊ±¼ä*/
    uint8 (*Res)(RelayM_DataCfgType *cfg);/*¼ÌµçÆ÷ÄÚ×èÉèÖÃ*/
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


uint8 RelayM_GetOnTime(uint8 pas);
int RelayM_SetOnTime(uint8 ctl ,uint8 pas);
uint8  RelayM_StateCtlWrite(RelayM_DataCfgType *cfg);
uint8  RelayM_OnTimeCtlWrite(RelayM_DataCfgType *cfg);
uint8  RelayM_OffTimeCtlWrite(RelayM_DataCfgType *cfg);
uint8  RelayM_ResCtlWrite(RelayM_DataCfgType *cfg);

#endif
