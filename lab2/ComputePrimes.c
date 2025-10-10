

#include <stdlib.h>


int main(){

   int i;
   int n;
   int j;
   int prime;
   int limit = i/2;

                for(i=3,n=0; n<20; i+=2){

                    prime = 1;
                    limit i/2;

                        for(j=2; j<limit; j++){

                            if(i%j==0){

                                prime = 0;
                                break;

                            }

                        }

                        if(prime){
                            n++;
                            printf("%d\n",i);
                        }
                }

return 0;



}