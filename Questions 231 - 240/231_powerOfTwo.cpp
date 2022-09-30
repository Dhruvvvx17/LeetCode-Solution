#include<iostream>
#include<vector>
using namespace std;

bool isPowerOfTwo(int n) {
    return (n>0) && !(n & n-1);
}

int main() {

    int n;

    cout<<"Enter n value: ";
    cin>>n;

    if(isPowerOfTwo(n))
        cout<<n<<" is a power of 2";
    else
        cout<<n<<" is not a power of 2";
    
    return 0;
}