#include "MPC5606B.h"
#include "Window_lifter.h"
#include "GPIO.h"
#include "typedefs.h"
#include "PIT.h"
#include "PLL.h"
#include "Button.h"
#include "IntcInterrupts.h"
#include "Exceptions.h"



void disableWatchdog(void) 
{
  SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
  SWT.SR.R = 0x0000d928; 
  SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}








int main(void) {
	for (;;) {
	initModesAndClock();
		
		/* Disable Watchdog */
		disableWatchdog();
		
		/*Initialize LEDs */
		GPIO_config();
		
		/*Initialize Interrupts */
		INTC_InitINTCInterrupts();
		
		/*Initialize Exception Handlers */
		EXCEP_InitExceptionHandlers();
		
		
	
		
		PIT_device_init();
		PIT_channel_config(PITCHANNEL_0 );	
		PIT_channel_active(PITCHANNEL_0);
		PIT_channel0_ISR();
	    
		INTC_InstallINTCInterruptHandler(PIT_channel0_ISR,59,1);  /* Install Interrupt routine for this specific channel */
  


  /* Loop forever */
  }
}



