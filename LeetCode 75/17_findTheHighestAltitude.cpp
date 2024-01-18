#include<iostream>
#include<vector>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int prevGain = 0;
    int highestGain = 0;

    for(int num: gain){
        prevGain += num;
        highestGain = max(highestGain, prevGain);
    }

    return highestGain;
}

int main() {

    vector<int> gain = {-5, 1, 8, 0, -7};

    cout<<"Largest altitude: "<<largestAltitude(gain);
    
    return 0;
}