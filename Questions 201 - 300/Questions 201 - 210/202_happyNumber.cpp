#include<iostream>
using namespace std;

// happy number is when sum of digits squared adds upto 1 at some point.
// eg - 
// 19 -> 1^2 + 9^2 = 82
// 82 -> 8^2 + 2^2 = 68
// 68 -> 6^2 + 8^2 = 100
// 100 -> 1^2 + 0^2 + 0^2 = 1 -> Happy Number

int generateNext(int n) {
    int res = 0;
    int rem;
    while(n>0) {
        rem = n % 10;
        res += (rem * rem);
        n = n / 10;
    }
    return res;
}

bool isHappy(int n) {
    int slow=n, fast=n;
    do {
        slow = generateNext(slow);
        fast = generateNext(fast);
        fast = generateNext(fast);
    } while(slow != fast);
    if(slow==1) return true;
    return false;
}

int main() {
    int n;
    cout<<"Enter n value: ";
    cin>>n;

    if(isHappy(n))
        cout<<n<<" is a happy number";
    else
        cout<<n<<" is not a happy number";

    return 0;
}