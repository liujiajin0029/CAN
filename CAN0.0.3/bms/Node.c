#include "Node.h"
#include "PrechargeM.h"

static int CurrentNode = 0;//µ±Ç°½Úµã 

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
	{//Node0 å¤æ­æé
		{ 0, Diagnosis, 2, 1, Node_NoAct, 0 },//æé ç»§ç»­å¤æ­æé
		{ 0, Diagnosis, 2, 0, PrechargeM_StartPre,1},//æ æé å¼å§é¢å è¿å¥é¢åå®æå¤æ­Node1
	},
	{//Node1 é¢åå®æå¤æ­
		{ 1, Diagnosis, 4, 1 , PrechargeM_StopPre, 0 },//æé æ­å¼é¢å è¿å¥Node0
		{ 1, PrechargeM_IsFail, 4, 1, PrechargeM_StopPre, 0 },//è¶æ¶ é¢ååæ­¢ è¿å¥ä¸ä¸èç¹Node0
		{ 1, PrechargeM_IsFinish, 4, 1, PreChargeM_Change, 2},//é¢åå®æï¼ æ­å¼é¢åï¼é­åæ»æ­£ è¿å¥ä¸ä¸èç¹Node2
		{ 1, PrechargeM_IsFinish, 4, 0, Node_NoAct,1 },//é¢åæªå®æ ç­å¾é¢åå®æ
	},
	{//Node2 æ¾çµæéå¤æ­
		{ 2, Diagnosis, 2, 1, PreChargeM_StopMaster, 0 },//æé æ­å¼æ»æ­£ è¿å¥Node0
		{ 2, Diagnosis, 2, 0, Node_NoAct, 2 },//åçµä¸­ ç»§ç»­åçµ
	}
};

    /*
void Node_Poll()
{
	int num = Lcfg[CurrentNode][0].N_num;//æ­¤èç¹çå¤æ­æ°é
         int i;
	for ( i = 0; i < num; i++)
	{
		if (Lcfg[CurrentNode][i].Condition() == Lcfg[CurrentNode][i].status)//å¤æ­
		{
			Lcfg[CurrentNode][i].Act();	//å¨ä½
			CurrentNode = Lcfg[CurrentNode][i].next_node;//ä¸ä¸èç¹
			break;
		}
	}
}      */
