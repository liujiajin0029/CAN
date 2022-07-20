#include "PrechargeM.h"


float PrechargeM_BATGet(void)
{
    return 1;
}

float PrechargeM_V1Get(void)
{
    return 0;
}


void PrechargeM_Init(void)
{

}

PrechargeM_Return_E PrechargeM_StartPre(void)
{
    PrechargeM_DcType  Hw_Data;
    PrechargeM_Return_E  retval = PRECHARGEM_NOTOK;

    Hw_Data.vbat_data  = PrechargeM_BATGet();

    Hw_Data.state_v1 = PrechargeM_V1Get();

    if (Hw_Data.state_v1 > 10)
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

PrechargeM_Return_E PrechargeM_StopPre(void)
{
    PrechargeM_Return_E  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;
}


PrechargeM_Return_E PrechargeM_StartMaster(void)
{
    PrechargeM_Return_E  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;
}

PrechargeM_Return_E PrechargeM_StopMaster(void)
{
    PrechargeM_Return_E  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;
}

PrechargeM_Return_E PrechargeM_Change(void)
{
    PrechargeM_Return_E  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;

}

PrechargeM_Return_E PrechargeM_IsFinish(void)
{
    PrechargeM_Return_E  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;
}

PrechargeM_Return_E PrechargeM_IsFail(void)
{
    PrechargeM_Return_E  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;

}

/*诊断函数，主要用来故障判断*/
PrechargeM_Return_E PrechargeM_Diagnosis(void)
{
    // PrechargeM_FaultType diagnosis2 ;
    PrechargeM_Return_E  retval = PRECHARGEM_NOTOK;
/*    if (diagnosis2.FaulData1 == 1)
    {
        retval = PRECHARGEM_NOTOK;
    }
    if (diagnosis2.FaulData2 == 1)
    {
        retval = PRECHARGEM_OK;
    }  */
    retval = PRECHARGEM_OK;
    return  retval;
}


PrechargeM_Return_E PrechargeM_NoAct(void)
{
     PrechargeM_Return_E  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_NOTOK;

    return retval;
}