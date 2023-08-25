#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> &arr, int start, int end){
    if(start == end)
        return start;
    
    int mid = (start+end)/2;

    if(arr[mid]>arr[mid+1])
        return search(arr, start, mid);
    else
        return search(arr, mid+1, end);
}

int findPeak(vector<int>& arr) {
    return search(arr, 0, arr.size()-1);
}

int main() {
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int> arr;

    cout<<"Enter the array elements: ";
    int ele;
    for(int i=0; i<n; i++){
        cin>>ele;
        arr.push_back(ele);
    }

    int index = findPeak(arr);

    cout<<"Peak is at index: "<<index;
    return 0;
}