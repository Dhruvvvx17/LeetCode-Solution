#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = 0;
    int c = matrix[0].size()-1;
    
    while( r < matrix.size() && c >= 0){
        if(matrix[r][c] == target)
            return true;
        else{
            if(matrix[r][c] < target)
                r++;
            else
                c--;
        }
    }
    return false;
}

int main() {

    int m, n, t;
    cout<<"Enter number of rows: ";
    cin>>m;

    cout<<"Enter number of cols: ";
    cin>>n;

    vector<vector<int>> matrix (m, vector<int> (n,0));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<<"Enter number (i:"<<i<<") (j:"<<j<<") ";
            cin>>t;
            matrix[i][j] = t;        
        }
    }

    int target;
    cout<<"Enter target element: ";
    cin>>target;

    if(searchMatrix(matrix, target))
        cout<<"Element found!";
    else
        cout<<"Element not found";

    return 0;
}