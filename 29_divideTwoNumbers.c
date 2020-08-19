#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int divide(int dividend, int divisor){

    // Check if the quotient will be positive or negative
    int isPositive = 1;
    
    // If both dividend and divisor are negative, quotient will be positive
    if(dividend<0 && divisor<0) isPositive = 1;

    // If either one of the dividend or the divisor is negative, quotient will be negative
    else if(dividend<0 || divisor<0) isPositive = 0;

    // Convert to long to handle the overflow conditions
    long new_dividend = dividend, new_divisor = divisor;
    
    // Extracts the absolute value of both. Was not working with with the inbuilt abs() functions, hence subtracted from 0 if negative.
    if(new_dividend<0) new_dividend = 0 - new_dividend;
    if(new_divisor<0) new_divisor = 0 - new_divisor;    
    

    // Core logic, using shift operations and dividing the dividend by doubling the divisor in every iteration
    long temp,i;
    long res = 0;
    while(new_dividend>=new_divisor){
        i = 1;
        temp = new_divisor;
        while(new_dividend>=temp){
            new_dividend -= temp;
            res += i;
            i = i<<1;
            temp = temp<<1;
        }
    }
 
    // Check if final answer should be +ve or -ve based on the original sign of dividend and divisor
    if(!isPositive) res = 0-res;

    // Return either INT_MIN or INT_MAX or the result accordingly
    if(res>INT_MAX)
        return(INT_MAX);
    
    else if(res<INT_MIN)
        return(INT_MIN);
    
    else
        return(res);
}

int main(int argc, char const *argv[]){
    int dividend, divisor;
    printf("Enter dividend: ");
    scanf("%d",&dividend);
    printf("Enter divisor: ");
    scanf("%d",&divisor);

    printf("Result of division: %d",divide(dividend,divisor));

    return 0;
}
