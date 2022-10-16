#include<iostream>
#include<vector>
using namespace std;

// bool isBadVersion(int version);
vector<bool> softwareBuild;

bool isBadVersion(int version) {
    return softwareBuild[version];
}

int firstBadVersion(int n) {
    int start = 1;
    int end = n;
    int mid, res;
    while(start <= end) {
        mid = start + (end-start)/2;
        
        // returns true
        if(isBadVersion(mid)) {
            res = mid;
            end = mid - 1;
        }
        // returns false
        else {
            start = mid + 1;
        }
    }
    return res;
}

int main() {

    int n, bad;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"Enter first bad version: ";
    cin>>bad;

    softwareBuild.push_back(false);

    for(int i=1; i<bad; i++){
        softwareBuild.push_back(false);
    }

    for(int i=bad; i<=n; i++){
        softwareBuild.push_back(true);
    }

    int res = firstBadVersion(n);

    cout<<"First bad version is: "<<res;

    return 0;
}
