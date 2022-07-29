#ifndef __PRECHARGEM_H
#define __PRECHARGEM_H

#include "hidef.h"
#include "derivative.h"

typedef enum _PrechargeM_ReturnType
{
    PRECHARGEM_STATEOK          =1,
    PRECHARGEM_STATENOTOK       =2,
    PRECHARGEM_PENDING          =3,
    PRECHARGEM_INITIALIZED      =4,
}Pre_ReturnType;


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
Bool Pre_DeIsFail(uint32 StartTime,uint32 NowTime,uint32 SetTime);


#endif
