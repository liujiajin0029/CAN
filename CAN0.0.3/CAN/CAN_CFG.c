#include "derivative.h"
#include "CAN_CFG.h"

Can_MsgType Can_MsgSendType1 =
{
    0x00000001,
    0,
    {1, 0, 0, 0, 0, 0, 0, 0},
    8,
    0,
    CAN_PASSAGEWAY1,
};

 Can_MsgType Can_MsgSendType2 =
{
    0x000000002,
    0,
    {2, 0, 0, 0, 0, 0, 0, 0},
    8,
    0,
    CAN_PASSAGEWAY1,
};

Can_MsgType Can_MsgSendType3 =
{
    0x000000003,
    0,
    {3, 0, 0, 0, 0, 0, 0, 0},
    8,
    0,
    CAN_PASSAGEWAY1,
};

Can_TimeType Can_TimeSendType =
{
    40,
    50,
    60,
    100,
};


Can_MsgType Can_MsgGetType =
{
    0x00,
    0,
    {0, 0, 0, 0, 0, 0, 0, 0},
    0,
    0,
};

Can_MsgType Can_MsgNodeType =
{
    0x000000003,
    0,
    {0,0, 0, 0, 0, 0, 0, 0},
    8,
    0,
    CAN_PASSAGEWAY1,
};


void Can_NodeSend(uint8_t Tag_num, uint8_t data)
{
    Can_MsgNodeType.Data[Tag_num] = data;
}
