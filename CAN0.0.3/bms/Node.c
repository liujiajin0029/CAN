#include "Node.h"
#include "Node_Cfg.h"
#include "CAN_CFG.h"

Node_StateInfoType Node_cfg;

const Node_StateType Node_PreStateStart[] =
{
    {NODE_NUMBER0, Pre_Diagnosis, PRECHARGEM_NOTOK, Pre_NoAct, NODE_NUMBER0},
    {NODE_NUMBER0, Pre_Diagnosis, PRECHARGEM_OK, Pre_StartPre,NODE_NUMBER1},
};

const Node_StateType Node_PreStateCheck[] =
{
/*Node1 预充完成判断*/
    /*故障 断开预充 进入Node0*/
    { NODE_NUMBER1, Pre_Diagnosis, PRECHARGEM_OK , Pre_StopPre, NODE_NUMBER0},
    /*超时 预充停止 进入下一节点Node0*/
    { NODE_NUMBER1, Pre_IsFail, PRECHARGEM_OK, Pre_StopPre, NODE_NUMBER0},
    /*预充完成， 断开预充，闭合总正 进入下一节点Node2*/
    { NODE_NUMBER1, Pre_IsFinish, PRECHARGEM_OK, Pre_Change, NODE_NUMBER2},
    /*预充未完成 等待预充完成*/
    { NODE_NUMBER1, Pre_IsFinish, PRECHARGEM_NOTOK, Pre_NoAct,NODE_NUMBER1},
};

const Node_StateType Node_PreStateFinish[] =
{
    {NODE_NUMBER1, Pre_IsFinish, PRECHARGEM_NOTOK, Pre_NoAct, NODE_NUMBER1},
};

const Node_StateType Node_PreStateFault[] =
{
/*Node2 放电故障判断*/
    /*故障 断开总正 进入Node0*/
    { NODE_NUMBER2, Pre_Diagnosis, PRECHARGEM_OK, Pre_StopMaster, NODE_NUMBER0},
    /*充电中 继续充电*/
    { NODE_NUMBER2, Pre_Diagnosis, PRECHARGEM_NOTOK, Pre_NoAct, NODE_NUMBER2},
};

const Node_StateCfgType Node_StateCfg[] =
{
    {2, Node_PreStateStart},
    {4, Node_PreStateCheck},
    {1, Node_PreStateFinish},
    {2, Node_PreStateFault},
};


void Node_CanSend(uint8_t node_num ,uint8_t data)
{
    Can_NodeSend(node_num,data);
}

void Node_Poll(void)
{
    uint8_t i = 0 , sum = 0;
    Node_cfg.node = NODE_NUMBER0;

    *(Node_cfg.state)= (Node_StateCfg[NODE_NUMBER0]);
    sum = (uint8_t)(Node_cfg.state -> num);
    for (i = 0;i <sum ;i++ )
    {
        Node_CanSend(0, Node_cfg.node);
        if (Node_cfg.state->state[i].Condition()  ==
            Node_cfg.state->state[i].Status)
        {
            Node_cfg.state->state[i].Act();
            Node_cfg.node = Node_cfg.state->state[i].Next;
            Node_CanSend(1, Node_cfg.node);
            break;
        }
    }
}





