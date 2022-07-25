#include "Node.h"
#include "CAN.h"
#include "CAN_CFG.h"
#include "Node_Cfg.h"

void Node_Poll(void)
{
    static int Node_Current = NODE_NUMBER0;

    unsigned int i = 0;

    unsigned int num = Node_cfg_length;

	Can_MsgSendType1.Id = num;

	for ( i = 0; i < 8; i++)
	{
        Can_MsgSendType1.Data[1] = (unsigned char) i;
		if (Node_MsgData[i].TypeNum == Node_Current)
		{
    		Can_MsgSendType1.Data[0] = (unsigned char) Node_Current;
    		if (Node_MsgData[i].Act() == Node_MsgData[i].Status)
    		{
                Node_Current = (Node_MsgData[i].Next - 1);
    		}
    		else
    		{

    		}
		}
	}
	if (Can_SendMsg(&Can_MsgSendType1) == 1)
	{

	}
}




