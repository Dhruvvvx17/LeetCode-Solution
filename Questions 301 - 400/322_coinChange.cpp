#include<iostream>
#include<vector>
using namespace std;

int getMin(int a, int b){
    return (a>b) ? b : a;
}

int coinChange(vector<int>& coins, int amount) {
    
    // dp array of size amount+1 (going from 0 -> amount) 
    // each value initialized to amount+1
    vector<int> dp (amount+1, amount+1);
    
    // init dp[0] = 0 
    dp[0] = 0;

    // iterate over all amounts
    for(int amt=1; amt<=amount; amt++) {

        // iterate over all coin values
        for(int i=0; i<coins.size(); i++) {
            
            int coin = coins[i];
            
            // solve only when remainder of the amount is positive
            if( amt - coin >= 0 ) {
                dp[amt] = getMin(dp[amt], 1 + dp[amt-coin]);
            }
        }
    }
    
    return (dp[amount] < amount+1) ? dp[amount] : -1;
}


int main() {

    int n, c;
    cout<<"Enter number of coins: ";
    cin>>n;

    vector<int> coins;
    cout<<"Enter coin values: "<<endl;
    for(int i=0; i<n; i++) {
        cin>>c;
        coins.push_back(c);
    }

    int amount;
    cout<<"Enter total amount: ";
    cin>>amount;

    int res = coinChange(coins, amount);
    if(res==-1)
        cout<<"Exact change not possible";
    else
        cout<<"Minimum number of coin change: "<<res<<endl;
    
    return 0;
}