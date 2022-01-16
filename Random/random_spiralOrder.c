#include<stdio.h>
#include<stdlib.h>

int* spiralOrder(int** matrix, int rows, int* columns, int* returnSize){

    if(!rows || !columns) {
        *returnSize = 0;     
        return NULL;   
    }

    int *res = (int*)malloc(sizeof(int)*((*columns)*rows));

    int top_left,bottom_left,top_right,bottom_right,nums,total;
    top_left = 0;
    top_right = *columns;
    bottom_left = -1;
    bottom_right = rows;
    nums = 0;
    total = (rows*(*columns));

    int i=0,j=0;

    while(nums<total){

        //Going right
        while(j<top_right){
            res[nums++] = matrix[i][j];
            j++;
        }
        j--;
        top_right--;
        i++;
        if(nums==total) break;

        // Going Down
        while(i<bottom_right){
            res[nums++] = matrix[i][j];
            i++;
        }
        i--;
        bottom_right--;
        j--;
        if(nums==total) break;    

        // Going Left
        while(j>bottom_left){
            res[nums++] = matrix[i][j];
            j--;
        }
        j++;
        bottom_left++;
        i--;
        if(nums==total) break;

        // Going up
        while(i>top_left){
            res[nums++] = matrix[i][j];
            i--;
        }
        i++;
        top_left++;
        j++;
        if(nums==total) break;        


    }

    *returnSize = nums;
    return res;
}


int main(int argc, char const *argv[]){
    int rows,columns;
    printf("Enter number of rows and columns: ");
    scanf("%d %d",&rows,&columns);

    int **arr = (int**)malloc(sizeof(int*)*rows);
    for(int i=0;i<rows;i++){
        arr[i] = (int*)malloc(sizeof(int)*columns);
    }

    printf("Enter matrix elements: ");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int returnSize = 0;
    int *res = spiralOrder(arr,rows,&columns,&returnSize);

    printf("Matrix values in spiral order: ");
    for(int x=0;x<returnSize;x++){
        printf("%d ",res[x]);
    }

    return 0;
}
