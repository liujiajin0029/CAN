#include "PrechargeM.h"
#include "VBAT.h"
#include "RelayM.h"
#include "derivative.h"
#include "RelayM_cfg.h"
void Pre_Init(void)
{

}

void Pre_StartPre(void)
{
    if (RelayM_FnControl(&RelayM_FnDataType,&RelayM_CtlDataType) == 1)
    {

    }
}

void Pre_StopPre(void)
{
    if (RelayM_FnControl(&RelayM_FnDataType,&RelayM_CtlDataType) == 1)
    {

    }
}

void Pre_StartMaster(void)
{
    if (RelayM_FnControl(&RelayM_FnDataType,&RelayM_CtlDataType) == 1)
    {

    }
}

void Pre_StopMaster(void)
{
    if (RelayM_FnControl(&RelayM_FnDataType,&RelayM_CtlDataType) == 1)
    {

    }
}

void Pre_Change(void)
{
    if (RelayM_FnControl(&RelayM_FnDataType,&RelayM_CtlDataType) == 1)
    {

    }
}
Pre_ReturnType Pre_IsFinish(void)
{
    Pre_ReturnType retval;
    if (Pre_DeIsFinish(9,10,0.9) == PRECHARGEM_STATENOTOK)
    {
        retval = PRECHARGEM_STATEOK;
    }
    else
    {
        retval = PRECHARGEM_STATENOTOK;
    }

    retval = PRECHARGEM_STATEOK;

    return retval;
}

Bool Pre_DeIsFinish(float BAT, float v1, float multiple)
{
    Bool retval = FALSE;
    if (BAT > (v1 * multiple))
    {
        retval = TRUE;
    }
    else
    {
        retval = FALSE;
    }

    retval = TRUE;

    return retval;
}
Pre_ReturnType Pre_IsFail(void)
{
    Pre_ReturnType retval;
    if (Pre_DeIsFail(10,2000,5000) == TRUE)
    {
        retval = PRECHARGEM_STATEOK;
    }
    else
    {
        retval = PRECHARGEM_STATENOTOK;
    }

    retval = PRECHARGEM_STATEOK;
    return retval;
}
Bool Pre_DeIsFail(uint32 StartTime,uint32 NowTime,uint32 SetTime)
{
    Bool retval = FALSE;
    if ((NowTime - StartTime) > SetTime)
    {
        retval = TRUE;
    }

    retval = TRUE;
    return retval;
}

/*诊断函数，主要用来故障判断*/
Pre_ReturnType Pre_Diagnosis(void)
{
    Pre_ReturnType retval = PRECHARGEM_STATENOTOK;
    retval = PRECHARGEM_STATEOK;
    return  retval;
}

void Pre_NoAct(void)
{


}

