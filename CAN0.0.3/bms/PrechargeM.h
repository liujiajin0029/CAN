#ifndef __PRECHARGEM_H
#define __PRECHARGEM_H

#include "hidef.h"
#include "derivative.h"

typedef struct _PrechargeM_DcDtat
{
	float vbat_data;
	float state_v1;
} PrechargeM_DcType;

typedef enum _PrechargeM_ReturnType
{
    PRECHARGEM_OK               =1,
    PRECHARGEM_NOTOK            =2,
    PRECHARGEM_PENDING          =3,
    PRECHARGEM_INITIALIZED      =4,
} Pre_ReturnType;

typedef struct _PrechargeM_FaultType
{
    Bool FaulData1;
    Bool FaulData2;
    Bool FaulData3;
}PrechargeM_FaultType;


Pre_ReturnType Pre_Diagnosis(void);
void Pre_StartPre(void);
void Pre_StartMaster(void);
void Pre_StopPre(void);
void Pre_StopMaster(void);
Pre_ReturnType Pre_IsFinish(void);
void Pre_Change(void);
Pre_ReturnType Pre_IsFail(void);
void Pre_NoAct(void);
Bool Pre_DeIsFinish(float BAT,float v1,float multiple);
Bool Pre_DeIsFail(uint32_t StartTime,uint32_t NowTime,uint32_t SetTime);


#endif
