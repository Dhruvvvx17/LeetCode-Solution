#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxCandies = *max_element(candies.begin(), candies.end());

    vector<bool> res;

    for(int c:candies){
        if(c + extraCandies >= maxCandies)
            res.push_back(true);
        else
            res.push_back(false);
    }
    return res;
}

int main() {
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    vector<bool> res = kidsWithCandies(candies, extraCandies);

    cout<<"Result: ";
    for(bool x: res){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}