#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    if(s.size()==0) return false;
    
    vector<bool> dp(s.size()+1,false);
    
    // the original word is to be treated at 1-indexed in dict
    // mark dp[0] as true
    dp[0] = true;
    
    for(int i=1; i<=s.size(); i++) {
        for(int j=i-1; j>=0; j--) {
            
            if(dp[j]) {
                string word = s.substr(j, i-j);
                if(std::find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    
    return dp[s.size()];
}

int main() {
    string s;
    cout<<"Enter input string: ";
    cin>>s;

    int n;
    cout<<"Enter number of substrings: ";
    cin>>n;

    string temp;
    vector<string> wordDict;
    for(int i=0; i<n; i++) {
        cout<<"Enter string "<<i+1<<" : ";
        cin>>temp;
        wordDict.push_back(temp);
    }

    if(wordBreak(s, wordDict)) {
        cout<<"substrings can make up the string";
    }
    else {
        cout<<"substrings cannot make up the strings";
    }

    return 0;
}
