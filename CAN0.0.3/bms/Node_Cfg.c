#include "Node.h"
#include "CAN.h"
#include "Node_Cfg.h"

Node_MsgType  Node_MsgData[] =
{
/*Node0 判断故障*/
	/*故障 继续判断故障*/
	{ NODE_NUMBER0, PrechargeM_Diagnosis, PRECHARGEM_NOTOK, PrechargeM_NoAct, NODE_NUMBER0},
	/*无故障 开始预充 进入预充完成判断Node1*/
	{ NODE_NUMBER0, PrechargeM_Diagnosis, PRECHARGEM_OK, PrechargeM_StartPre,NODE_NUMBER1},
/*Node1 预充完成判断*/
	/*故障 断开预充 进入Node0*/
	{ NODE_NUMBER1, PrechargeM_Diagnosis, PRECHARGEM_OK , PrechargeM_StopPre, NODE_NUMBER0},
	/*超时 预充停止 进入下一节点Node0*/
	{ NODE_NUMBER1, PrechargeM_IsFail, PRECHARGEM_OK, PrechargeM_StopPre, NODE_NUMBER0},
	/*预充完成， 断开预充，闭合总正 进入下一节点Node2*/
	{ NODE_NUMBER1, PrechargeM_IsFinish, PRECHARGEM_OK, PrechargeM_Change, NODE_NUMBER2},
	/*预充未完成 等待预充完成*/
	{ NODE_NUMBER1, PrechargeM_IsFinish, PRECHARGEM_NOTOK, PrechargeM_NoAct,NODE_NUMBER1},
/*Node2 放电故障判断*/
	/*故障 断开总正 进入Node0*/
	{ NODE_NUMBER2, PrechargeM_Diagnosis, PRECHARGEM_OK, PrechargeM_StopMaster, NODE_NUMBER0},
	/*充电中 继续充电*/
	{ NODE_NUMBER2, PrechargeM_Diagnosis, PRECHARGEM_NOTOK, PrechargeM_NoAct, NODE_NUMBER2},
};

const unsigned char Node_cfg_length = sizeof(Node_MsgData) / sizeof(Node_MsgData[0]);
