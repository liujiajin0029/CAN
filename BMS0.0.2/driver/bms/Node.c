#include "Node.h"
#include "Node_Cfg.h"
#include "CAN_CFG.h"
#include "Node_Msg.h"


Node_StateInfoType Node_cfg;


void Node_Poll(void)
{
    static uint8 nodestate  = 0;
    uint8 i = 0, sum = 0;

    Node_cfg.state = &(Node_StateCfg[Node_cfg.node]);
    sum = (uint8)(Node_cfg.state -> num);
    Node_CanSend(2, sum);
    for (i = 0; i < sum; i++)
    {
        Node_CanSend(0, Node_cfg.node);
        if (Node_cfg.state -> state[i].Condition()  == Node_cfg.state -> state[i].Status)
        {
            Node_cfg.state -> state[i].Act();
            Node_cfg.node = Node_cfg.state -> state[i].Next;
            Node_CanSend(1, Node_cfg.node);
            break;
        }
    }
}





