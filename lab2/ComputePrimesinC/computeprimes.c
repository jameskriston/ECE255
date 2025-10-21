

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
/* ComputePrimes() to compute first n prime numbers greater than 2
*  Parameters: num - number of primes to compute
*  
*  Translate this algorithm from C to assembly and then check for any optimizations. 
*  There can likely be some optimizations made to the loops, specifically when comparing
*  the loop condition ex. sometimes a >= and a > can differ in execution. 
*  Will need to copy in code from multiply.asm for the j^2 condition. 
*
*
*
*/

void ComputePrimesOld(int num){ //algorithm from lab manual
    int i,j,n;
    n=0;
        for(i=3;n<num;i+=2){  //check every odd number starting from 3
            int prime = 1; //flag variable to indicate if number is prime
            int limit = i/2; //no factors larger than i/2 except i itself
                
            for(j=2;j<limit;j++){ //check for factors from 2 to i/2
                    if(i%j==0){ //if a factor is found
                        prime = 0;  //set flag to not prime
                        break;
                    }
                }
            if(prime){ //if number is prime
                n++;  //increment count of primes found
            }
        }
}

void ComputePrimesNew(int num){
   int i,n,j;
   int prime;
   n = 0; // start counting from 2

    for (i = 3; n < num; i += 2) {
        prime = 1; //flag variable to indicate if number is prime
   
        for (j = 3; (uint64_t)j * j <= i; j += 2) { //check for factors from 3 to sqrt(i), only odd factors
            if (i % j == 0) { //if a factor is found
                prime = 0; //set flag to not prime
                break;
            }
        }
        if (prime) { //if number is prime
            n++;    //increment count of primes found
          
        }
    }
}