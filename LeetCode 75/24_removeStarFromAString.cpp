#include<iostream>
#include<vector>
using namespace std;

string removeStars(string s) {
    string res = "";

    for(int i=0; i<s.size(); i++){
        if(s[i] != '*') res += s[i];
        else res.pop_back();
    }

    return res;
}

int main() {

    string s = "leee*tcc*ode";

    cout<<"Final String: "<<removeStars(s);
    
    return 0;
}