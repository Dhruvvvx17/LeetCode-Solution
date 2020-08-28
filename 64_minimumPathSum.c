#include<stdio.h>
#include<stdlib.h>

int getMin(int a,int b){
    return (a>b) ? b : a;
}

int minPathSum(int** grid, int rows, int columns){

    
    int i,j;
     
    //bottom row
    for(j=columns-2;j>=0;j--){
        grid[rows-1][j] += grid[rows-1][j+1]; 
    }

    //right most column
    for(i=rows-2;i>=0;i--){
        grid[i][columns-1] += grid[i+1][columns-1]; 
    }
    
    //fill rest of the matrix
    for(i=rows-2;i>=0;i--){
        for(j=columns-2;j>=0;j--){
            grid[i][j] += getMin(grid[i+1][j],grid[i][j+1]);
        }
    }

    printf("\nCumulative cost array:\n");
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }

    
    return grid[0][0];
}

int main(int argc, char const *argv[])
{
    int columns, rows;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&rows,&columns);

    int **arr = (int**)malloc(sizeof(int*)*rows);
    for(int i=0;i<rows;i++){
        arr[i] = (int*)malloc(sizeof(int)*columns);
    }

    printf("Enter cell cost: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("Cost for [%d][%d]? ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\nOriginal cost array: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }


    printf("\nMinimum cost of a path from source [0][0] to destination [%d][%d] = %d",rows-1,columns-1,minPathSum(arr,rows,columns));


    for(int i=0;i<rows;i++){
        free(arr[i]);
    }
    free(arr);

    return 0;

}
