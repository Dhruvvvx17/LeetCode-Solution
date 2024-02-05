#include<iostream>
#include<queue>
using namespace std;

string predictPartyVictory(string senate) {

    queue<int> rads;
    queue<int> dirs;

    for(int i=0; i<senate.size(); i++){
        if(senate[i]=='R') rads.push(i);
        else dirs.push(i);
    }

    int nextPos = senate.size() + 1;
    int rads_index = 0;
    int dirs_index = 0;

    while(!rads.empty() && !dirs.empty()){
        if(rads.front() < dirs.front()){
            rads.push(nextPos);
        }
        else{
            dirs.push(nextPos);
        }
        rads.pop();
        dirs.pop();
        nextPos += 1;
    }

    return (rads.empty()) ? "Dire" : "Radiant";
}

int main() {

    string senate = "DDRRRDRDDRDDRRRR";

    string res = predictPartyVictory(senate);

    cout<<res;
    
    return 0;
}