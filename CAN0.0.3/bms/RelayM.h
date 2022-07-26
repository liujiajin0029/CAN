#ifndef __RELAYM_H
#define __RELAYM_H

#include "hidef.h"
#include "derivative.h"
#include "VBAT.h"


#define RELAYM_PRESWITCHON  	(1U)
#define RELAYM_PRESWITCHOFF 	(0U)
#define RELAYM_PRE_IOON  		(1U)
#define RELAYM_PRE_IOOFF 		(1U)
#define RELAYM_CLOSEDTOTALON 	(5U)
#define RELAYM_CLOSEDTOTALOFF	(0U)
#define RELAYM_CLOSEDTOTALIO 	(1U)

void RelayM_Change(unsigned char  Switch);
void RelayM_Control(unsigned char  Pre_switch,unsigned char state);
#endif
