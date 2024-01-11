#include<iostream>
using namespace std;

bool isVowel(char s){
    if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u') return true;
    return false;
}

int maxVowels(string s, int k) {
    int currCount = 0;
    int highestCount = 0;
    int n = s.size();

    // count of first k vowels
    for(int i=0; i<k; i++) {
        if(isVowel(s[i])) currCount++;
    }

    highestCount = currCount;

    if(highestCount == k)
        return highestCount;

    for(int i=k; i<n; i++) {
        if(isVowel(s[i-k])) currCount--;
        if(isVowel(s[i])) currCount++;
        highestCount = max(highestCount, currCount);
    }   
    return highestCount;
}

int main() {

    string s = "abciiidef";
    int k = 3;

    cout<<"Maximum number of vowels in a substring of length "<<k<<" is "<<maxVowels(s,k);    
    
    return 0;
}