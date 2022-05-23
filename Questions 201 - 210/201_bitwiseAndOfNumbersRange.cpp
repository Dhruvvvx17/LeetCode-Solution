#include<iostream>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int count = 0;
    while(left != right) {
        left = left>>1;
        right = right>>1;
        count++;
    }
    return left<<count;
}

int main() {
    int left, right;

    cout<<"Enter range start: ";
    cin>>left;
    cout<<"Enter range end: ";
    cin>>right;

    cout<<"Bitwise AND of range: "<<rangeBitwiseAnd(left, right);
    return 0;
}