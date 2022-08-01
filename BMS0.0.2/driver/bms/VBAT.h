#ifndef __VBAT_DATA_H
#define __VBAT_DATA_H
#include "hidef.h"
#include "derivative.h"

#define HV_GEWAY_MAX_TEMP     (100U)
#define HV_GEWAY_MAX_CURRENT  (100U)
#define HV_GEWAY_MAX_VOLTAGE  (100U)
#define HV_GEWAY_MIN_TEMP     (10U)
#define HV_GEWAY_MIN_CURRENT  (10U)
#define HV_GEWAY_MIN_VOLTAGE  (10U)

typedef struct  _Hv_RetvalType
{
    uint8 Voltage;
    uint8 Current;
    uint8 Temp;
    uint8 passa;
    uint8 power;
}Hv_RetvalType;

typedef enum _HV_ATTRIBUTETYPE
{
    HV_GEWAY_VOLTAGE,
    HV_GEWAY_CURRENT,
    HV_GEWAY_TEMP,
}Hv_AttriButeType;


typedef struct _HV_CfgPass
{
    Hv_AttriButeType geway;
    uint8 passageway;
}HV_PassCfgType;


typedef struct _Hv_DemoDataType
{
    uint8 (*Voltage)(uint8 pas);
    uint8 (*Current)(uint8 pas);
    uint8 (*Temp)(uint8 pas);
    uint8 passa;
}Hv_DataCxtType;

Hv_RetvalType Hv_GetVoltage(uint8 geway);
Bool Hv_DataManage(uint8 data, uint8 MAX, uint8 MIN);
uint8 Hv_GetAlonMsg(HV_PassCfgType *cfg, Hv_DataCxtType *msg);
Bool Hv_OpenCheck(Hv_RetvalType *cfg);
Hv_RetvalType Hv_GetVoltageData(uint8 geway, Hv_DataCxtType *cfg); //µçÑ¹
uint8 Hv_GetVoltageFct(uint8 pas);
uint8 Hv_GetCurrentFct(uint8 pas);
uint8 Hv_GetTempFct(uint8 pas);



#endif
