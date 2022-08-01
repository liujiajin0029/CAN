#include "RelayM.h"
#include "derivative.h"
#include "RelayM_cfg.h"
#include "RelayM_Lcfg.h"
#include "RelayM_PBcfg.h"

void RelayM_InterruptOFF()
{

}

void RelayM_InterruptON()
{

}

uint8 RelayM_IOSetMsg(uint8 IO, uint8 data)
{
    IO = data;
    return IO;
}

uint8 RelayM_GetControL(uint8 pas)
{
    pas = 1;
    return pas;
}
uint8 RelayM_GetOnTime(uint8 pas)
{
    pas = 1;
    return pas;
}
uint8 RelayM_GetOffTime(uint8 pas)
{
    pas = 1;
    return pas;
}
uint8 RelayM_GetResTime(uint8 pas)
{
    pas = 1;
    return pas;
}
uint8 RelayM_GetActTime(uint8 pas)
{
    pas = 1;
    return pas;
}

uint8 RelayM_StateCtlWrite(RelayM_ControLCfgType *cfg)
{
    uint8 data;
    uint8 retval;
    data = cfg->Ctl;
    if (RelayM_IOSetMsg(cfg->passage, data) == TRUE)
    {
        retval = data;
    }
    else
    {

    }
    return retval;
}


uint8 RelayM_OnTimeCtlWrite(RelayM_ControLCfgType *cfg)
{
    uint8 data;
    uint8 retval;
    data = cfg->OnTime;
    if (RelayM_IOSetMsg(cfg->passage, data) == TRUE)
    {
        retval = data;
    }
    else
    {

    }
    return retval;
}

uint8 RelayM_OffTimeCtlWrite(RelayM_ControLCfgType *cfg)
{
    uint8 data;
    uint8 retval;
    data = cfg->OffTime;
    if (RelayM_IOSetMsg(cfg->passage, data) == 1)
    {
       retval = data;
    }
    else
    {

    }
    return retval;
}
uint8 RelayM_ResCtlWrite(RelayM_ControLCfgType *cfg)
{
    uint8 data;
    uint8 retval;
    data = cfg->Res;
    if (RelayM_IOSetMsg(cfg->Res, data) == TRUE)
    {
        retval = data;
    }
    else
    {

    }
    return retval;
}

Relaym_StateRetvalType RelayM_FnControl(RelayM_FnType *fn, RelayM_ControLCfgType *ctl)
{
    Relaym_StateRetvalType retval;
   if (fn->Ctl == RELAYM_HAVE_CTL )
   {
        if (RelayM_StateCtlWrite(ctl) == 1)
        {
           retval = RELAYM_STATE_RETVAL_ON;
        }
   }
   if (fn->OnTime == RELAYM_HAVE_ONTIME )
   {
        if (RelayM_OnTimeCtlWrite(ctl) == 1)
        {
           retval = RELAYM_STATE_RETVAL_ON;
        }
   }
   if (fn->OffTime == RELAYM_NOT_HAVE_OFFTIME )
   {
        if (RelayM_OffTimeCtlWrite(ctl) == 1)
        {
           retval = RELAYM_STATE_RETVAL_ON;
        }
   }
   if (fn->Res == RELAYM_HAVE_RES )
   {
        if (RelayM_ResCtlWrite(ctl) == 1)
        {
          retval = RELAYM_STATE_RETVAL_ON;
        }
   }
   return retval;
}


RelayM_ActureCallType RelayM_ReadAllData(uint8 pas, RelayM_ActureCxtType *cfg)
{
    RelayM_ActureCallType retval;
    /*数组越界保护*/
    if (pas < RELAYM_MAX_PASSANUM)
    {
        RelayM_InterruptOFF();

        RelayM_StateData[pas].get -> Act = (cfg->Act);
        retval.Act = RelayM_StateData[pas].get -> Act(pas);

        RelayM_StateData[pas].get -> Ctl = (cfg->Ctl);
        retval.Ctl = RelayM_StateData[pas].get -> Ctl(pas);

        RelayM_StateData[pas].get -> OnTime = (cfg->OnTime);
        retval.OnTime = RelayM_StateData[pas].get -> OnTime(pas);

        RelayM_StateData[pas].get -> OffTime = (cfg->OffTime);
        retval.OffTime = RelayM_StateData[pas].get -> OffTime(pas);

        RelayM_StateData[pas].get -> Res = (cfg->Res);
        retval.Res = RelayM_StateData[pas].get -> Res(pas);

        retval.passage = RelayM_StateData[pas].get-> passage;
        RelayM_InterruptON();
    }
    return retval;
}

uint8 RelayM_ReadAloneData(uint8 pas, Relaym_SateMsgType state)
{
    uint8 retval;
    /*数组越界保护*/
    if (pas < RELAYM_MAX_PASSANUM)
    {
        RelayM_InterruptOFF();
        switch (state)
        {
            case RELAYM_ACTURE_STATE:
            retval = RelayM_StateData[pas].get -> Act(pas);
            break;

            case RELAYM_CONTROL_STATE:
            retval = RelayM_StateData[pas].get -> Ctl(pas);
            break;

            case RELAYM_ON_TIME_STATE:
            retval = RelayM_StateData[pas].get -> OnTime(pas);
            break;

            case RELAYM_OFF_TIME_STATE:
            retval = RelayM_StateData[pas].get -> OffTime(pas);
            break;

            case RELAYM_RES_STATE:
            retval = RelayM_StateData[pas].get -> Res(pas);
            break;
        }
        RelayM_InterruptON();
    }
    return retval;
}

