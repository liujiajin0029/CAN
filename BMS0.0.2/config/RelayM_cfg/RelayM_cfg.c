#include "RelayM.h"
#include "RelayM_cfg.h"

RelayM_ActureType   RelayM_ActureData[10] =
{
    {RelayM_GetActTime,RelayM_GetControL,RelayM_GetOnTime,
     RelayM_GetOffTime,RelayM_GetResTime,0},
};

RelayM_CtlCxtType   RelayM_ControlData[10]=
{
    {RelayM_StateCtlWrite,RelayM_OnTimeCtlWrite,RelayM_OffTimeCtlWrite,
     RelayM_ResCtlWrite,0},
};

RelayM_MsgCfgType   RelayM_StateData[10]  =
{
   {0,&RelayM_ActureData[0],&RelayM_ControlData[0]},
   {1,&RelayM_ActureData[1],&RelayM_ControlData[1]},
};

RelayM_FnType   RelayM_FnDataType =
{
    RELAYM_HAVE_CTL,
    RELAYM_HAVE_ONTIME,
    RELAYM_HAVE_OFFTIME,
    RELAYM_NOT_HAVE_OFFTIME,
    RELAYM_CHANNEL_0,
};

RelayM_ControLCfgType   RelayM_CtlDataType =
{
    1,10,50,300,0,
};