#include <time.h>
#include <stdint.h>
#include <windows.h>
#include "timer.h"

    static LARGE_INTEGER start, freq;

    void timer_init(void){ 
    QueryPerformanceFrequency(&freq);
    }

    void timer_start(void){
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    }

    uint64_t timer_stop(void){
        LARGE_INTEGER end;
        QueryPerformanceCounter(&end);
    
       double seconds = (double)(end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
        
        return (seconds*1e6);

    }