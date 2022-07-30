#ifndef __VBAT_DATA_H
#define __VBAT_DATA_H
#include "hidef.h"
#include "derivative.h"




#define HV_GEWAYMAXTEMP 100
#define HV_GEWAYMAXCURRENT 100
#define HV_GEWAYMAXVOLTAGE  100
#define HV_GEWAYMINTEMP     10
#define HV_GEWAYMINCURRENT  10
#define HV_GEWAYMINVOLTAGE  10



typedef struct  _Hv_RetvalType
{
    uint32 Voltage;
    uint32 Current;
    uint32 Temp;
    uint32 passa;
    uint32 power;
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
}HV_CfgPass;


typedef struct _Hv_DemoDataType
{
    uint32 (*Voltage)(void);
    uint32 (*Current)(void);
    uint32 (*Temp)(void);
    uint8 passa;
}Hv_DemoDataType;

Hv_RetvalType Hv_GetVoltage(uint8 geway);
Bool Hv_DataDeal(uint32 data ,uint32 MAX ,uint32 MIN);
uint8 HV_poll(HV_CfgPass *Hv_msg);
Bool Hv_OpenPitCheck(Hv_RetvalType retval);


float VBAT_BATGet(void);

float VBAT_V1Get(void);



#endif
