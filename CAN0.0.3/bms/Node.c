#include "Node.h"
#include "CAN.h"
#include "CAN_CFG.h"


Node_MsgType  Lcfg[3][4] =
{
	/*Node0 判断故障*/
	{
		/*故障 继续判断故障*/
		{ NODE_NUMBER0, PrechargeM_Diagnosis, 2, PRECHARGEM_OK, PrechargeM_NoAct, NODE_NUMBER0 },
		/*无故障 开始预充 进入预充完成判断Node1*/
		{ NODE_NUMBER0, PrechargeM_Diagnosis, 2, PRECHARGEM_NOTOK, PrechargeM_StartPre,NODE_NUMBER1},
	},
	/*Node1 预充完成判断*/
	{
		/*故障 断开预充 进入Node0*/
		{ NODE_NUMBER1, PrechargeM_Diagnosis, 4, PRECHARGEM_OK , PrechargeM_StopPre, NODE_NUMBER0 },
		/*超时 预充停止 进入下一节点Node0*/
		{ NODE_NUMBER1, PrechargeM_IsFail, 4, PRECHARGEM_OK, PrechargeM_StopPre, NODE_NUMBER0 },
		/*预充完成， 断开预充，闭合总正 进入下一节点Node2*/
		{ NODE_NUMBER1, PrechargeM_IsFinish, 4, PRECHARGEM_OK, PrechargeM_Change, NODE_NUMBER2},
		/*预充未完成 等待预充完成*/
		{ NODE_NUMBER1, PrechargeM_IsFinish, 4, PRECHARGEM_NOTOK, PrechargeM_NoAct,NODE_NUMBER1 },
	},
	/*Node2 放电故障判断*/
	{
		/*故障 断开总正 进入Node0*/
		{ NODE_NUMBER2, PrechargeM_Diagnosis, 2, PRECHARGEM_OK, PrechargeM_StopMaster, NODE_NUMBER0 },
		/*充电中 继续充电*/
		{ NODE_NUMBER2, PrechargeM_Diagnosis, 2, PRECHARGEM_NOTOK, PrechargeM_NoAct, NODE_NUMBER2 },
	},
};

void Node_Poll(void)
{
    static int Node_Current = 0;

    unsigned int i = 0,num = 0;

    while (Lcfg[Node_Current][num].TypeNum == Lcfg[Node_Current][0].TypeNum)
	{
		num ++;
	}
        if(Node_Current > 3)
        {
            Node_Current  = 0;
        }
	for ( i = 0; i < num; i++)
	{
		if (Lcfg[Node_Current][i].Condition() == Lcfg[Node_Current][i].Status)
		{
			if (Lcfg[Node_Current][i].Act() == 1)
			{

			}
			Node_Current = Lcfg[Node_Current][i].Next;
			break;
		}
	}
}




