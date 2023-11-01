#include<iostream>
#include<vector>
using namespace std;

string mergeAlternately(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();

    int l = (len1 < len2) ? len1 : len2;

    string res = "";
    for(int i=0; i<l; i++){
        res += word1[i];
        res += word2[i];
    }

    res += word1.substr(l, len1);
    res += word2.substr(l, len2);

    return res;
}

int main() {
    
    string word1, word2;
    cout<<"Enter word 1: ";
    cin>>word1;

    cout<<"Enter word 2: ";
    cin>> word2;

    string res = mergeAlternately(word1, word2);

    cout<<"Result: "<<res;

    return 0;
}