#ifndef __PRECHARGEM_H
#define __PRECHARGEM_H

#include "hidef.h"
#include "derivative.h"

typedef struct _PrechargeM_DcDtat
{
	float vbat_data;
	float state_v1;
} PrechargeM_DcType;

typedef enum
{
    PRECHARGEM_OK            = 1,		/*正常*/
    PRECHARGEM_NOTOK         = 2 ,		/*正在运行*/
    PRECHARGEM_PENDING       = 3,		/*请求挂起*/
    PRECHARGEM_INITIALIZED	 = 4,		/*已初始化*/
} PrechargeM_ReturnType;

typedef struct _PrechargeM_FaultType
{
    Bool FaulData1;
	Bool FaulData2;
	Bool FaulData3;
}PrechargeM_FaultType;


PrechargeM_ReturnType PrechargeM_Diagnosis(void);
PrechargeM_ReturnType PrechargeM_StartPre(void);
PrechargeM_ReturnType PrechargeM_StopPre(void);
PrechargeM_ReturnType PrechargeM_StopMaster(void);
PrechargeM_ReturnType PrechargeM_IsFail(void);
PrechargeM_ReturnType PrechargeM_Change(void);
PrechargeM_ReturnType PrechargeM_IsFinish(void);
PrechargeM_ReturnType PrechargeM_NoAct(void);

#endif
