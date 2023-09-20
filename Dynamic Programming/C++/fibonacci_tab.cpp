// Given an integer n, find the nth fibonacci number using tabulation method.
// Time complexity: O(n)
// Space complexity: O(n)

#include<iostream>
#include<vector>
using namespace std;

int64_t fib_tab(int n){
    vector<int64_t> table (n+1, 0);
    table[0] = 0;
    table[1] = 1;

    for(int i=2; i<=n; i++){
        table[i] = table[i-1] + table[i-2];
    }
    return table[n];
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"The "<<n<<"th fibonacci number is: "<<fib_tab(n);

    return 0;
}