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

#define TRUE        (1==1)
#define FALSE       (1==0)

#define BUTTON_PUSHED           TRUE
#define BUTTON_RELEASED         FALSE
#define LED_ON                  TRUE
#define LED_OFF                 FALSE



int ReadButton1Status( void );
// int ReadButton2Status(void);

// enumerated type state for controlling sequence of button presses
typedef enum { 
        event0, // waiting for beginning of sequence
        event1, // button 1 got pushed and released 
        event2  // button 2 gets pushed and released, check for one final click of button 2 and back to event0
} state;

/**********************************************************************************************************************/
int polling(void)
{
        GPIO_InitTypeDef  GPIO_InitStructure;

        /* GPIOD Periph clock enable */
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);

        //configure the PA0 as the output pin
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOA, &GPIO_InitStructure);

        //configure PA4 as the input pin
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
        GPIO_Init(GPIOA, &GPIO_InitStructure);



/*
//        *** Intialize button 2 to pin 5 ***

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;       // set pin 5 to be input for button 2 
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;    // probably some error in here
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
        GPIO_Init(GPIOA, &GPIO_InitStructure);



*/
/*
//              *** Use for if taking input from a sequence of button 1 once, button 2 twice ***

        *** simple implementation of a finite state machine to control sequence of button presses and LED toggle ***

*/
/*
        state current = event0; // current event to track sequence, begin with event 0, which is the state of no input yet
        int b1_last_state = FALSE; // assume last states of buttons to be false
        int b2_last_state = FALSE;
        int LED_state = FALSE; //assume LED begins off 
        while(1){
                
                int b1_state = ReadButton1Status(); // read button 1 status
                int b2_state = ReadButton2Status(); // read button 2 status
                // If button has last been pushed, and is then released, then it is considered a "click of button", make true, otherwise false
                int b1_click = (b1_state == BUTTON_RELEASED && b1_last_state == BUTTON_PUSHED); 
                int b2_click = (b2_state == BUTTON_RELEASED && b2_last_state == BUTTON_PUSHED);

                switch(current){

                        case event0:    // the event0 case is if sequence has not started, check if b1 gets clicked to begin sequence        
                                if(b1_click){
                                        current = event1; 
                                }
                        break;

                        case event1:    // if b1 got clicked, we are on event1, check if b2 gets clicked now then go to event2

                                if (b2_click){
                                        current = event2; 
                                }
                                else if(b1_click) {
                                        current = event0;  
                                }
                        break;

                        case event2:    // if b2 got clicked once after b1, check if b2 gets clicked again to finish sequence

                                if(b2_click){
                                        if(LED_state){ // if LED is already on, turn it off
                                              GPIO_ResetBits(GPIOA, GPIO_Pin_0);
                                              LED_state = !LED_state;  
                                        }
                                        else { // if LED is off, turn it on
                                              GPIO_SetBits(GPIOA, GPIO_Pin_0);
                                              LED_state = !LED_state;
                                        }
                                        current = event0; // sequence completed, restart sequence
                                }
                                else if(b1_click){
                                        current = event0; // if no 2nd b2 click, restart sequence
                                }
                        break;
                }
        b1_last_state = b1_state; // set the last state to the most recent state before iterating loop again
        b2_last_state = b2_state;
        }
      */      
        while (1)
        {

                 if( BUTTON_PUSHED == ReadButton1Status() )
                {
                                GPIO_SetBits(GPIOA, GPIO_Pin_0);
                }
                else
                {
                                GPIO_ResetBits(GPIOA, GPIO_Pin_0);
                }



        }

        /*
//              *** Use for if taking input from button 2 rather than button 1 ***     
        while (1)
        {

                 if( BUTTON_PUSHED == ReadButton2Status() )
                {
                                GPIO_SetBits(GPIOA, GPIO_Pin_0);
                }
                else
                {
                                GPIO_ResetBits(GPIOA, GPIO_Pin_0);
                }



        }
        */

        return 0;
}

/**********************************************************************************************************************/
int ReadButton1Status( void )
{
        if(GPIOA->IDR & GPIO_Pin_4 )
        {
                return( BUTTON_PUSHED );
        }

        return( BUTTON_RELEASED );
}

/**********************************************************************************************************************/

/* 
//      *** Use for if taking input from button 2 rather than button 1 ***
int ReadButton2Status(void) { //exact same as button 1 status reading, but for a different button

        if(GPIOA->IDR & GPIO_Pin_5){    // pin 5 is placeholder, could be different pin for button 2
                return (BUTTON_PUSHED); // i would probably know if i read the lab manual in depthly, but i'm more of a skim over it and not actually read it type of guy
        }
        return (BUTTON_RELEASED);

}
*/


int
main(int argc, char* argv[])
{
        polling();
        return 0;
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
