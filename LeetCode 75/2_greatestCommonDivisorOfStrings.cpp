#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2) {
    return (str1 + str2 == str2 + str1) ? str1.substr(0, __gcd(str1.size(), str2.size())) : "";
}

int main() {
    
    string word1, word2;
    cout<<"Enter word 1: ";
    cin>>word1;

    cout<<"Enter word 2: ";
    cin>> word2;

    string res = gcdOfStrings(word1, word2);

    if(res.size() > 0)
        cout<<"Result: "<<res;
    else
        cout<<"No GCD";

    return 0;
}