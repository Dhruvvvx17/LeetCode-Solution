#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int res = nums[0];
    int n = nums.size();
    int l = 1, r = 1;
    
    for(int i=0; i<n; i++){
        l = l * nums[i];
        r = r * nums[n-i-1];
        
        res = max(res, max(l,r));
        if(l==0) l = 1;
        if(r==0) r = 1;
    }
    
    return res;
}

int max(int a, int b){
    return (a>b) ? a : b;
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr;
    int ele;
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Maximum product subarray: ";
    cout<<maxProduct(arr);
    return 0;
}