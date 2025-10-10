#include "timer.h"

    void timer_init(void){


        SysTick->LOAD = 0xFFFFFFF;
        SysTick->VAL = 0;
        SysTick->CTRL = 5;


    }

    void timer_start(void){

        SysTick->VAL = 0;
        
    }

    uint32_t timer_stop(void){

        return 0xFFFFFF - SysTick->VAL;

    }