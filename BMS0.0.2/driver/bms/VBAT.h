#ifndef __VBAT_DATA_H
#define __VBAT_DATA_H
#include "hidef.h"
#include "derivative.h"


#define Hv_MAXPASSANUM 5

#define HV_GEWAYMAXTEMP 100
#define HV_GEWAYMAXCURRENT 100
#define HV_GEWAYMAXVOLTAGE  100
#define HV_GEWAYMINTEMP     10
#define HV_GEWAYMINCURRENT  10
#define HV_GEWAYMINVOLTAGE  10



float VBAT_BATGet(void);

float VBAT_V1Get(void);



#endif
