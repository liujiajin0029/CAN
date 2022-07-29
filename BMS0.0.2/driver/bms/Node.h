#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"
#include "PrechargeM.h"

#define   NODE_NUMBER0   (0U)
#define   NODE_NUMBER1   (1U)
#define   NODE_NUMBER2   (2U)
#define   NODE_NUMBER3   (3U)

typedef struct _Node_StateType
{
    unsigned int TypeNum;
    Pre_ReturnType (*Condition)(void);
    Pre_ReturnType Status;
    void (*Act)(void);
    uint8 Next;
}Node_StateType;

typedef struct _NodeStateCfgType
{
    uint16 num;
    const Node_StateType *state;
}Node_StateCfgType;

typedef struct _NodeStateInfoType
{
    uint8 node;
    const Node_StateCfgType *state;
}Node_StateInfoType;

void Node_Poll(void);
#endif

