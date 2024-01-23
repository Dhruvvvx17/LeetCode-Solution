#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool closeStrings(string word1, string word2) {
    if(word1.size() != word2.size()) return false;

    vector<int> count1(26,0), count2(26,0);

    for(char x: word1) count1[x-'a']++;

    for(char x: word2) count2[x-'a']++;

    // check if same unique characters exist in both strings
    for(int i=0; i<26; i++){
        if(count1[i] > 0 && count2[i] == 0) return false;
    }

    sort(count1.begin(), count1.end());
    sort(count2.begin(), count2.end());

    // check if the sorted count vectors are the same
    if(count1 == count2) return true;
    return false;
}

int main() {

    string word1 = "abcccb";
    string word2 = "bcaaac";

    if (closeStrings(word1, word2)) {
        cout<<"TRUE";
    }
    else {
        cout<<"FALSE";
    }
    
    return 0;
}