#include "RelayM.h"


void RelayM_Init(Hv_IOInit *_Hv_IOType) //    IO�ڳ�ʼ������
{

    _Hv_IOType->IO_dir = 1;

}

void  RelayM_Control(void)
{


}

int RelayM_Change(RelayM_Change_data *RelayM_data)  //    �����л�����
{
    if (RelayM_data->KEY_PRE == TRUE)
    {
		PORTC_PC4 = TRUE;
    }
    else
    {
		PORTC_PC4 = FALSE;
    }
    if (RelayM_data->KEY_RELAY == TRUE)
    {
		PORTC_PC4 = TRUE;
    }
    else
    {
		PORTC_PC4 = FALSE;
    }
    return FALSE;
}



