#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"
#include "PrechargeM.h"

#define   NODE_NUMBER0   (1U)
#define   NODE_NUMBER1   (2U)
#define   NODE_NUMBER2   (3U)
#define   NODE_NUMBER3   (4U)

typedef struct _Node_StateType
{
	unsigned int TypeNum;
	Pre_ReturnType (*Condition)(void);
	Pre_ReturnType Status;
	Pre_ReturnType (*Act)(void);
	unsigned int Next;
}Node_StateType;

typedef struct  _NodeStateCfgType
{
  unsigned char num;
  Node_StateType *state;
} Node_StateCfgType;

typedef struct _NodeStateInfoType
{
  unsigned char  node;
  Node_StateCfgType *state;
} Node_StateInfoType;


#endif

