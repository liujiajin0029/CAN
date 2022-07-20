#ifndef __PRECHARGEM_H
#define __PRECHARGEM_H

#include "hidef.h"
#include "derivative.h"

typedef struct _PrechargeM_DcDtat
{
	float vbat_data;
	float state_v1;
} PrechargeM_DcType;

typedef enum _PrechargeM_Return_E
{
    PRECHARGEM_OK                       = 1,		/*正常*/
    PRECHARGEM_NOTOK                    = 2 ,		/*正在运行*/
    PRECHARGEM_PENDING                  = 3,		/*请求挂起*/
    PRECHARGEM_INITIALIZED              = 4,		/*已初始化*/
} PrechargeM_Return_E;

typedef struct _PrechargeM_FaultType
{
    Bool FaulData1;
    Bool FaulData2;
    Bool FaulData3;
}PrechargeM_FaultType;

float  PrechargeM_BATGet(void);
float  PrechargeM_V1Get(void);
PrechargeM_Return_E PrechargeM_Diagnosis(void);
PrechargeM_Return_E PrechargeM_StartPre(void);
PrechargeM_Return_E PrechargeM_StopPre(void);
PrechargeM_Return_E PrechargeM_StopMaster(void);
PrechargeM_Return_E PrechargeM_IsFail(void);
PrechargeM_Return_E PrechargeM_Change(void);
PrechargeM_Return_E PrechargeM_IsFinish(void);
PrechargeM_Return_E PrechargeM_NoAct(void);

#endif
