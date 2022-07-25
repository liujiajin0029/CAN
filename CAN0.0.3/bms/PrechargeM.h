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
    PRECHARGEM_OK                    =1,		/*正常*/
    PRECHARGEM_NOTOK             =2,		/*正在运行*/
    PRECHARGEM_PENDING          =3  ,		/*请求挂起*/
    PRECHARGEM_INITIALIZED      =4	 ,		/*已初始化*/
} Pre_ReturnType;

typedef struct _PrechargeM_FaultType
{
    Bool FaulData1;
	Bool FaulData2;
	Bool FaulData3;
}PrechargeM_FaultType;


Pre_ReturnType Pre_Diagnosis(void);
Bool Pre_StartPre(void);
Pre_ReturnType Pre_StopPre(void);
Pre_ReturnType Pre_StopMaster(void);
Bool Pre_IsFinish(void);
Pre_ReturnType Pre_Change(void);
Bool Pre_IsFail(void);
Pre_ReturnType Pre_NoAct(void);
Pre_ReturnType Pre_DeIsFinish(float BAT,float v1,float multiple);
 Pre_ReturnType Pre_DeIsFail(unsigned int StartTime,unsigned int NowTime,unsigned int SetTime);
#endif
