#include<iostream>
#include<unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    
    if(s.size() == 0)
        return 0;
    if(s.size() == 1)
        return 1;
    
    unordered_set<char> visited;

    int l, r, res = 0;
    l = 0;
    
    visited.insert(s[l]);
    
    for(r = 1; r < s.size(); r++) {
        // found repeating char
        if(visited.find(s[r]) != visited.end()) {
            // remove characters from left until repeating character is removed
            while(visited.find(s[r]) != visited.end()){
                visited.erase(s[l]);
                l+=1;
            }                
            // add new character in set
            visited.insert(s[r]);
        }
        else {
            visited.insert(s[r]);
        }
        // update result
        res = ( r - l + 1 > res) ?  (r-l+1) : res;            
    }
    return res;
}

int main() {

    string s = "abcabcdefgabc";

    cout<<"Longest unique word substring: "<<lengthOfLongestSubstring(s);    
    
    return 0;
}