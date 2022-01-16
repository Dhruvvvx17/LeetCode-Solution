// Similar to fibonacci

#include<stdio.h>
#include<stdlib.h>

int climbStairs(int n){
    
    int a,b,res;
    a = 0;
    b = 1;
    
    for(int i=0;i<n;i++){
        res = a+b;
        a = b;
        b = res;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number of steps [between 1 to 45]: ");
    scanf("%d",&n);

    printf("Number of ways to get to the top with 1 or 2 steps at a time = %d",climbStairs(n));

    return 0;
}
