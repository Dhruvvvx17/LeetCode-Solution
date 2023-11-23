#include<iostream>
#include<vector>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0, j = 0;

    while(j < t.size() && i < s.size()){
        if(s[i] == t[j]){
            i++;
        }
        j++;
    }

    if(i==s.size()) return true;
    return false;
}

int main() {
    string s = "abc";
    string t = "ahbgdc";

    if(isSubsequence(s,t))
        cout<<"Is Subsequence";
    else
        cout<<"Is not subsequence";

    return 0;
}