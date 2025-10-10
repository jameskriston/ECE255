//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>
#include "diag/Trace.h"
#include <stm32f0xx.h>
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the $(trace) output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

extern void ComputePrimes(void);

uint32_t ms;
#define systick_start  SysTick->VAL=SystemCoreClock/1000;SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;
#define systick_stop   SysTick->CTRL&=~(SysTick_CTRL_ENABLE_Msk);ms = SystemCoreClock/1000-SysTick->VAL;

volatile unsigned int timer=0;
void SysTick_Handler(void)                 //SysTick interrupt handler
{
	timer++;
}

int main(int argc, char* argv[])
{
  // At this stage the system clock should have already been configured
  // at high speed.
        /* Setup SysTick Timer for 1 msec interrupts.
             ------------------------------------------
            1. The SysTick_Config() function is a CMSIS function which configure:
               - The SysTick Reload register with value passed as function parameter.
               - Configure the SysTick IRQ priority to the lowest value (0x0F).
               - Reset the SysTick Counter register.
               - Configure the SysTick Counter clock source to be Core Clock Source (HCLK).
               - Enable the SysTick Interrupt.
               - Start the SysTick Counter.

            2. You can change the SysTick Clock source to be HCLK_Div8 by calling the
               SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8) just after the
               SysTick_Config() function call. The SysTick_CLKSourceConfig() is defined
               inside the stm32f0xx_misc.c file.

            3. You can change the SysTick IRQ priority by calling the
               NVIC_SetPriority(SysTick_IRQn,...) just after the SysTick_Config() function
               call. The NVIC_SetPriority() is defined inside the core_cm0.h file.

            4. To adjust the SysTick time base, use the following formula:

                 Reload Value = SysTick Counter Clock (Hz) x  Desired Time base (s)

               - Reload Value is the parameter to be passed for SysTick_Config() function
               - Reload Value should not exceed 0xFFFFFF
         */
        if(SysTick_Config(SystemCoreClock/1000))  // Setup SysTick Timer
        {
                while(1);                         //exception catch
        }

        volatile uint32_t t0 = SysTick->VAL;

//
// Calls your function to compute the first 20 prime numbers
//

        ComputePrimes();


        t0 = t0-SysTick->VAL;

        trace_printf( "Total time to compute 20 prime numbers: %d clock cycles\r\n", t0 );
        while(1){}

}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
