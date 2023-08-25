// Idea is to have two loops, for j and i (starting and end index), j starts from zero and is incremented everytime j and i 
// point to the same character. The overall max is noted after every iteration

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lengthOfLongestSubstring(char * s){
    
    // Because minimum length would be 1 
    int count = 1;
    
    if(!s[0])
        return 0;
    else if(strlen(s)==1)
        return 1;

    int n = strlen(s);
    int curr_count = 1;
    int j_start_index = 0;
    
    for(int i=0; i<n; i++){
        for(int j=j_start_index; j<i; j++){
            if(s[i]!=s[j])
                curr_count += 1;
            else
                j_start_index = j + 1;
            }
            if(curr_count>count)
                count = curr_count;
            curr_count = 1; 
        }    
    return count;
}

void main(){
    char *temp = (char*)malloc(sizeof(char)*100);
    
    printf("Enter the string: ");
    scanf("%s",temp);
    int len = strlen(temp);

    char *str = (char*)malloc(sizeof(char)*len);
    strcpy(str,temp);
    free(temp);

    printf("Length of longest substring with no repeating characters = %d",lengthOfLongestSubstring(str));
    free(str);
    return;
}