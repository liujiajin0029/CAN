#include "RelayM.h"


void RelayM_Init(RelayM_IoChgType *IOType) //    IO�ڳ�ʼ������
{
    IOType->KEY_PRE = 1;
}

void  RelayM_Control(void)
{


}

int RelayM_Change(RelayM_IoChgType *IoChg)  //    �����л�����
{
    if (IoChg->KEY_PRE == TRUE)
    {
		PORTC_PC4 = TRUE;
    }
    else
    {
		PORTC_PC4 = FALSE;
    }
    if (IoChg->KEY_RELAY == TRUE)
    {
		PORTC_PC4 = TRUE;
    }
    else
    {
		PORTC_PC4 = FALSE;
    }
    return FALSE;
}



