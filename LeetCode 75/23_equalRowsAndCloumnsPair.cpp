#include<iostream>
#include<vector>
#include<map>
using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    map<vector<int>, int> cache;

    for(int i=0 ; i<n; i++){
        cache[grid[i]]++;
    }

    int res = 0;

    for(int i=0; i<n; i++){
        vector<int> col;
        for(int j=0; j<n; j++){
            col.push_back(grid[j][i]);
        }
        res += cache[col];
    }

    return res;
}

int main() {

    vector<vector<int>> grid = {{3,2,1}, {1,7,6}, {2,7,7}};

    cout<<"Number of equal pairs: "<<equalPairs(grid);
    
    return 0;
}