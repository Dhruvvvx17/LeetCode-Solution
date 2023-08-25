#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int maxProfit(int* prices, int pricesSize){
    int i = 0, n = pricesSize-1;
    int profit = 0;
    int buy, sell;
    while(i<n){
        // loop till next possible buying opportunity
        while(i<n && prices[i+1]<=prices[i]) i++;
            buy = prices[i];
        
        // loop till next possible selling opportunity
        while(i<n && prices[i+1]>prices[i]) i++;
            sell = prices[i];

        profit += (sell - buy);        
    }
    
    return profit;
}

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter stock prices: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Max profit = %d",maxProfit(arr,n));
}