#include<iostream>
#include<vector>
using namespace std;

bool isVowel(char s){
    if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u' || s=='A' || s=='E' || s=='I' || s=='O' || s=='U') return true;
    return false;
}

string reverseVowels(string s) {
    int left = 0;
    int right = s.size()-1;
    char temp;

    while(left < right) {

        while(!isVowel(s[left]) && left < right) {
            left+=1;
        }

        while(!isVowel(s[right]) && left < right) {
            right-=1;
        }
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left+=1;
        right-=1;
    }

    return s;
}

int main() {

    string s = "leetcode";

    cout<<"Reversed vowels: "<<reverseVowels(s);
    
    return 0;
}