#include "derivative.h"
#include "Vbat.h"

float VBAT_BATGet(void)
{
    return 1;
}
float VBAT_V1Get(void)
{
    return 0;
}


typedef struct  _Hv_RetvalType
{
    uint32 Voltage;
    uint32 Current;
    uint32 Temp;
    uint32 passa;
    uint32 power;
}Hv_RetvalType;

typedef enum _HV_ATTRIBUTETYPE
{
    HV_GEWAYVOLTAGE,
    HV_GEWAYCURRENT,
    HV_GEWAYTEMP,
}HV_ATTRIBUTETYPE;


typedef struct _HV_CfgPass
{
    HV_ATTRIBUTETYPE geway;
    uint8 passageway;
}HV_CfgPass;


typedef struct _Hv_DemoDataType
{
    uint32 (*Voltage)(void);
    uint32 (*Current)(void);
    uint32 (*Temp)(void);
    uint8 passa;
}Hv_DemoDataType;

/*ÍêÕû£¬¾­¹ý´¦ÀíµÄÊý¾Ý*/
Hv_DemoDataType Hv_Data[Hv_MAXPASSANUM] =
{
    {0,0,0,0},
    {0,0,0,0},
};

Hv_RetvalType Hv_GetVoltage(uint8 geway);
Bool Hv_DataDeal(uint32 data ,uint32 MAX ,uint32 MIN);
uint8 HV_poll(HV_CfgPass *Hv_msg);
Bool Hv_OpenPitCheck(Hv_RetvalType retval);

void Hv_OpenPit()
{

}
void Hv_ClosePit()
{

}

Bool Hv_DataDeal(uint32 data ,uint32 MAX ,uint32 MIN)
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

uint8 Hv_VoltageData()
{

}

uint8 HV_poll(HV_CfgPass *Hv_msg)
{
    Hv_RetvalType retval;
    retval = Hv_GetVoltage(Hv_msg -> geway);
    if (Hv_msg ->passageway == HV_GEWAYVOLTAGE)
    {
        return retval.Voltage;
    }
    else if (Hv_msg ->passageway == HV_GEWAYCURRENT)
    {
        return retval.Current;
    }
    else if (Hv_msg ->passageway == HV_GEWAYTEMP)
    {
        return retval.Temp;
    }
    else
    {

    }
}

Bool Hv_OpenPitCheck(Hv_RetvalType retval)
{
    uint8 sum = 0;

    if(Hv_DataDeal(retval.Temp,HV_GEWAYMAXTEMP,HV_GEWAYMINTEMP) == TRUE)
    {
        sum ++;
    }
    if(Hv_DataDeal(retval.Current,HV_GEWAYMAXCURRENT,HV_GEWAYMINCURRENT) == TRUE)
    {
        sum ++;
    }
    if(Hv_DataDeal(retval.Voltage,HV_GEWAYMAXVOLTAGE,HV_GEWAYMINVOLTAGE) == TRUE)
    {
        sum ++;
    }
    if (sum >= 3)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Hv_RetvalType Hv_GetVoltage (uint8 geway) //µçÑ¹
{
    Hv_RetvalType retval;
    uint8 i,state;
    for (i = 0; i < Hv_MAXPASSANUM; i++)
    {
        /*数组越界检查*/
        if (i < Hv_MAXPASSANUM)
        {
        if (geway == Hv_Data[i].passa)
        {
        /*¹ØÖÐ¶Ï*/
        Hv_ClosePit();
        retval.Voltage = Hv_Data[i].Voltage();
        retval.Current = Hv_Data[i].Current();
        retval.Temp = Hv_Data[i].Temp();
        retval.passa = geway;
        /*¿ªÖÐ¶Ï*/
        Hv_OpenPit();
        break;
        }
        }
    }
    retval.power =  retval.Voltage *  retval.Current;
    if (Hv_OpenPitCheck(retval) == TRUE)
    {
        return retval;
    }
    else
    {

    }
}

