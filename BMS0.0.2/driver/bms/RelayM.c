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
uint8 RelayM_GetOnTime(uint8 time)
{
    time = 1;
    return time;
}
uint8 RelayM_GetOffTime(uint8 time)
{
    time = 1;
    return time;
}
uint8 RelayM_GetResTime(uint8 time)
{
    time = 1;
    return time;
}
uint8 RelayM_GetActstate(uint8 pas)
{
    pas = 1;
    return pas;
}

uint8 (*RelayM_Get[])(uint8) =
{
    RelayM_GetActstate,
    RelayM_GetControL,
    RelayM_GetOnTime,
    RelayM_GetOffTime,
    RelayM_GetResTime,
};

uint8 RelayM_StateCtlWrite(uint8 pas, uint8 data)
{
    uint8 retval;
    if (RelayM_IOSetMsg(pas, data) == TRUE)
    {
        retval = data;
    }
    else
    {

    }
    return retval;
}

uint8 RelayM_OnTimeCtlWrite(uint8 pas, uint8 data)
{
    uint8 retval;
    if (RelayM_IOSetMsg(pas, data) == TRUE)
    {
        retval = data;
    }
    else
    {

    }
    return retval;
}


uint8 RelayM_OffTimeCtlWrite(uint8 pas, uint8 data)
{
    uint8 retval;
    if (RelayM_IOSetMsg(pas, data) == 1)
    {
       retval = data;
    }
    else
    {

    }
    return retval;
}


uint8 RelayM_ResCtlWrite(uint8 pas, uint8 data)
{
    uint8 retval;
    if (RelayM_IOSetMsg(pas, data) == TRUE)
    {
        retval = data;
    }
    else
    {

    }
    return retval;
}

Relaym_RetvalType RelayM_FnControl(RelayM_FnType *fn, RelayM_CtlCallType *ctl)
{
    Relaym_RetvalType retval;
   if (fn->Ctl == RELAYM_CTL )
   {
        if (RelayM_StateCtlWrite(ctl->Ctl,ctl->passage) == 1)
        {
           retval = RELAYM_STATE_RETVAL_ON;
        }
   }
   if (fn->OnTime == RELAYM_ONTIME )
   {
        if (RelayM_OnTimeCtlWrite(ctl->OnTime,ctl->passage) == 1)
        {
           retval = RELAYM_STATE_RETVAL_ON;
        }
   }
   if (fn->OffTime == RELAYM_NOT_OFFTIME )
   {
        if (RelayM_OffTimeCtlWrite(ctl->OffTime,ctl->passage) == 1)
        {
           retval = RELAYM_STATE_RETVAL_ON;
        }
   }
   if (fn->Res == RELAYM_RES )
   {
        if (RelayM_ResCtlWrite(ctl->Res,ctl->passage) == 1)
        {
          retval = RELAYM_STATE_RETVAL_ON;
        }
   }
   return retval;
}


RelayM_ActCallType RelayM_ReadAllData(uint8 pas, RelayM_ActInfoType *cfg)
{
    RelayM_ActCallType retval;
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

uint8 RelayM_StateDatanum = 0;
uint8  (*RelayM_AloneState[])(uint8 i) = {RelayM_StateData[RelayM_StateDatanum].get -> Act,
                                          RelayM_StateData[RelayM_StateDatanum].get -> Ctl,
                                          RelayM_StateData[RelayM_StateDatanum].get -> OnTime,
                                          RelayM_StateData[RelayM_StateDatanum].get -> OffTime,
                                          RelayM_StateData[RelayM_StateDatanum].get -> Res};

uint8 RelayM_ReadAloneData(uint8 pas, Relaym_SateMsgType state)
{

    uint8 retval;
    /*数组越界保护*/
    if (pas < RELAYM_MAX_PASSANUM)
    {
        RelayM_InterruptOFF();

        RelayM_StateDatanum =  pas;
        retval = RelayM_AloneState[state](pas);
        RelayM_InterruptON();
    }
    return retval;
}

