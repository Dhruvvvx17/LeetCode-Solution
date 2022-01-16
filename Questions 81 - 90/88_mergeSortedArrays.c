#include <stdio.h>
#include <stdlib.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{

    // if second array is empty
    if (n == 0)
        return;

    // if first array is just 0's then return second array as first
    if (m == 0){
        int i = 0;
        while (i < n){
            nums1[i] = nums2[i];
            i += 1;
        }
        return;
    }

    /* general case */
    int i = m - 1, j = n - 1, x = nums1Size - 1; // iterator over two arrays

    for (x = nums1Size - 1; x >= 0; x--){
        if (nums1[i] >= nums2[j]){
            nums1[x] = nums1[i];
            i -= 1;
        }
        else{
            nums1[x] = nums2[j];
            j -= 1;
        }

        // check if reached end of array-1
        if (i < 0){
            x = x - 1;
            while (j >= 0){
                nums1[x] = nums2[j];
                j -= 1;
                x -= 1;
            }
            break;
        }

        // check if reached end of array-2
        if (j < 0) break;
    }
}

void main(){
    int m, n, arr1Size, arr2Size;
    int *arr1, *arr2;

    printf("Enter arr 1 size: ");
    scanf("%d", &m);
    printf("Enter arr 2 size: ");
    scanf("%d", &n);

    arr1Size = m + n;
    arr2Size = n;

    arr1 = (int *)calloc(arr1Size, sizeof(int)); //use calloc to init all the values to 0
    arr2 = (int *)malloc(sizeof(int) * arr2Size);

    for (int i = 0; i < m; i++){
        printf("Enter arr1 element %d: ", i);
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < n; i++){
        printf("Enter arr2 element %d: ", i);
        scanf("%d", &arr2[i]);
    }

    merge(arr1, arr1Size, m, arr2, arr2Size, n);

    printf("Final array: ");
    for(int i=0;i<arr1Size;i++){
        printf("%d ",arr1[i]);
    }
}