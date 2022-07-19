#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"
#include "PrechargeM.h"

typedef enum  _Node_NumType
{
    NODE_NUMBER0 = 0,
    NODE_NUMBER1 = 1,
    NODE_NUMBER2 = 2,
    NODE_NUMBER3 = 3,
}Node_NumType;

typedef struct _Node_MsgType
{
	int TypeNum;
	PrechargeM_ReturnType (*Condition)(void);
	int N_num;
	int Status;
	PrechargeM_ReturnType  (*Act)(void);
	Node_NumType Next;
}Node_MsgType;

extern Node_MsgType Lcfg[3][4];

#endif

