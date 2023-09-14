// given a number n, find the nth fibonacci number
// Time complexity without memoization = O(2^n) - n is the number
// Time complexity with memoization = O(2*n) - n is the number
#include<iostream>
#include<map>
using namespace std;

// cache for memoization
map<int, int> cache;

// without memoization
int fib(int n) {
    if(n <= 2) return 1;
    return fib(n-1) + fib(n-2);
}

// with memoization
int fib_memo(int n){
    if(cache.find(n) != cache.end()) return cache[n];

    if(n <= 2) return 1;

    int res = fib_memo(n-1) + fib_memo(n-2);
    cache[n] = res;
    return cache[n];
}

// integer overflow due to limited int size
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    // cout<<"The "<<n<<"th fibonacci number is: "<<fib(n);
    cout<<"The "<<n<<"th fibonacci number is: "<<fib_memo(n);

    return 0;
}