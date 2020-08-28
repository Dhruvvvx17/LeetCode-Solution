#include<stdlib.h>
#include<stdio.h>

int uniquePathsWithObstacles(int** obstacleGrid, int rows, int columns){

    int i, j;
    
    long int **res = (long int**)malloc(sizeof(long int*)*rows);
    for(i=0;i<rows;i++){
        res[i] = (long int*)malloc(sizeof(long int)*columns);
    }
    
    // Is destination/start itself an obstacle?
    // If yes, no possible way to reach
    if(obstacleGrid[rows-1][columns-1]==1 || obstacleGrid[0][0]==1)
        return 0;
    else
        res[rows-1][columns-1] = 1;
    
    //fill bottom row - right to left
    for(j=columns-2;j>=0;j--){
        if(obstacleGrid[rows-1][j]==1 || res[rows-1][j+1]==0)
            res[rows-1][j] = 0;
        else
            res[rows-1][j] = 1;
    }
    
    //fill right most column
    for(i=rows-2;i>=0;i--){
        if(obstacleGrid[i][columns-1]==1 || res[i+1][columns-1]==0)
            res[i][columns-1] = 0;
        else
            res[i][columns-1] = 1;
    }

    //fill rest of matrix
    for(i=rows-2;i>=0;i--){
        for(j=columns-2;j>=0;j--){
            if(obstacleGrid[i][j]==1)
                res[i][j] = 0;
            else
                res[i][j] = res[i+1][j] + res[i][j+1];
        }
    }
    
    printf("Final res array: \n");    
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    
    int r = res[0][0];

    for(i=0;i<rows;i++){
        free(res[i]);
    }
    free(res);

    return r;
}


int main(int argc, char const *argv[])
{
    int columns, rows;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&rows,&columns);

    int **obstacles = (int**)malloc(sizeof(int*)*rows);
    for(int i=0;i<rows;i++){
        obstacles[i] = (int*)malloc(sizeof(int)*columns);
    }

    printf("Enter 1 for obstacle, 0 otherwise: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("Is [%d][%d] an obstacle? ",i,j);
            scanf("%d",&obstacles[i][j]);
        }
    }

    printf("Original obstacle array: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d ",obstacles[i][j]);
        }
        printf("\n");
    }


    printf("Number of paths from source [0][0] to destination [%d][%d] = %d",rows-1,columns-1,uniquePathsWithObstacles(obstacles,rows,columns));


    for(int i=0;i<rows;i++){
        free(obstacles[i]);
    }
    free(obstacles);

    return 0;
}
