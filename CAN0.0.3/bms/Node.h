#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"
#include "PrechargeM.h"

#define   NODE_NUMBER0   (1U)
#define   NODE_NUMBER1   (2U)
#define   NODE_NUMBER2   (3U)
#define   NODE_NUMBER3   (4U)

typedef struct _Node_MsgType
{
	unsigned int TypeNum;
	PrechargeM_ReturnType (*Condition)(void);
	PrechargeM_ReturnType Status;
	PrechargeM_ReturnType (*Act)(void);
	unsigned int Next;
}Node_MsgType;

extern Node_MsgType  Node_MsgData[] ;

//void Node_Poll(Node_MsgType *Node_Data[3][4]);
 void Node_Poll(void);
#endif

