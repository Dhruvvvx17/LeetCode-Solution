#include<stdio.h>
#include<stdlib.h>

// Rotates the image 90deg clockwise
void rotateRight(int** matrix, int matrixSize){
    int i,j;
    for(i=0;i<matrixSize;i++){
        for(j=i+1;j<matrixSize;j++){
            matrix[i][j] = matrix[i][j] + matrix[j][i];
            matrix[j][i] = matrix[i][j] - matrix[j][i];
            matrix[i][j] = matrix[i][j] - matrix[j][i];
        }
    }
    
    for(i=0; i<matrixSize; i++){
        for(j=0; j<(matrixSize/2); j++){
            matrix[i][j] = matrix[i][j] + matrix[i][matrixSize-j-1];
            matrix[i][matrixSize-j-1] = matrix[i][j] - matrix[i][matrixSize-j-1];
            matrix[i][j] = matrix[i][j] - matrix[i][matrixSize-j-1];
        }
    }

    return;
}

// Rotates the image 90deg anticlockwise
void rotateLeft(int** matrix, int matrixSize){
    int i,j;
    for(i=0;i<matrixSize-1;i++){
        for(j=0;j<matrixSize-i-1;j++){
            matrix[i][j] = matrix[i][j] + matrix[matrixSize-j-1][matrixSize-i-1];
            matrix[matrixSize-j-1][matrixSize-i-1] = matrix[i][j] - matrix[matrixSize-j-1][matrixSize-i-1];
            matrix[i][j] = matrix[i][j] - matrix[matrixSize-j-1][matrixSize-i-1];
        }
    }
    
    for(i=0; i<matrixSize; i++){
        for(j=0; j<(matrixSize/2); j++){
            matrix[i][j] = matrix[i][j] + matrix[i][matrixSize-j-1];
            matrix[i][matrixSize-j-1] = matrix[i][j] - matrix[i][matrixSize-j-1];
            matrix[i][j] = matrix[i][j] - matrix[i][matrixSize-j-1];
        }
    }

    return;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter matrix dimension: ");
    scanf("%d",&n);

    int **arr = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        arr[i] = (int*)malloc(sizeof(int)*n);
    }

    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    printf("Original image: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    rotateRight(arr,n);

    printf("Rotated image right by 90degrees: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    rotateLeft(arr,n);
    printf("Rotated image left by 90degrees: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
