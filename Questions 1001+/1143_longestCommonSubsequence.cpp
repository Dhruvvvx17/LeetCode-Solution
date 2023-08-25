#include<iostream>
#include<vector>
using namespace std;


int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int optimizeddp(string text1, string text2) {
    vector<int> old_row (text2.size()+1, 0);
    
    int m = text2.size();
    int n = text1.size();     
    
    // iterate over first string
    for(int i=n-1; i>=0; --i) {
        vector<int> new_row (text2.size()+1, 0);
        
        // iterate over second string
        for(int j=m-1; j>=0; --j) {
            if(text1[i] == text2[j])
                new_row[j] = 1 + old_row[j+1];
            else
                new_row[j] = getMax(old_row[j], new_row[j+1]);
        }
        
        old_row = new_row;
    } 
    
    return old_row[0];
}

int regulardp(string text1, string text2) {
    
    int m = text2.size();
    int n = text1.size();
    
    vector<vector<int>> dp (n+1, vector<int>(m+1, 0));
    
    // iterate over first string
    for(int i=n-1; i>=0; --i){
        
        // iterate over second string
        for(int j=m-1; j>=0; --j){

            // if match found go diagonal
            if(text1[i] == text2[j])
                dp[i][j] = 1 + dp[i+1][j+1];
            // else max of right and down
            else
                dp[i][j] = getMax(dp[i+1][j], dp[i][j+1]);
        }
    }
    
    
    // for(int i=0; i<n; i++){        
    //     for(int j=0; j<m; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
        return dp[0][0];
}

int longestCommonSubsequence(string text1, string text2) {
    
    // normal dp approach
    return regulardp(text1, text2);
    
    // memoized dp approach
    return optimizeddp(text1, text2);
    
}


int main() {

    string s1, s2;

    cout<<"Enter string 1: ";
    cin>>s1;

    cout<<"Enter string 2: ";    
    cin>>s2;

    cout<<"Longest common subsequence: "<<regulardp(s1, s2)<<endl;

    cout<<"Longest common subsequence (using memoization): "<<optimizeddp(s1, s2)<<endl;

    return 0;
}