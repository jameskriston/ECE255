#include <stdio.h>
#include <windows.h>
#include "timer.h"
#include <stdlib.h>
#include "computeprimes.h"

    int main(int argc, char *argv[]){
        int num = 0;
        if(argc!=2){
        printf("You entered too many arguments, or zero, terminating program"); //check that 1 argument is entered
        exit(0);
    }
    if(atoi(argv[1])==0){
        printf("You entered an argument that is not a number\n"); //check that only a number is entered
        printf("%d\n",num);
        exit(0);
    }

       num = atoi(argv[1]);
       printf("Computing prime numbers greater than 2 and less than %d\n",num); 
        int repeats = 10000; //the amount of times to run the algorithm for accurate timing
        timer_init();
        timer_start();
       
                for (int i = 0; i < repeats; i++){ //loop algorithm1 
                    ComputePrimesOld(num);
                }
                    double time1 = timer_stop(); //stop timer and store time to do x repeats of algorithm1
        
        timer_init(); //reset timer
        timer_start();
                for (int i = 0; i < repeats; i++){ //loop algorithm2
                    ComputePrimesNew(num);
                }
                    double time2 = timer_stop(); //stop timer and store time to do x repeats of algorithm2       
       
        printf("Algorithm 1 computing first %d primes greater than 2 (repeated %d times) took %.4f microseconds\n",num,repeats,time1); //print results
        printf("Algorithm 2 computing first %d primes greater than 2 (repeated %d times) took %.4f microseconds\n",num,repeats,time2);

    }