// Given two strings s1 and s2 what is the minimum number of character-wise operations (add/delete/edit) needed to be performed.
// To convert one string the the other.
// Using bottom up dynamic programming approach.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 100

void print2DArray(int**, int, int);
int minVal(int, int, int);

void main(){
    char *str1, *str2, *temp;
    int str1_len, str2_len;
    temp = (char*)malloc(sizeof(char)*MAX_STR_LEN);

    // Input string 1, allocate memory and copy
    printf("Enter String 1: ");
    scanf("%s",temp);
    str1_len = strlen(temp);
    str1 = (char*)malloc(sizeof(char)*str1_len);
    strcpy(str1,temp);

    // Input string 2, allocate memory and copy
    printf("Enter String 2: ");
    scanf("%s",temp);
    str2_len = strlen(temp);
    str2 = (char*)malloc(sizeof(char)*str2_len);
    strcpy(str2,temp);

    // free temp
    free(temp);

    // Create DP table
    int **dp = (int**)malloc(sizeof(int*)*(str1_len+1));
    for(int i=0;i<=str1_len;i++){
        dp[i] = (int*)malloc(sizeof(int)*(str2_len+1));
    }

        // Initialize DP table with -1
    for(int i=0;i<=str1_len;i++){
        for(int j=0;j<=str2_len;j++){
            dp[i][j] = -1;
        }
    }

    // Print inital DP table
    printf("\nInitial DP table: \n");
    print2DArray(dp,str1_len,str2_len);

    // Fill the DP table, using bottom up approach
    for(int i=0;i<=str1_len;i++){

        for(int j=0;j<=str2_len;j++){
        
            if(i==0){
                dp[i][j] = j;
            }
            else if(j==0){
                dp[i][j] = i;
            }
            else{
                //str[i-1] because for i=0 and j=0, the loop sets DP value to 0.
                // For i = n, need the (n-1)th character from the string.
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1];        //number of ops = diagonally left + 0 as the current char is same.
                else
                    // dp[i-1][j] - Indicates a remove operation
                    // dp[i][j-1] - Indicates an insert operation
                    // dp[i-1][j-1] - Indicates a replace operation 
                    dp[i][j] = 1 + minVal(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }

    // Print final DP table
    printf("\nFinal DP table: \n");
    print2DArray(dp,str1_len,str2_len);

    printf("Number of operations to convert \"%s\" to \"%s\" = %d",str1,str2,dp[str1_len][str2_len]);
    free(str1);
    free(str2);
}

void print2DArray(int **arr, int l1, int l2){
    for(int i=0; i<=l1; i++){
        for(int j=0; j<=l2; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int minVal(int a, int b, int c){
    return (a<b) ? (a<c) ? a : c : (b<c) ? b : c;
}