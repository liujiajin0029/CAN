#include "RelayM.h"
#include "RelayM_cfg.h"

RelayM_ActureCxtType   RelayM_ActureData[10] =
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