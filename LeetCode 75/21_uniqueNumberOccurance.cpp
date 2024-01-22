#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> count;
    unordered_set<int> temp;

    for(int x: arr) count[x]+=1;
    for(auto it: count) temp.insert(it.second);

    return temp.size() == count.size();
}

int main() {

    vector<int> arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

    if(uniqueOccurrences(arr))
        cout<<"True";
    else
        cout<<"False";
    
    return 0;
}