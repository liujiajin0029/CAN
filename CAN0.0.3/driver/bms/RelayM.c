#include "RelayM.h"
   
void RelayM_Change(unsigned char  Switch)            //    ¿ª¹ØÇÐ»»º¯Êý
{
    if (Switch ==  RELAYM_PRESWITCHON)
    {
        RelayM_Control(RELAYM_PRE_IOON,1);
    }
    else if (Switch ==  RELAYM_PRESWITCHOFF)
    {
        RelayM_Control(RELAYM_PRE_IOOFF,0);
    }
    else if (Switch == RELAYM_CLOSEDTOTALON)
    {
        RelayM_Control(RELAYM_PRE_IOOFF,0);
        RelayM_Control(RELAYM_CLOSEDTOTALIO,1);
    }

}

void RelayM_Control(unsigned char Pre_switch,unsigned char  state)
{
   if (RELAYM_PRE_IOON == Pre_switch)
   {
     
   }
}


