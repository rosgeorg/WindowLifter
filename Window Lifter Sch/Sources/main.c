#include "HAL/MPC5606B.h"
#include "HAL/GPIO.h"
#include "HAL/type_definitions.h"
#include "MAL/Button.h"
#include "MAL/LED.h"
#include "HAL/Exceptions.h"
#include "HAL/IntcInterrupts.h"
#include "HAL/PIT.h"
#include "HAL/PLL.h"
#include "MAL/Scheduler.h"
#include "Application/Window_Lifter.h"



void disableWatchdog(void) 
{
  SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
  SWT.SR.R = 0x0000d928; 
  SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}





int main(void) {
	initModesAndClock();
	initPeriClkGen();				
					/* Disable Watchdog */
					disableWatchdog();
					
					/*Initialize LEDs, turn on LEDs */
					GPIO_config();
					window_closed();
					/*Initialize Interrupts */
					INTC_InitINTCInterrupts();
					
					/*Initialize Exception Handlers */
					EXCEP_InitExceptionHandlers();
					
					
				
					PIT_device_init();
					PIT_channel_config(PITCHANNEL_0 );
					PIT_channel_active(PITCHANNEL_0);
					INTC.CPR.B.PRI=0;
					INTC_InstallINTCInterruptHandler(PIT_channel0_ISR,59,1);  /* Install Interrupt routine for this specific channel */
					
					
						
					init_Counters();
						
					Sch_Ex();
	
	
					
	
	
  
  /* Loop forever */
  for (;;) {
   
  }
}



