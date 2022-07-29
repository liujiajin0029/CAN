#include "Node.h"
#include "Node_Cfg.h"
#include "CAN_CFG.h"
#include "Node_Msg.h"
#include "CAN_Msg.h"


void Node_CanSend(uint8 node_num,uint8 data)
{
   Can_NodeSend(node_num,data);
}
