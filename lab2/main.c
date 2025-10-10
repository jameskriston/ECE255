#include <stdio.h>
#include <timer.h>
#include <stdlib.h>
#inlucde "factorial.h"

    int main(char argc, char *arg[]){
        int num = 0;
        if(argc!=2){
        printf("You entered too many arguments, or zero, terminating program");
        exit(0);
    }
    if(atoi(argv[1])==0){
        printf("You entered an argument that is not a number\n");
     
        printf("%d\n",num);

        exit(0);

    }
       num = atoi(arg[1])
       printf("Computing prime numbers greater than 2 and less than %d\n",num);

        timer_init();
        timer_start();

        uint32_t result = ComputePrimes(num);
        uint32_t time = timer_stop();

        printf("Execution time: %d\n",time);

        return 0;


    }