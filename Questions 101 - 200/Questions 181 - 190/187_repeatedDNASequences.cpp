#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
            
    set<string> seen;
    set<string> repeated;
    vector<string> res;
    
    if(s.length()<10)
        return res;
    
    for(int i=0; i<s.length()-9; i++){
        string sub = s.substr(i,10);
            if (!seen.count(sub))
                seen.insert(sub);                                        
            else
                repeated.insert(sub);
    }
    
    res.assign(repeated.begin(), repeated.end());

    return res;
}

int main(){

    string s;
    cout<<"Enter DNA: ";
    cin>>s;

    vector<string>res = findRepeatedDnaSequences(s);

    cout<<"Repeating DNA patterns found: "<<endl;
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<endl;
    }

    return 0;
}