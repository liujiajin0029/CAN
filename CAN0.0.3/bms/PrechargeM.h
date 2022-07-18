#ifndef __PRECHARGEM_H
#define __PRECHARGEM_H

#include "hidef.h"
#include "derivative.h"

typedef enum
{
    PRECHARGEM_OK                  	 = 0,		/*����*/
    PRECHARGEM_BUSY_OK             	 = 1,		/*��������*/
    PRECHARGEM_REQUEST_PENDING       = 2,		/*�������*/
    PRECHARGEM_ALREADY_INITIALIZED	 = 3,		/*�ѳ�ʼ��*/
} PrechargeM_ReturnType;

typedef struct _Fault
{
	Bool PrechargeM_FaultTypeData1;
	Bool PrechargeM_FaultTypeData2;
	Bool PrechargeM_FaultTypeData3;
}PrechargeM_FaultType;

int PrechargeM_IsFail(void);

#endif
