#include<stdio.h>
#include<stdlib.h>

int getMin(int first, int second){
    return (first<second) ? first : second;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

    // allocate O(n) memory for res
    int n = triangleSize;
    int *res = (int*)malloc(sizeof(int)*n);
    
    // copy value of bottom most row to result array
    // because for bottom row, min path sum is node value itself
    for(int i=0;i<n;i++){
        res[i] = triangle[n-1][i];
    }
    
    // bottom up (row n-2) find min path sum all the way up (row 0)
    for(int row=n-2; row>=0; row--){

        // iterate over all nodes in current row
        for(int index=0; index<=row; index++){
        
            // new min path => min of below two paths + current Node value
            res[index] = getMin(res[index], res[index+1]) + triangle[row][index];       

        }

    }

    // final res[0] -> min path sum at the top of the triangle
    return res[0];
}


void main(){

    int n;
    printf("Enter number of rows in triangle: ");
    scanf("%d",&n);


    int **triangle = (int**)malloc(sizeof(int*)*n);

    // allocate memory for each row
    for(int i=0;i<n;i++){
        triangle[i] = (int*)malloc(sizeof(int)*(i+1));
    }

    for(int row=0;row<n;row++){
        printf("Enter row %d values: \n", row);
        for(int i=0;i<=row;i++){
            printf("Node %d: ", i);
            scanf("%d",&triangle[row][i]);
        }
    }

    // not sure why this variable
    int triangleColSize = 1;

    int res = minimumTotal(triangle, n, &triangleColSize);

    printf("Min path sum: %d",res);
}