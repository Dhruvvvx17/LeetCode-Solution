#include<iostream>
#include<vector>
using namespace std;

int numDistinct(string s, string t) {
    int s_length = s.length();
    int t_length = t.length();
        
    vector<vector<unsigned int>> dp_table(t_length + 1, vector<unsigned int> (s_length + 1, 0));

    for (int col = 0; col <= s_length; col++) dp_table[0][col] = 1;

    for (int col = 1; col <= s_length; col++){
        for (int row = 1; row <= t_length; row++){
            dp_table[row][col] = dp_table[row][col-1] + (t[row-1]==s[col-1] ? dp_table[row-1][col-1] : 0);   
        }
    }
    
    return dp_table[t_length][s_length];
}

int main(){

    string s, t;
    cout<<"Enter sentence: ";
    cin>>s;
    cout<<"Enter substring: ";
    cin>>t;

    cout<<"Number of distinct subsequences: "<<numDistinct(s,t)<<endl;

    return 0;
}