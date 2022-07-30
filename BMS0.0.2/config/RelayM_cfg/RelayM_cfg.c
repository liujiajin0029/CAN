#include "RelayM.h"
#include "RelayM_cfg.h"



RelayM_ActureType  RelayM_ActureData[10] =
{
    {RelayM_GetOnTime,RelayM_GetOnTime,RelayM_GetOnTime,
     RelayM_GetOnTime,RelayM_GetOnTime,0},
};

RelayM_CtlType   RelayM_ControlData[10]=
{
    {RelayM_StateCtlWrite,RelayM_OnTimeCtlWrite,RelayM_OffTimeCtlWrite,
     RelayM_ResCtlWrite,0},
};


RelayM_MsgCfgType RelayM_StateData[10]  =
{
   {0,&RelayM_ActureData[0],&RelayM_ControlData[0]},
   {1,&RelayM_ActureData[1],&RelayM_ControlData[1]},
};