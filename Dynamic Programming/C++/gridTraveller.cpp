// Given a mxn grid, how many ways can I go from the start (0,0) to the end (m,n) by just moving RIGHT or DOWN
// Time Complexity without memoization O(2 ^ (m+n))
// Time Complexity with memoization O(m*n) - m = no. of rows and n = no. of columns
#include<iostream>
#include<map>
using namespace std;

// memoization
map<string, int64_t> cache;

int64_t gridTraveller(int64_t m, int64_t n){
    string key = to_string(m) + "_" + to_string(n);
    if(cache.find(key) != cache.end()) return cache[key];

    // edge cases
    if(m==1 && n==1) return 1;
    if(m==0 || n==0) return 0;  // non-existant grid

    cache[key] = gridTraveller(m-1, n) + gridTraveller(m, n-1);
    return cache[key];
}


int main() {

    int64_t m, n;
    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of cols: ";
    cin>>n;

    cout<<"Number of ways to travel from (1,1) to ("<<m<<","<<n<<") is: "<<gridTraveller(m,n)<<endl;

    // for(const auto& pair: cache){
    //     cout<<pair.first<<" : "<<pair.second<<endl;
    // }

    return 0;
}