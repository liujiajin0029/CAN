#ifndef __RELAYM_H
#define __RELAYM_H

#include "hidef.h"
#include "derivative.h"
#include "VBAT_DATA.h"


typedef struct _Hv_IOInit
{
	char IO_dir;
}RelayM_IOInitType;

RelayM_IOInitType Hv_IOType =
{
	1,
};

typedef struct _RelayM
{
   char KEY_PRE;
   char KEY_RELAY;
} RelayM_IoChgType;

RelayM_IoChgType MODE_IO =
{
	1,
	0,
};

void RelayM_Init();

#endif
