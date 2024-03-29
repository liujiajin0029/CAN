#include "derivative.h"
#include "CAN.h"
#include "CAN_CFG.h"

//测试
//void CAN_IDSend(Can_InitType *Can_Cfg)
//{
//	unsigned char Remove_Warning = 0;
//	/*扩展帧ID发送*/
//	if (Can_Cfg->Ide)
//	{
//		/*消除移位超过15位编译器警告问题*/
//		Remove_Warning =  (Can_Cfg->Id) >> 15;
//		*((&CAN0TXIDR0) + Memory) = (unsigned char)(Remove_Warning >> 6);
//		*((&CAN0TXIDR1) + Memory) = (unsigned char)(Can_Cfg->Id >> 13) & 0xE0;
//		*((&CAN0TXIDR1) + Memory) |= 0x18;
//		*((&CAN0TXIDR1) + Memory) |= (unsigned char)(Can_Cfg->Id >> 15) & 0x07;
//		*((&CAN0TXIDR2) + Memory) = (unsigned char)(Can_Cfg->Id >> 7);
//		*((&CAN0TXIDR3) + Memory) = (unsigned char)(Can_Cfg->Id << 1);
//		*((&CAN0TXIDR3) + Memory) |= 0x01;
//	}
//	else
//	{
//		/*标准帧ID发送*/
//		*((&CAN0TXIDR0) + Memory) = (unsigned char)(Can_Cfg->Id>>3);
//		*((&CAN0TXIDR1) + Memory) = (unsigned char)(Can_Cfg->Id<<5);
//	}
//}
//
//void Can_DataSend(Can_InitType *Can_Cfg)
//{
//	/*报文数据发送*/
//	for (sp = 0; sp < Can_Cfg->Len;sp++)
//	{
//		*((&CAN0TXDSR0) + sp + Memory) = Can_Cfg-> Data[sp];
//	}
//	/*报文长度发送*/
//	*((&CAN0TXDLR) + Memory) = Can_Cfg-> Len;
//
//	*((&CAN0TXTBPR) + Memory) = Can_Cfg-> Prty;
//
//	/*清除标志*/
//	*((&CAN0TFLG) + Memory) = SendBuf;
//}
//
//Can_SendType Can_Send[] =
//{
//	{
//		{(&CAN_CTL0_ADDRESS(CAN_PASSAGEWAY1)),(&CAN_CTL0_ADDRESS(CAN_PASSAGEWAY1))|0x01},
//		/*ID帧检测发送*/
//		{},
//		/*报文检测发送*/
//		{		},
//		/*发送完成检测*/
//		{		},
//		/*下个寄存器地址*/
//		{		},
//	};
//
//	{
//		{		},
//		{		},
//		{		},
//		{		},
//	}
//}
//
//void Can_SendAll(Can_SendType *Can_SendType)
//{
//	int i;
//
//	for (i = 0 ; i<64 ; i++)
//	{
//		if (((&CAN0TXIDR0) + Can_SendAll[i].Memory + i) == Can_SendAll[i].address)
//		{
//			*((&CAN0TXIDR0) + Can_SendAll[i].Memory+i) = Can_SendAll[i].data;
//		}
//		else
//		{
//
//		}
//	}
//}
//

void Can_Init(void)
{
	Can_DeInit(&Can0_InitType);
	Can_DeInit(&Can1_InitType);
}

/*CAN初始化函数*/
void Can_DeInit(Can_AddressType *Address , Can_InitType *Can_Cfg)
{
	unsigned char Memory = 0;
	unsigned char BlockingTime = 0;

	Memory = Can_Cfg->Geway;

	if ((Address->CANCTL0) & 0x01== 0)
	{
		Address->CANRXDSR0|= 1;
	}
	while ((Address->CANCTL1)  & 0x01 == 0)
	{

	}

	(Address->CANBTR0)  |= 0xC0;
	/*CAN通道通信频率选择*/
	if (Can_Cfg->BPS == CAN_BSPTYPE125K)
	{
		(Address->CANBTR1) |= 0x1D;
		(Address->CANBTR0)  = 0x0E;
	}
	else if (Can_Cfg->BPS == CAN_BSPTYPE250K)
	{
		(Address->CANBTR1) |= 0x1C;
		(Address->CANBTR0)  = 0x07;
	}
	else if (Can_Cfg->BPS == CAN_BSPTYPE500K)
	{
		(Address->CANBTR1) |= 0x1C;
		(Address->CANBTR0)  = 0x03;
	}
	else if (Can_Cfg->BPS == CAN_BSPTYPE1000K)
	{
		(Address->CANBTR1) |= 0x1C;
		(Address->CANBTR0)  = 0x01;
	}
	else
	{

	}

	(Address->CANIDMR0) = 0xFF;
	(Address->CANIDMR1) = 0xFF;
	(Address->CANIDMR3) = 0xFF;
	(Address->CANIDMR4) = 0xFF;
	(Address->CANIDMR5) = 0xFF;
	(Address->CANIDMR6) = 0XFF;
	(Address->CANIDMR7) = 0xFF;
	(Address->CANCTL1) = 0xC0;
	(Address->CANCTL0) = 0x00;

	while (((Address->CANCTL1) & 0x01) == 1 && BlockingTime < 5)
	{
		BlockingTime ++;
	}

	(Address->CANRIER) |= 0x01;
}

