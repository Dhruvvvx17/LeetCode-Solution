#include<iostream>
#include<vector>
using namespace std;

int countSubstrings(string s) {
    
    if(s.size()==1)
        return 1;
    
    int count = 0;
    
    for(int i=0; i<s.size(); i++) {
        
        // odd length palindromes
        int l = i, r = i;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            count += 1;
            l -= 1;
            r += 1;
        }
        
        // even length palindromes
        l = i, r = i+1;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            count += 1;
            l -= 1;
            r += 1;
        }            
    }
    return count;
}

int main() {

    string s;
    cout<<"Enter input string: ";
    cin>>s;

    cout<<"Number of palindromic substrings in "<<s<<": "<<countSubstrings(s)<<endl;
    
    return 0;
}