#include "derivative.h"
#include "Vbat.h"
#include "Hv_cfg.h"
#include "Hv_Lcfg.h"
#include "Hv_PBcfg.h"

void Hv_OpenPit()
{

}
void Hv_ClosePit()
{

}
uint8 Hv_GetVoltageFct(uint8 pas)
{
    pas = 1;
    return pas;
}
uint8 Hv_GetCurrentFct(uint8 pas)
{
    pas = 1;
    return pas;
}

uint8 Hv_GetTempFct(uint8 pas)
{
    pas = 1;
    return pas;
}



Bool Hv_DataManage(uint8 data ,uint8 MAX ,uint8 MIN)
{
    if (data > MIN && data < MAX)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
uint8 Hv_GetAlonMsg(HV_CfgPassType *cfg)
{
    uint8 retval;
    Hv_RetvalType data;
    data = Hv_GetVoltageData(cfg -> passageway);
    if (cfg ->geway == HV_GEWAY_VOLTAGE)
    {
        retval = data.Voltage;
    }
    else if (cfg ->geway == HV_GEWAY_CURRENT)
    {
        retval = data.Current;
    }
    else if (cfg ->geway == HV_GEWAY_TEMP)
    {
        retval = data.Temp;
    }
    else
    {

    }
    return retval;
}

Bool Hv_OpenPitCheck(Hv_RetvalType *cfg)
{
    uint8 sum = 0;
    Bool retval;
    if (Hv_DataManage(cfg->Temp,HV_GEWAY_MAX_TEMP,HV_GEWAY_MIN_TEMP) == TRUE)
    {
        retval = TRUE;
    }
    if (Hv_DataManage(cfg->Current,HV_GEWAY_MAX_CURRENT,HV_GEWAY_MIN_CURRENT) == TRUE)
    {
        retval = TRUE;
    }
    if (Hv_DataManage(cfg->Voltage,HV_GEWAY_MAX_VOLTAGE,HV_GEWAY_MIN_VOLTAGE) == TRUE)
    {
        retval = TRUE;
    }
    return retval;
}

Hv_RetvalType Hv_GetVoltageData(uint8 geway) //µçÑ¹
{
    Hv_RetvalType retval;
    uint8 i;
    for (i = 0; i < Hv_MAXPASSANUM; i++)
    {
        /*数组越界检查*/
        if (i < Hv_MAXPASSANUM)
        {
            if (geway == Hv_Data[i].passa)
            {
            /*¹ØÖÐ¶Ï*/
            Hv_ClosePit();
            retval.Voltage = Hv_Data[i].Voltage(geway);
            retval.Current = Hv_Data[i].Current(geway);
            retval.Temp = Hv_Data[i].Temp(geway);
            retval.passa = geway;
            /*¿ªÖÐ¶Ï*/
            Hv_OpenPit();
            break;
            }
        }
    }
    retval.power =  retval.Voltage *  retval.Current;
    if (Hv_OpenPitCheck(&retval) == TRUE)
    {

    }
    return retval;
}

