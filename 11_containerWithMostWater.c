#include<stdio.h>
#include<stdlib.h>

int maxArea(int* height, int heightSize){

    int i = 0;
    int j = heightSize-1;
    int max_area = 0;
    int minHeight;
    
    while(i<j){
        minHeight = (height[i] > height[j]) ? height[j] : height[i];
        if( minHeight * (j-i) > max_area)
                max_area =  minHeight * (j-i);
        
        if(height[i]==minHeight)
            i++;
        else
            j--;
    }
    
    return (max_area);
    
}

void main(){
    int *arr = (int*)malloc(sizeof(int)*9);
    arr[0] = 1;
    arr[1] = 8;
    arr[2] = 6;
    arr[3] = 2;
    arr[4] = 5;
    arr[5] = 4;
    arr[6] = 8;
    arr[7] = 3;
    arr[8] = 7;

    printf("The maximum water the container can hold is = %d",maxArea(arr,9));
    return;
}