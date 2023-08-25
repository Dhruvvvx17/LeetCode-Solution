// Simple brute force string matching.
// If one character matches then increase the haystack and needle index simultaneously
// else set needle back to 0 and haystack to the index just after the previous match.
// If two characters do not match simply increment haystack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strStr(char * haystack, char * needle){

    int hl,nl;
    hl = strlen(haystack);
    nl = strlen(needle);
    
    if(hl<nl)
        return -1;
    
    int index = 0;
    int hi=0, ni=0;
    
    while(hi<hl && ni<nl){
        if(haystack[hi]==needle[ni]){
            hi++; ni++;
        }
        else{
            index++;
            hi = index;
            ni = 0;
        }
    }
    
    if(ni == nl){
        return index;
    }
    return -1;
}


int main(int argc, char const *argv[])
{
    char *temp, *haystack, *needle;
    int len = 0; 
    temp = (char*)malloc(sizeof(char)*100);

    printf("Enter haystack (string): ");
    scanf("%s",temp);
    
    len = strlen(temp);
    haystack = (char*)malloc(sizeof(char)*len);
    strcpy(haystack,temp);

    printf("Enter needle (substring): ");
    scanf("%s",temp);

    len = strlen(temp);
    needle = (char*)malloc(sizeof(char)*len);
    strcpy(needle,temp);

    free(temp);

    printf("\"%s\" found at index %d in \"%s\"\n",needle,strStr(haystack,needle),haystack);

    free(haystack);
    free(needle);
    return 0;
}
