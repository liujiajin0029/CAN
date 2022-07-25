#include "PrechargeM.h"
#include "Vbat.h"


void PrechargeM_Init(void)
{

}

PrechargeM_ReturnType PrechargeM_StartPre(void)
{
    PrechargeM_DcType  Hw_Data;
    PrechargeM_ReturnType  retval = PRECHARGEM_NOTOK;

    Hw_Data.vbat_data  = VBAT_BATGet();

    Hw_Data.state_v1 = VBAT_V1Get();

    if ( Hw_Data.state_v1 > 10)
    {
        retval = PRECHARGEM_OK;
    }
    else
    {
        retval = PRECHARGEM_NOTOK;
    }
    /*测试使用*/
    retval = PRECHARGEM_OK;

    return retval;

}

PrechargeM_ReturnType  PrechargeM_StopPre(void)
{
    PrechargeM_ReturnType  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;
}


PrechargeM_ReturnType PrechargeM_StartMaster(void)
{
    PrechargeM_ReturnType  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;
}

PrechargeM_ReturnType PrechargeM_StopMaster(void)
{
    PrechargeM_ReturnType  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;
}

PrechargeM_ReturnType PrechargeM_Change(void)
{
    PrechargeM_ReturnType  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;

}

PrechargeM_ReturnType PrechargeM_IsFinish(void)
{
    PrechargeM_ReturnType  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;
}

PrechargeM_ReturnType PrechargeM_IsFail(void)
{
    PrechargeM_ReturnType  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;

}

/*诊断函数，主要用来故障判断*/
PrechargeM_ReturnType PrechargeM_Diagnosis(void)
{
    // PrechargeM_FaultType diagnosis2 ;
    PrechargeM_ReturnType  retval = PRECHARGEM_NOTOK;
/*    if (diagnosis2.FaulData1 == 1)
    {
        retval = PRECHARGEM_NOTOK;
    }
    if (diagnosis2.FaulData2 == 1)
    {
        retval = PRECHARGEM_OK;
    }              */
    retval = PRECHARGEM_OK;
    return  retval;
}


PrechargeM_ReturnType PrechargeM_NoAct(void)
{
     PrechargeM_ReturnType  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_NOTOK;

    return retval;
}