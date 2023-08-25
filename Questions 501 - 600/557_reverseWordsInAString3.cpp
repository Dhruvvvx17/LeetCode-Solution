#include<iostream>
#include<vector>
using namespace std;

#define MAX_LEN 100

string reverseWord(string s) {
    int n = s.size();
    char temp;
    for(int i = 0; i<n/2; ++i) {
        temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }

    return s;
}


string reverseWords(string s) {
    int n = s.size();
    string res = "";
    string t = "";
    for(int i=0; i<n; ++i) {
        while(s[i] != ' ' && i<n){
            t += s[i];
            i += 1;
        }
        res += reverseWord(t);
        res += ' ';
        t = "";
    }
    
    // remove last space
    res.pop_back();
    
    return res;
}

int main() {

    char s[MAX_LEN];
    cout<<"Enter a string: ";
    cin.getline (s, MAX_LEN);

    string res = reverseWords(s);

    cout<<res;

    return 0;
}