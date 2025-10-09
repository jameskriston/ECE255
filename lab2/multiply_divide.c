#include <stdlib.h>
#include <stdio.h>

    int main(){
    int a = 0;
    int b = 0;
    int result = 0;
    int remainder = 0;   

    printf("Enter M for multiplication or D for division\n");
    
        char ch = getchar();
        if(ch =='m' || ch =='M'){
            printf("Enter two integers in format: a,b\n");
            
            scanf("%d,%d",&a,&b);
                int i = 0;
                    while(i<a){
                        result+=b;
                        i++;
                    }
            printf("Result of multiplication of %d * %d = %d", a,b,result);
            exit(0);

        }
        if (ch == 'd' || ch == 'D'){
            printf("Enter two integers in format a,b - Where a is your numerator and b is the denominator\n");
            scanf("%d,%d",&a,&b);
                if(b==0){
                    printf("Division by zero is undefined");
                    exit(0);
                }
                int i = a;
                    while(i>=b){
                    result++;
                    i = i-b;    
                }
                remainder = i;
                printf("Quotient is %d with remainder of %d",result,remainder);
                exit(0);
        }
        else{
            printf(" one of m,M,d,D was not entered, exiting.\n");
            exit(0);
        }
        }

    /*
    
    int a = 0;
    int b = 0;
    int result = 0;
    int remainder = 0;   
    
    
    int i = a;
                    while(i>=b){
                    result++;
                    i = i-b;    
                }
                remainder = i;


r1 = a
r2 = b
quotient = 0
remainder = 0

check if b = 0
exit if so

r3-> quotient
r4->reaminder

index (R0) has value of R1
move value 0 into r5

loop

        compare 







    
    
    
    
    
    */