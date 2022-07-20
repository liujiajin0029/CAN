#ifndef __NODE_CFG_H
#define __NODE_CFG_H


typedef struct _Node_MsgType
{
	unsigned char TypeNum;
	PrechargeM_Return_E (*Condition)(void);
	PrechargeM_Return_E Status;
	PrechargeM_Return_E (*Act)(void);
	unsigned char Next;
}Node_MsgType;


extern Node_MsgType Node_MsgData[3][4];


#endif

