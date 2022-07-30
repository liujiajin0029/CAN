#ifndef __VBAT_DATA_H
#define __VBAT_DATA_H
#include "hidef.h"
#include "derivative.h"

#define HV_GEWAYMAXTEMP     100
#define HV_GEWAYMAXCURRENT  100
#define HV_GEWAYMAXVOLTAGE  100
#define HV_GEWAYMINTEMP     10
#define HV_GEWAYMINCURRENT  10
#define HV_GEWAYMINVOLTAGE  10

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
    HV_GEWAYVOLTAGE,
    HV_GEWAYCURRENT,
    HV_GEWAYTEMP,
}HV_ATTRIBUTETYPE;


typedef struct _HV_CfgPass
{
    HV_ATTRIBUTETYPE geway;
    uint8 passageway;
}HV_CfgPassType;


typedef struct _Hv_DemoDataType
{
    uint8 (*Voltage)(uint8 pas);
    uint8 (*Current)(uint8 pas);
    uint8 (*Temp)(uint8 pas);
    uint8 passa;
}Hv_DataCxtCfgType;

Hv_RetvalType Hv_GetVoltage(uint8 geway);
Bool Hv_DataManage(uint8 data ,uint8 MAX ,uint8 MIN);
uint8 Hv_GetAlonMsg(HV_CfgPassType *Hv_msg);
Bool Hv_OpenPitCheck(Hv_RetvalType retval);
Hv_RetvalType Hv_GetVoltageData (uint8 geway); //µçÑ¹
uint8 Hv_GetVoltageFct(uint8 pas);
uint8 Hv_GetCurrentFct(uint8 pas);
uint8 Hv_GetTempFct(uint8 pas);



#endif
