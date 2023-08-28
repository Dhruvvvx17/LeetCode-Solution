#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int val){
    int l = 0;
    int r = arr.size();
    int res = -1;

    while(l <= r){
        int mid = l + (r - l)/2;

        if(arr[mid] >= val){
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return res;
}


bool valid(vector<int>& arr, int position){
    int firstOccurance = binarySearch(arr, arr[position]);

    if(arr[firstOccurance] == arr[firstOccurance + arr.size()/4])
        return true;
    return false;
}

int findSpecialInteger(vector<int>& arr) {
    int n = arr.size();
    int first = n/4;
    int second = n/2;
    int third = 3 * n/4;

    if(valid(arr, first)) return arr[first];
    else if(valid(arr, second)) return arr[second];
    else return arr[third];
}

int main() {

    int n, t;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr;

    for(int i=0; i<n; i++){

        cout<<"Enter element "<<i<<": ";
        cin>>t;

        arr.push_back(t);
    }

    cout<<"Special integer appearing more than 25% is : "<<findSpecialInteger(arr);
    
    return 0;
}