/*报文发送函数*/
Bool Can_SendMsg(Can_MsgType *Can_Cfg)
{
	unsigned char SendBuf = 0 , sp = 0 , BlockingTime = 0;
	unsigned char Memory = 0;
	unsigned int Remove_Warning = 0;
	Memory = Can_Cfg->SenGeway;

	/*判断发送报文长度*/
	if (Can_Cfg->Len > CAN_MSGTYPE_DATA_MAXLEN)
	{
		return FALSE;
	}
	while ((*((&CAN0CTL0) + Memory) & 0x10) == 0)
	{
		return FALSE;
	}
	do
	{
		*((&CAN0TBSEL) + Memory) = *((&CAN0TFLG) + Memory);

		SendBuf = *((&CAN0TBSEL) + Memory);

		BlockingTime++;

	}while (!(SendBuf) && BlockingTime < 5);

	/*扩展帧ID发送*/
	if (Can_Cfg->Ide)
	{
		/*消除移位超过15位编译器警告问题*/
		Remove_Warning =  (Can_Cfg->Id) >> 15;
		*((&CAN0TXIDR0) + Memory) = (unsigned char)(Remove_Warning >> 6);
		*((&CAN0TXIDR1) + Memory) = (unsigned char)(Can_Cfg->Id >> 13) & 0xE0;
		*((&CAN0TXIDR1) + Memory) |= 0x18;
		*((&CAN0TXIDR1) + Memory) |= (unsigned char)(Can_Cfg->Id >> 15) & 0x07;
		*((&CAN0TXIDR2) + Memory) = (unsigned char)(Can_Cfg->Id >> 7);
		*((&CAN0TXIDR3) + Memory) = (unsigned char)(Can_Cfg->Id << 1);
		*((&CAN0TXIDR3) + Memory) |= 0x01;
	}
	else
	{
		/*标准帧ID发送*/
		*((&CAN0TXIDR0) + Memory) = (unsigned char)(Can_Cfg->Id>>3);
		*((&CAN0TXIDR1) + Memory) = (unsigned char)(Can_Cfg->Id<<5);
	}

	/*报文数据发送*/
	for (sp = 0; sp < Can_Cfg->Len;sp++)
	{
		*((&CAN0TXDSR0) + sp + Memory) = Can_Cfg-> Data[sp];
	}
	/*报文长度发送*/
	*((&CAN0TXDLR) + Memory) = Can_Cfg-> Len;

	*((&CAN0TXTBPR) + Memory) = Can_Cfg-> Prty;
	/*清除标志*/
	*((&CAN0TFLG) + Memory) = SendBuf;

	return TRUE;

}

/*报文周期发送函数*/
void Can_SendTime(Can_TimeType TimeCfgType)
{
	static int Can_TIME ;

	Can_TIME++;

	if (Can_TIME == TimeCfgType.Can_Time1)
	{
		if (Can_SendMsg(&Can_MsgSendType1) == 1)
		{

		}
	}

	if (Can_TIME == TimeCfgType.Can_Time2)
	{
		if (Can_SendMsg(&Can_MsgSendType2) == 1)
		{

		}
	}
	if (Can_TIME >= TimeCfgType.Can_Time4)
	{
		Can_TIME = 0;
	}

}

/*发送所有函数*/
void Can_SendMsgAll(void)
{
	Can_SendTime(Can_TimeSendType);
}

/*报文接收函数*/
Bool Can_GetMsg(Can_MsgType *Can_Cfg)
{

	unsigned char sp;

	/*检测接收标志*/
	if (!(CAN1RFLG_RXF))
	{
		return FALSE;
	}
	/*检测 CAN协议报文模式 （一般/扩展） 标识符*/
	if (CAN1RXIDR1_IDE)
	{
	// IDE = Recessive (Extended Mode)
		return FALSE;
	}
	/*读标识符*/
	Can_Cfg ->Id = (unsigned int)(CAN1RXIDR0<<3) |
						  (unsigned char)(CAN1RXIDR1>>5);

	if (CAN1RXIDR1 & 0x10)
	{
		Can_Cfg->Ide = TRUE;
	}
	else
	{
		Can_Cfg->Ide = FALSE;
	}

	/*读取数据长度 */
	Can_Cfg->Len = CAN1RXDLR;

	/*读取数据*/
	for (sp = 0; sp < Can_Cfg->Len; sp++)
	{
		Can_Cfg->Data[sp] = *((&CAN1RXDSR0)+sp);
	}
	/*清RXF标志位 (缓冲器准备接收)*/
	CAN1RFLG = 0x01;

	return TRUE;
}

/*接收报文数据处理函数*/
Bool Can_GetCallBack(void)
{
	if (Can_GetMsg(&Can_MsgGetType) == TRUE)
	{
		/*接收信息*/
		if (Can_MsgGetType.Id == 0x3c && (!Can_MsgGetType.Ide))
		{
			if (Can_SendMsg(&Can_MsgSendType3) == 1)
			{

			}
		}
	}
	return 0;
}


