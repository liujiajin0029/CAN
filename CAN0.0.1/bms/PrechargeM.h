#ifndef __PRECHARGEM_H
#define __PRECHARGEM_H

#include "hidef.h"
#include "derivative.h"

typedef struct PrechargeM_Ok
{
	float vbat_mV;
	float v1_mV;
	int state_vbat;
	int state_v1;
}hw_tab;

/* Status parameters*/
typedef enum
{
    PrechargeM_Ok                  	 = 0,		/*����*/
    PrechargeM_Busy_Ok             	 = 1,		/*��������*/
    PrechargeM_Request_Pending       = 2,		/*�������*/
    PrechargeM_Already_Initialized	 = 3,		/*�ѳ�ʼ��*/
} PrechargeM_RETURN_TYPE;

typedef struct _Fault
{
	Bool FaultDATA1;
	Bool FaultDATA2;
	Bool FaultDATA3;
}Fault;

int PrechargeM_IsFail(void);

#endif
