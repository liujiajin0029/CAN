#ifndef __RELAYM_H
#define __RELAYM_H

#include "hidef.h"
#include "derivative.h"
#include "VBAT.h"



typedef enum _Relaym_SateMsgType
{
    RELAYM_ACTURE_STATE,
    RELAYM_CONTROL_STATE,
    RELAYM_ON_TIME_STATE,
    RELAYM_OFF_TIME_STATE,
    RELAYM_RES_STATE,
    RELAYM_ON_CLOSE_RELAY,/*闭合继电器*/
    RELAYM_OFF_CLOSE_RELAY,/*断开继电器*/
} Relaym_SateMsgType;


typedef enum _RELAYM_STATERETVAL
{
    RELAYM_STATE_RETVAL_ON,
    RELAYM_STATE_RETVAL_OFF,
}Relaym_RetvalType;


typedef enum _RELAYM_ChannelType
{
    RELAYM_CHANNEL_0,
    RELAYM_CHANNEL_1,
    RELAYM_CHANNEL_2,
    RELAYM_CHANNEL_3,
    RELAYM_CHANNEL_4,
    RELAYM_CHANNEL_5,
    RELAYM_CHANNEL_6,
    RELAYM_CHANNEL_7,
    RELAYM_CHANNEL_8,
}RELAYM_ChannelType;

typedef enum RELAYM_HaveAttribute
{
    RELAYM_HAVE_CTL,
    RELAYM_NOT_HAVE_CTL,
    RELAYM_HAVE_RES,
    RELAYM_NOT_HAVE_RES,
    RELAYM_HAVE_ONTIME,
    RELAYM_NOT_HAVE_ONTIME,
    RELAYM_HAVE_OFFTIME,
    RELAYM_NOT_HAVE_OFFTIME,
}RelayM_HaveAttType;


typedef struct _RelayM_ControlType
{
    RelayM_HaveAttType Ctl;      /*继电器是否拥有控制属性*/
    RelayM_HaveAttType OnTime;   /*继电器是否拥有开时间属性*/
    RelayM_HaveAttType OffTime;  /*继电器是否拥有关闭时间属性*/
    RelayM_HaveAttType Res;      /*继电器是否拥有阻值属性*/
    RELAYM_ChannelType passage;
}RelayM_FnType;


typedef struct _RelayM_ControLCfgType
{
    uint8 Ctl;       /*继电器控制参数*/
    uint8 OnTime;    /*继电器开时间参数*/
    uint8 OffTime;   /*继电器关闭时间参数*/
    uint8 Res;       /*继电器阻值参数*/
    uint8 passage;
}RelayM_CtlCallType;


typedef struct _RelayM_ActureType
{
    uint8 (*Act)(uint8 pas);            /*读取继电器实际参数*/
    uint8 (*Ctl)(uint8 pas);            /*读取继电器控制参数*/
    uint8 (*OnTime)(uint8 pas);         /*读取继电器开时间参数*/
    uint8 (*OffTime)(uint8 pas);        /*读取继电器关闭时间参数*/
    uint8 (*Res)(uint8 pas);            /*读取继电器阻值参数*/
    uint8  passage;
}RelayM_ActInfoType;


typedef struct _RelayM_CtlType
{
    uint8 (*Ctl)(RelayM_CtlCallType *cfg);           /*输入继电器控制参数*/
    uint8 (*OnTime)(RelayM_CtlCallType *cfg);        /*输入继电器开时间参数*/
    uint8 (*OffTime)(RelayM_CtlCallType *cfg);       /*输入继电器关闭时间参数*/
    uint8 (*Res)(RelayM_CtlCallType *cfg);           /*输入继电器阻值参数*/
    uint8    passage;
}RelayM_CtlInfoType;


typedef struct _RelayM_MsgCfgType
{
    uint8    passage;
    RelayM_ActInfoType *get;
    RelayM_CtlInfoType *ctl;
}RelayM_MsgCfgType;

typedef struct _RelayM_CtlCfgType
{
    uint8    passage;
    RelayM_CtlInfoType *ctl;
}RelayM_CtlCxtType;


typedef struct _RelayM_ActCfgType
{
    uint8    passage;
    RelayM_ActInfoType *get;
}RelayM_ActCxtType;

typedef struct _RelayM_ActureCallType
{
    uint8 Act;
    uint8 Ctl;
    uint8 OnTime;
    uint8 OffTime;
    uint8 Res;
    uint8 passage;
}RelayM_ActCallType;


uint8   RelayM_StateCtlWrite(RelayM_CtlCallType *cfg);
uint8   RelayM_OnTimeCtlWrite(RelayM_CtlCallType *cfg);
uint8   RelayM_OffTimeCtlWrite(RelayM_CtlCallType *cfg);
uint8   RelayM_ResCtlWrite(RelayM_CtlCallType *cfg);

uint8   RelayM_GetControL(uint8 pas);
uint8   RelayM_GetOnTime(uint8 pas);
uint8   RelayM_GetOffTime(uint8 pas);
uint8   RelayM_GetResTime(uint8 pas);
uint8   RelayM_GetActstate(uint8 pas);

RelayM_ActCallType RelayM_ReadAllData(uint8 pas, RelayM_ActInfoType *cfg);
uint8 RelayM_ReadAloneData(uint8 pas ,Relaym_SateMsgType state);
Relaym_RetvalType RelayM_FnControl(RelayM_FnType *fn, RelayM_CtlCallType *ctl);


#endif
