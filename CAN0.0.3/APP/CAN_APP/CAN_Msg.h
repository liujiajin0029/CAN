#ifndef __CAN_MSG_H
#define __CAN_MSG_H


void Can_SendTime(Can_TimeType Can_TimeTypeCfg);
void Can_SendMsgAll(void);
Bool Can_GetCallBack(void);
void Can_NodePollCallBcak(void);
void Can_NodeSend(uint8_t Tag_num, uint8_t data);

#endif