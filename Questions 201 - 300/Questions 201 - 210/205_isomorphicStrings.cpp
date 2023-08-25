#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool isIsomorphic(string s, string t) {
    map<char, char> dict;
    map<char, char> rev_dict;
    int len = s.size();
    
    for(int i=0; i<len; i++) {
        
        // char not yet in either dict
        if(dict.find(s[i]) != dict.end() && t[i] != dict.find(s[i])->second)
            return false;
        
        if(rev_dict.find(t[i]) != rev_dict.end() && s[i] != rev_dict.find(t[i])->second)
            return false;
        
        dict.insert({s[i], t[i]});
        rev_dict.insert({t[i], s[i]});            
    }
    return true;
}

int main() {

    string s, t;
    cout<<"Enter first string: ";
    cin>>s;

    cout<<"Enter second string: ";
    cin>>t;

    if(s.size() != t.size())
        cout<<"Unequal lengths, can't be isomorphic";
    else {
        if(isIsomorphic(s,t))
            cout<<"Isomorphic Strings!";
        else
            cout<<"Not Isomorphic Strings!";
    }
    return 0;
}