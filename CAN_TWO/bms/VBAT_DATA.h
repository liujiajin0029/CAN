#ifndef __VBAT_DATA_H
#define __VBAT_DATA_H
#include "hidef.h"
#include "derivative.h"


#define VBAT_SUM  10

/*BMS_Ԥ���_��ѹ_��ֵ_��*/
#define VOLTAGE_THRESHOLD_H  20

/*BMS_Ԥ���_��ѹ_��ֵ_��*/
#define VOLTAGE_THRESHOLD_L  10

 
typedef struct _HV_DATA
{
	int BAT;		//BAT��׼��ѹ
	int current;		//V1��ѹ
}HV_DATA;
 


 
 
int BAT_Get(void);
int V1_Get(void);

#endif
