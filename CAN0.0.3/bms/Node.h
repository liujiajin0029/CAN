#ifndef __NODE_H
#define __NODE_H

#include "hidef.h"
#include "derivative.h"

typedef struct _Node_MsgType
{
	int TypeNum;	//节点号
	Bool (*Condition)(void);//条件
	int Number;	//条件数
	int Status;	//条件匹配
	void (*Act)(void);//动作
	int Next;//下个节点
}Node_MsgType;


extern Node_MsgType Lcfg[3][4];

#endif

