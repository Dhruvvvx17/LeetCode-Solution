#include<stdio.h>
#include<stdlib.h>

int uniquePaths(int m, int n){

    if(m==1 || n==1)
        return 1;
    
    int i,j;
    int *res = (int*)malloc(sizeof(int)*(n-1));
    for(i=0;i<n-1;i++){
        res[i] = 1;
    }
    
    int right;

    for(i=m-1;i>0;i--){
        right = 1;
        for(j=n-2;j>=0;j--){
            res[j] += right;
            right = res[j];    
        }
    }
    
    return res[0];
}

int main(int argc, char const *argv[])
{
    int m,n;
    printf("Enter array dimension: ");
    scanf("%d %d",&m,&n);

    printf("Starting position = [0,0]\nFinal position = [%d,%d]\nNumber of ways = %d\n",m-1,n-1,uniquePaths(m,n));
    return 0;
}
