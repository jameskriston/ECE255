//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//
// ----------------------------------------------------------------------------

#include <stdio.h>
#include "diag/Trace.h"
#include <stm32f0xx.h>
// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

volatile int EXTI4_5Counter = 0b0000;
volatile int flag = 0;


//       *** 2 Button Sequence Handler ***
//      Sequence is button one twice, and button two three times	

void EXTI4_15_IRQHandler(void){
        if(EXTI->PR & EXTI_PR_PR4){             // if the interrupt was from pin4 (button 1)

                EXTI->PR |= EXTI_PR_PR4;        // this is like writing x = x | y 
                                                // read PR and EXTI PR4, and assign the value from the OR back to PR, if  PR | PR4 evaluates to true, sets PR to 1, clears the flag
                                                 
                if(flag==0){                    // press B1 once, update sequence flag
                	flag = 1;
                }
                else if(flag==1) {              // press B1 a second time, update sequence flag
                	flag = 2;
                }
                else{                           // otherwise reset sequence flag
                	flag = 0;
                }
        }
        if(EXTI->PR & EXTI_PR_PR5){             // if interrupt was from pin5 (button 2)
                EXTI->PR |= EXTI_PR_PR5;        // clear the flag if true


                if(flag==2){                    // if B1 has been pressed twice, and B2 pressed once, update sequence flag
                       flag = 3;                
                }
                else if(flag==3){               // if B2 pressed a second time, update sequence flag
                	flag = 4;
                }
                else if(flag==4){               // if B2 pressed a third time, sequence is complete

                        EXTI4_5Counter = (EXTI4_5Counter + 1) & 15;   // increment the counter with bit wrapping
                        flag = 0;                                     // reset sequence
                }
        		else {
        			flag = 0;                               // if incorrect input is given, reset sequence to beginning
        		}
        }
}
/**********************************************************************************************************************/
void interrupt(void) {
        EXTI_InitTypeDef EXTI_InitStructure;
        GPIO_InitTypeDef GPIO_InitStructure;
        NVIC_InitTypeDef NVIC_InitStructure;

        /* Enable GPIOA clock */
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

        /* Configure PA0,PA1,PA2,PA3 pin as output floating */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOA, &GPIO_InitStructure);

        /* Configure PA4 pin as input floating */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
        GPIO_Init(GPIOA, &GPIO_InitStructure);

        /* Configure PA5 pin as input floating */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
        GPIO_Init(GPIOA, &GPIO_InitStructure);

        /* Enable SYSCFG clock */
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

        /* Connect EXTI0 Line to PA0,PA1,PA2,PA3 pin */
        SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0 | EXTI_PinSource1 |
        EXTI_PinSource2 | EXTI_PinSource3);

        /*Configure EXTI5 Line */
        EXTI_InitStructure.EXTI_Line = EXTI_Line5;
        EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
        EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
        EXTI_InitStructure.EXTI_LineCmd = ENABLE;
        EXTI_Init(&EXTI_InitStructure);

        /* Configure EXTI4 line */
        EXTI_InitStructure.EXTI_Line = EXTI_Line4;
        EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
        EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
        EXTI_InitStructure.EXTI_LineCmd = ENABLE;
        EXTI_Init(&EXTI_InitStructure);

        /* Enable and set EXTI4_15 Interrupt */
        NVIC_InitStructure.NVIC_IRQChannel = EXTI4_15_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
        NVIC_Init(&NVIC_InitStructure);


//               *** Loop to handle binary LED display  ***
               while (1) {
                       if ((EXTI4_5Counter & 0b1000) != 0)        // if bit 3 is 1, turn PA0 on
                               GPIO_SetBits(GPIOA, GPIO_Pin_0);
                       else
                               GPIO_ResetBits(GPIOA, GPIO_Pin_0); // if bit 3 is 0, turn PA0 off

                       if ((EXTI4_5Counter & 0b0100) != 0)        // if bit 2 is 1, turn PA1 on
                               GPIO_SetBits(GPIOA, GPIO_Pin_1);
                       else
                               GPIO_ResetBits(GPIOA, GPIO_Pin_1); // if bit 2 is 0, turn PA1 off

                       if ((EXTI4_5Counter & 0b0010) != 0)        // if bit 1 is 1, turn PA2 on
                               GPIO_SetBits(GPIOA, GPIO_Pin_2);
                       else
                               GPIO_ResetBits(GPIOA, GPIO_Pin_2); // if bit 1 is 0, turn PA2 off

                       if ((EXTI4_5Counter & 0b0001) != 0)        // if bit 0 is 1, turn PA3 on
                               GPIO_SetBits(GPIOA, GPIO_Pin_3);
                       else
                               GPIO_ResetBits(GPIOA, GPIO_Pin_3); // if bit 0 is 0, turn PA3 off
               }

}
/**********************************************************************************************************************/
int main(void) {
        interrupt();
        return 0;
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
