#include "Node.h"
#include "Node_Cfg.h"
#include "CAN_CFG.h"
#include "Node_Msg.h"

void Node_CanSend(uint8_t node_num ,uint8_t data)
{
    Can_NodeSend(node_num,data);
}
