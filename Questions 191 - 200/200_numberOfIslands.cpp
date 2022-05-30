#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<vector<char>>& grid, int i, int j) {
    // check for boundaries
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
        return;
    
    // check for visited land or water
    if(grid[i][j]=='0' || grid[i][j]=='2')
        return;
    
    // new land, mark as visited
    grid[i][j] = '2';
        
    DFS(grid, i, j+1);
    DFS(grid, i, j-1);
    DFS(grid, i+1, j);
    DFS(grid, i-1, j);
}

int numIslands(vector<vector<char>>& grid) {

    int res = 0;
    
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].size(); j++) {
            if(grid[i][j] == '1') {
                DFS(grid, i, j);
                res++;
            }
        }
    }
    return res;        
}

int main() {
    int row, column;

    cout<<"Enter number of rows: ";
    cin>>row;

    cout<<"Enter number of columns: ";
    cin>>column;

    vector<vector<char>> grid(row);


    char x;
    for(int i=0; i<row; i++) {
        grid[i] = vector<char>(column);
        for(int j=0; j<column; j++) {
            cout<<"Land(1) or Sea(0) at position "<<i<<" "<<j<<": ";
            cin>>x;
            grid[i][j] = x;
        }
    }

    cout<<"Original map: "<<endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    int res = numIslands(grid);

    cout<<"Number of islands: "<<res;
    return 0;
}