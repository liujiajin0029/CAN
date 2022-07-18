#ifndef __CAN_H
#define __CAN_H

#include "hidef.h"
#include "derivative.h"

#define   	CAN_MSGTYPE_DATA_MAXLEN   8

#define 	CAN_PASSAGEWAY1  (0x40u)

#define		CAN_PASSAGEWAY0  (0u)

#define		CAN_CTL0_ADDRESS(address)		(*(&CAN0CTL0 + address))

#define		CAN_CTL1_ADDRESS(address)		(*(&CAN0CTL1 + address))

#define		CAN_RXDSR0_ADDRESS(address)		(*(&CAN0RXDSR0 + address))

#define		CAN_TBSEL_ADDRESS(address)		(*(&CAN0TBSEL + address))

#define		CAN_TFLG_ADDRESS(address)		(*(&CAN0TFLG + address))



typedef enum CAN_Bsp
{
	CAN_BSPTYPE125K ,
	CAN_BSPTYPE250K ,
	CAN_BSPTYPE500K ,
	CAN_BSPTYPE1000K ,
}Can_BspType;


typedef struct Can_Time
{
	int Can_Time1;
	int Can_Time2;
	int Can_Time3;
	int Can_Time4;
}Can_TimeType;


typedef struct Can_Msg
{
	unsigned int Id;
	unsigned char Ide;
	unsigned char Data[CAN_MSGTYPE_DATA_MAXLEN];
	unsigned char Len;
	unsigned char Prty;
	unsigned char SenGeway;
}Can_MsgType;

typedef struct _Can_SendMsg
{
	char address;	//
	int data;//
	int Memory;	//通道数据
	void (*Act)(void);//发送完成检测
	int next_node;//下个寄存器地址
}Can_SendType;

typedef struct Can_HwCfgType
{
	Can_BspType BPS;
	unsigned char Geway;
}Can_InitType;


typedef struct _Can_AddressType
{   	
        Can_BspType BPS;
	unsigned char Geway;
	unsigned char  CANCTL0;
	unsigned char  CANCTL1;
	unsigned char  CANBTR0;
	unsigned char  CANBTR1;
	unsigned char  CANRFLG;
	unsigned char  CANRIER;
	unsigned char  CANTBSEL;
	unsigned char  CANTFLG;
	unsigned char  CANTXIDR0;
	unsigned char  CANTXIDR1;
	unsigned char  CANTXIDR2;
	unsigned char  CANTXIDR3;
	unsigned char  CANIDMR0;
	unsigned char  CANIDMR1;
	unsigned char  CANIDMR2;
	unsigned char  CANIDMR3;
	unsigned char  CANIDMR4;
	unsigned char  CANIDMR5;
	unsigned char  CANIDMR6;
	unsigned char  CANIDMR7;
	unsigned char  CANRXIDR0;
	unsigned char  CANRXIDR1;
	unsigned char  CANRXIDR2;
	unsigned char  CANRXIDR3;
	unsigned char  CANRXDSR0;
	unsigned char  CANRXDLR;
	unsigned char  CANTXDSR0;
	unsigned char  CANTXDLR;
	unsigned char  CANTXTBPR;
}Can_AddressType;


/*
void CAN_RegAdd_Cfg(int channel)
{
    CANCTL0 = ((&CAN0CTL0) + channel * 0x40);
    CANCTL1 = ((&CAN0CTL1) + channel * 0x40);
    CANBTR0 = ((&CAN0BTR0) + channel * 0x40);
    CANBTR1 = ((&CAN0BTR1) + channel * 0x40);
    CANRFLG = ((&CAN0RFLG) + channel * 0x40);
    CANRIER = ((&CAN0RIER) + channel * 0x40);
    CANTBSEL = ((&CAN0TBSEL) + channel * 0x40);
    CANTFLG = ((&CAN0TFLG) + channel * 0x40);
    CANTXIDR0 = ((&CAN0TXIDR0) + channel * 0x40);
    CANTXIDR1 = ((&CAN0TXIDR1) + channel * 0x40);
    CANTXIDR2 = ((&CAN0TXIDR2) + channel * 0x40);
    CANTXIDR3 = ((&CAN0TXIDR3) + channel * 0x40);
    CANIDMR0 = ((&CAN0IDMR0) + channel * 0x40);
    CANIDMR1 = ((&CAN0IDMR1) + channel * 0x40);
    CANIDMR2 = ((&CAN0IDMR2) + channel * 0x40);
    CANIDMR3 = ((&CAN0IDMR3) + channel * 0x40);
    CANIDMR4 = ((&CAN0IDMR4) + channel * 0x40);
    CANIDMR5 = ((&CAN0IDMR5) + channel * 0x40);
    CANIDMR6 = ((&CAN0IDMR6) + channel * 0x40);
    CANIDMR7 = ((&CAN0IDMR7) + channel * 0x40);
    CANRXIDR0 = ((&CAN0RXIDR0) + channel * 0x40);
    CANRXIDR1 = ((&CAN0RXIDR1) + channel * 0x40);
    CANRXIDR2 = ((&CAN0RXIDR2) + channel * 0x40);
    CANRXIDR3 = ((&CAN0RXIDR3) + channel * 0x40);
    CANRXDSR0 = ((&CAN0RXDSR0) + channel * 0x40);
    CANRXDLR = ((&CAN0RXDLR) + chann
}*/


static Can_InitType Can0_InitType =
{
	CAN_BSPTYPE125K,
	CAN_PASSAGEWAY0,
};

static Can_InitType Can1_InitType =
{
	CAN_BSPTYPE125K,
	CAN_PASSAGEWAY1,
};



void Can_Init(void);
void Can_DeInit(Can_InitType *Can_InitTypeCfg);
void Can_SendTime(Can_TimeType Can_TimeTypeCfg);
void Can_SendMsgAll(void);
Bool Can_GetCallBack(void);


#endif