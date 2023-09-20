// Given a mxn grid, how many ways can I go from the start (0,0) to the end (m,n) by just moving RIGHT or DOWN
// Time complexity = O(m*n)
// Space complexity = O(m*n)

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int64_t gridTraveller_tab(int rows, int cols){
    vector<vector<int64_t>> table (rows+1, vector<int64_t> (cols + 1, 0));

    // 0th row and 0th col will be populated with zeros
    // table[1][1] will be 1 as there is 1 way to reach destination on a 1x1 grid
    table[1][1] = 1;

    for(int i=0; i<=rows; i++){
        for(int j=0; j<=cols; j++){
            if(j+1 <= cols) table[i][j+1] += table[i][j];
            if(i+1 <= rows) table[i+1][j] += table[i][j];
        }
    }
    return table[rows][cols];
}

int main() {

    int m, n;
    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of cols: ";
    cin>>n;

    cout<<"Number of ways to travel from (1,1) to ("<<m<<","<<n<<") is: "<<gridTraveller_tab(m,n)<<endl;

    return 0;
}