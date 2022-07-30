#include "RelayM.h"
#include "derivative.h"
#include "RelayM_cfg.h"

void RelayM_InterruptOFF()
{

}

void RelayM_InterruptON()
{

}


Bool RelayM_IOSetMsg(uint8 IO, uint8 data)
{
    return TRUE;
}


uint8  RelayM_StateCtlWrite(RelayM_DataCfgType *cfg)
{
    uint8 data;
    uint8 retval;
    data = cfg->Ctl;
    if(RelayM_IOSetMsg(cfg->passage , data) == TRUE)
    {
        retval = data;

    }
    else
    {

    }
    return retval;
}


uint8  RelayM_OnTimeCtlWrite(RelayM_DataCfgType *cfg)
{
    uint8 data;
    uint8 retval;
    data = cfg->OnTime;
    if(RelayM_IOSetMsg(cfg->passage , data) == TRUE)
    {
        retval = data;

    }
    else
    {

    }
    return retval;
}

uint8  RelayM_OffTimeCtlWrite(RelayM_DataCfgType *cfg)
{
    uint8 data;
    uint8 retval;
    data = cfg->OffTime;
    if(RelayM_IOSetMsg(cfg->passage , data) == TRUE)
    {
       retval = data;
    }
    else
    {

    }
    return retval;
}
uint8  RelayM_ResCtlWrite(RelayM_DataCfgType *cfg)
{
    uint8 data;
    uint8 retval;
    data = cfg->Res;
    if(RelayM_IOSetMsg(cfg->Res , data) == TRUE)
    {
        retval = data;
    }
    else
    {

    }
    return retval;
}

uint8 RelayM_SetControL(uint8 ctl ,uint8 pas)
{
      return ctl - pas;
}

int RelayM_SetOnTime(uint8 ctl ,uint8 pas)
{

}



Relaym_StateRetvalType RelayM_FunctionControl(RelayM_FnType *fn, RelayM_DataCfgType *ctl)
{
    Relaym_StateRetvalType retval;
   if (fn->Ctl == RELAYM_HAVE_CTL )
   {
        RelayM_StateCtlWrite(&ctl);
   }
   if (fn->OnTime == RELAYM_HAVE_ONTIME )
   {
        RelayM_OnTimeCtlWrite(&ctl);
   }
   if (fn->OffTime == RELAYM_NOT_HAVE_OFFTIME )
   {
        RelayM_OffTimeCtlWrite(&ctl);
   }
   if (fn->Res == RELAYM_HAVE_RES )
   {
        RelayM_ResCtlWrite(&ctl);
   }
}


uint8 RelayM_GetControL(uint8 pas)
{

}
uint8 RelayM_GetOnTime(uint8 pas)
{
    return  0;
}


RelayM_ActureCallType RelayM_ReadAllData(uint8 pas)
{
    uint8 i;
    RelayM_ActureCallType retval;
    /**/
    RelayM_InterruptOFF();
    retval.Act = RelayM_StateData[pas].get -> Act(pas);
    retval.Ctl = RelayM_StateData[pas].get -> Ctl(pas);
    retval.OnTime = RelayM_StateData[pas].get -> OnTime(pas);
    retval.OffTime = RelayM_StateData[pas].get -> OffTime(pas);
    retval.Res = RelayM_StateData[pas].get -> Res(pas);
    retval.passage = RelayM_StateData[pas].get->passage;
    RelayM_InterruptON();
    return retval;
}



uint8 RelayM_ReadAloneData(uint8 pas ,RELAYM_STATEMSGTYPE state)
{
    uint8 retval;
    /**/
    RelayM_InterruptOFF();
    switch ( state )
    {
        case RELAYM_ACTSTATE:
        retval = RelayM_StateData[pas].get -> Act(pas);
        break;

        case RELAYM_CONTROLSTATE:
        retval = RelayM_StateData[pas].get -> Ctl(pas);
        break;

        case RELAYM_ONTIMEACTSTATE:
        retval = RelayM_StateData[pas].get -> OnTime(pas);
        break;

        case RELAYM_OFFTIMESTATE:
        retval = RelayM_StateData[pas].get -> OffTime(pas);
        break;

        case RELAYM_RESSTATE:
         retval = RelayM_StateData[pas].get -> Res(pas);
        break;
    }
    RelayM_InterruptON();

    return retval;
}

