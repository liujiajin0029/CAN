#include "derivative.h"
#include "CAN.h"
#include "CAN_CFG.h"
#include "CAN_Msg.h"
#include "Node.h"

/*报文周期发送函数*/
void Can_SendTime(Can_TimeType TimeCfgType)
{
    static int Can_Time ;

    Can_Time++;

    if (Can_Time == TimeCfgType.Can_Time1)
    {
      /*  if (Can_SendMsg(&Can_MsgNodeType) == 1)
        {

        }  */
    }

    if (Can_Time == TimeCfgType.Can_Time2)
    {
      /*  if (Can_SendMsg(&Can_MsgSendType2) == 1)
        {

        }     */
    }
    if (Can_Time >= TimeCfgType.Can_Time4)
    {
        Can_Time = 0;
        Can_NodePollCallBcak();
        if (Can_SendMsg(&Can_MsgNodeType) == 1)
        {

        }
    }

}

/*发送所有函数*/
void Can_SendMsgAll(void)
{
    Can_SendTime(Can_TimeSendType);
}

/*接收报文数据处理函数*/
Bool Can_GetCallBack(void)
{
    if (Can_GetMsg(&Can_MsgGetType) == TRUE)
    {
        /*接收信息*/
        if (Can_MsgGetType.Id == 0x3c && (!Can_MsgGetType.Ide))
        {
            if (Can_SendMsg(&Can_MsgNodeType) == 1)
            {

            }
        }
    }
    return 0;
}

void Can_NodeSend(uint8 Tag_num, uint8 data)
{
    Can_MsgNodeType.Data[Tag_num] = data;
}

void Can_NodePollCallBcak(void)
{
    Node_Poll();
}