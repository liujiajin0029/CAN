#ifndef __PRECHARGEM_H
#define __PRECHARGEM_H

#include "hidef.h"
#include "derivative.h"

typedef enum
{
    PRECHARGEM_OK                  	 = 0,		/*正常*/
    PRECHARGEM_BUSY_OK             	 = 1,		/*正在运行*/
    PRECHARGEM_REQUEST_PENDING       = 2,		/*请求挂起*/
    PRECHARGEM_ALREADY_INITIALIZED	 = 3,		/*已初始化*/
} PrechargeM_ReturnType;

typedef struct _Fault
{
	Bool FaulData1;
	Bool FaulData2;
	Bool FaulData3;
}PrechargeM_FaultType;

Bool    PrechargeM_StartPre(void) ;
Bool    PrechargeM_StopPre(void);
Bool    PreChargeM_Change(void);
Bool   PrechargeM_IsFail(void);
 Bool PrechargeM_IsFinish(void);
Bool PreChargeM_StopMaster(void) ;


#endif
