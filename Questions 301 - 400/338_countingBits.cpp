#include<iostream>
#include<vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> dp(n+1,0);
    int offset = 1;

    for(int i=1; i<=n; i++){
        if(offset*2 == i)
            offset = i;

        dp[i] = 1 + dp[i-offset];
    }
    return dp;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    vector<int> res = countBits(n);

    for(int x: res){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}