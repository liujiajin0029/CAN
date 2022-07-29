#include <hidef.h>           /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "CAN.h"
#include "ECT.h"
#include "PLL.h"
#include "Node.h"
#include "PrechargeM.h"
#include "Node.h"
#include "PIT.h"

#define IO_MODEPC4 PORTC_PC4
#define IO_DIRRC4 DDRC_DDRC4

#define IO_MODEPC5 PORTC_PC5
#define IO_DIRRC5 DDRC_DDRC5

void main(void)
{
  /* put your own code here */

    DisableInterrupts;
    Pii_Init();
    Can_Init();
    Pit_Init();
    Ect_Init();
    EnableInterrupts;
    IO_MODEPC4 = 1;
    IO_DIRRC4 = 1;
    IO_MODEPC5 = 0;
    IO_DIRRC5 = 1;

    for(;;)
    {
      _FEED_COP();   /* feeds the dog */

    }                /* loop forever */
                       /* please make sure that you never leave main */
}
