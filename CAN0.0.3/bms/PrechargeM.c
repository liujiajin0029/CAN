#include "PrechargeM.h"
#include "Vbat.h"


void Pre_Init(void)
{

}


Bool Pre_StartPre(void)
{
    Bool retval;
     retval = 0;

    return retval;
}

Pre_ReturnType Pre_DeStargtPre()
{

    Pre_ReturnType  retval = PRECHARGEM_NOTOK;

    return retval;
}
Pre_ReturnType  Pre_StopPre(void)
{
    Pre_ReturnType  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;
}


Pre_ReturnType Pre_StartMaster(void)
{
    Pre_ReturnType  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;
}

Pre_ReturnType Pre_StopMaster(void)
{
    Pre_ReturnType  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;
}

Pre_ReturnType Pre_Change(void)
{
    Pre_ReturnType  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_OK;

    return retval;

}
Bool Pre_IsFinish(void)
{
    Bool retval;
    if(Pre_DeIsFinish(9,10,0.9) == PRECHARGEM_NOTOK)
    {
        retval = 1;
    }
    else
    {
        retval = 0;
    }
    return retval;
}

Pre_ReturnType Pre_DeIsFinish(float BAT,float v1,float multiple)
{
    Pre_ReturnType retval = PRECHARGEM_NOTOK;
    if (BAT > (v1 * multiple) )
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
Bool Pre_IsFail(void)
{
    Bool retval;
    if (Pre_DeIsFail(10,2000,5000) == PRECHARGEM_OK)
    {
        retval = PRECHARGEM_OK;
    }
    else
    {
        retval = PRECHARGEM_NOTOK;
    }
    return retval;
}
Pre_ReturnType Pre_DeIsFail(unsigned int StartTime,
                            unsigned int NowTime,
                            unsigned int SetTime)
{
    Pre_ReturnType  retval = PRECHARGEM_NOTOK;
    if (NowTime - StartTime > SetTime)
    {
        retval = PRECHARGEM_NOTOK;
    }
    retval = PRECHARGEM_OK;
    return retval;
}

/*诊断函数，主要用来故障判断*/
Pre_ReturnType Pre_Diagnosis(void)
{
    // PrechargeM_FaultType diagnosis2 ;
    Pre_ReturnType  retval = PRECHARGEM_NOTOK;
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


Pre_ReturnType Pre_NoAct(void)
{
     Pre_ReturnType  retval = PRECHARGEM_NOTOK;

    retval = PRECHARGEM_NOTOK;

    return retval;
}

