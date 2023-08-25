#include<iostream>
#include<map>
using namespace std;

bool isAnagram(string s, string t) {
    
    if(s.size() != t.size())
        return false;
    
    map<char,int> my_map;
    
    for(int i=0; i<s.size(); i++) {
        my_map[s[i]]++;
        my_map[t[i]]--;
    }
    
    for (auto x: my_map){
        if (x.second != 0)
            return false;
    }
    return true;
}

int main() {

    string s,t;

    cout<<"Enter string s: ";
    cin>>s;

    cout<<"Enter string t: ";
    cin>>t;


    if(isAnagram(s,t))
        cout<<"Anagrams!";
    else
        cout<<"Not Anagrams";
    
    return 0;
}