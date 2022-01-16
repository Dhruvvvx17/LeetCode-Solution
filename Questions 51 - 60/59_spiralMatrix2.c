#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    
    if(n==0) {
        *returnSize = 0;     
        return NULL;   
    }

    int **res = (int**)malloc(sizeof(int*)*(n));  
    *returnColumnSizes = (int*)malloc(sizeof(int)*n);
    
    for(int i=0;i<n;i++){
        res[i] = (int*)malloc(sizeof(int)*n);
        (*returnColumnSizes)[i] = n;
    }
    
    int top_left, top_right, bottom_left, bottom_right;
    top_left = 0;
    top_right = n;
    bottom_left = -1;
    bottom_right = n;
    
    int i=0, j=0, nums=1, total=n*n;

    while(nums<=total){

        // Going Right
        while(j<top_right){
            res[i][j] = nums++;
            j++;
        }    
        top_right--;
        j--;
        i++;
        if(nums>total) break;
        
        // Going Down
        while(i<bottom_right){
            res[i][j] = nums++;
            i++;
        }
        bottom_right--;
        i--;
        j--;
        if(nums>total) break;
        
        //Going Left
        while(j>bottom_left){
            res[i][j] = nums++;
            j--;
        }
        bottom_left++;
        j++;
        i--;
        if(nums>total) break;
        
        //Going Up
        while(i>top_left){
            res[i][j] = nums++;
            i--;
        }
        top_left++;
        i++;
        j++;
        if(nums>total) break;
    }

    *returnSize = n;
    return res;
}


int main(int argc, char const *argv[])
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    int returnSize;
    int *returnColumnSize;

    int **res = generateMatrix(n,&returnSize,&returnColumnSize);

    for(int i=0;i<returnSize;i++){
        for(int j=0;j<returnSize;j++){
            printf("%d\t",res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
