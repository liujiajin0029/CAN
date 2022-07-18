#include "Node.h"
#include "PrechargeM.h"

static int CurrentNode = 0;//��ǰ�ڵ� 

Bool Diagnosis()
{
	return FALSE;
}

Bool  Node_NoAct()
{
	 return 1;
}
void Node_Init()
{
	;
}

Node_MsgType Lcfg[3][4] =
{
	{//Node0 判断故障
		{ 0, Diagnosis, 2, 1, Node_NoAct, 0 },//故障 继续判断故障
		{ 0, Diagnosis, 2, 0, PrechargeM_StartPre,1},//无故障 开始预充 进入预充完成判断Node1
	},
	{//Node1 预充完成判断
		{ 1, Diagnosis, 4, 1 , PrechargeM_StopPre, 0 },//故障 断开预充 进入Node0
		{ 1, PrechargeM_IsFail, 4, 1, PrechargeM_StopPre, 0 },//超时 预充停止 进入下一节点Node0
		{ 1, PrechargeM_IsFinish, 4, 1, PreChargeM_Change, 2},//预充完成， 断开预充，闭合总正 进入下一节点Node2
		{ 1, PrechargeM_IsFinish, 4, 0, Node_NoAct,1 },//预充未完成 等待预充完成
	},
	{//Node2 放电故障判断
		{ 2, Diagnosis, 2, 1, PreChargeM_StopMaster, 0 },//故障 断开总正 进入Node0
		{ 2, Diagnosis, 2, 0, Node_NoAct, 2 },//充电中 继续充电
	}
};

    /*
void Node_Poll()
{
	int num = Lcfg[CurrentNode][0].N_num;//此节点的判断数量
         int i;
	for ( i = 0; i < num; i++)
	{
		if (Lcfg[CurrentNode][i].Condition() == Lcfg[CurrentNode][i].status)//判断
		{
			Lcfg[CurrentNode][i].Act();	//动作
			CurrentNode = Lcfg[CurrentNode][i].next_node;//下一节点
			break;
		}
	}
}      */
