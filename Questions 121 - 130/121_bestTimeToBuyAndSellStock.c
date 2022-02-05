#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int maxProfit(int* prices, int pricesSize){
    int buy = prices[0];
    int sell = prices[0];
    int profit = sell-buy;
    
    for(int i=1; i<pricesSize; i++){
        if(prices[i]<buy)
            buy = prices[i];
        
        else if((prices[i]-buy)>profit){
            sell = prices[i];
            profit = sell-buy;
        }
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