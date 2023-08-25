#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int m, int n) {
    
    vector<int> old_row(n, 1);
    
    // iterate over all rows
    for(int i=0; i<m-1; i++){
        vector<int> new_row(n, 1);
        
        // iterate over all columns right to left
        for(int j=n-2; j>=0; --j) {
            new_row[j] = new_row[j+1] + old_row[j];
        }
        
        old_row = new_row;
    }
    return old_row[0];
}

int main() {

    int m,n;

    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of columns: ";
    cin>>n;

    cout<<"Number of unique paths = "<<uniquePaths(m,n);
    
    
    return 0;
}