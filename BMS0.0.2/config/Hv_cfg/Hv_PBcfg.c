#include "Vbat.h"
#include "Hv_cfg.h"
#include "Hv_PBcfg.h"


Hv_DataCxtCfgType Hv_Data[Hv_MAXPASSANUM] =
{
    {Hv_GetVoltageFct,Hv_GetCurrentFct,Hv_GetTempFct,0},
};

