#include "Node.h"
#include "CAN.h"
#include "CAN_CFG.h"
#include "Node_Cfg.h"

void Node_Poll(void)
{
    static int Node_Current = 0;

    unsigned int i = 0,num = 0;

    while (Node_MsgData[Node_Current][num].TypeNum == Node_MsgData[Node_Current][0].TypeNum)
	{
		num ++;
	}
	Can_MsgSendType1.Id = num;
    if (Can_SendMsg(&Can_MsgSendType1) == 1)
	{

	}
	for ( i = 0; i < num; i++)
	{
		if (Node_MsgData[Node_Current][i].Condition() == Node_MsgData[Node_Current][i].Status)
		{
			if (Node_MsgData[Node_Current][i].Act() == 1)
			{

			}
			Node_Current = (Node_MsgData[Node_Current][i].Next - 1);
			break;
		}
	}
}




