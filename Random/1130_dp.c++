#include<iostream>
#include<vector>
#include<map>
using namespace std;

int solve(map<pair<int,int>,int>& mp,int l,int r,vector<vector<int>> &v){
        if(l==r)return 0;
        int ans = INT_MAX;
        if(v[l][r] != -1)return v[l][r];
        for(int i = l; i < r; i++){
            ans = min(ans,mp[{l,i}]*mp[{i+1,r}]+solve(mp,l,i,v)+solve(mp,i+1,r,v));
        }
        return v[l][r] = ans;
}

int mctFromLeafValues(vector<int>& arr) {
    map<pair<int,int>,int> mp;
    int i,j,n = arr.size();
    for(i = 0; i < n; i++){
        mp[{i,i}] = arr[i];
        for(j = i+1; j < n; j++){
            mp[{i,j}] = max(mp[{i,j-1}],arr[j]);
        }
    }
    vector<vector<int>> v (n,vector<int>(n,-1));
    // for(auto &i: mp)cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    return solve(mp,0,n-1,v);
}