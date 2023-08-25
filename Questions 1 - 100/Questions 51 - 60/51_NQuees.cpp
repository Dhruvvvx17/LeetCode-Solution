#include<iostream>
#include<vector>
using namespace std;

vector<vector<string>> res;

bool checkValid(vector<string>& board, int row, int col) {
    
    // check column
    for(int x = row; x>=0; --x)
        if(board[x][col] == 'Q') return false;
    
    
    // check left diagonal
    for(int x = row, y=col; x>=0 && y>=0; --x, --y) {
        if(board[x][y] == 'Q') return false;
    }
    
    // check right diagonal
    for(int x = row, y = col; x>=0 && y<board.size(); --x, ++y) {
        if(board[x][y] == 'Q') return false;
    }
    
    return true;
}

void DFS(vector<string>& board, int row) {
    
    if(row == board.size()) {
        res.push_back(board);
        return;
    }
    
    for(int i = 0; i<board.size(); i++) {
        if(checkValid(board, row, i)) {
            
            board[row][i] = 'Q';
            
            DFS(board, row+1);
            
            board[row][i] = '.';
        }            
    }
    return;
}


vector<vector<string>> solveNQueens(int n) {
    
    vector<string> board(n, string (n,'.'));
    
    DFS(board, 0);        
    
    return res;
}


int main() {

    vector<vector<string>> res = solveNQueens(4);    
    
    for(int i=0; i<res.size(); i++){
        cout<<"Solution "<<i+1<<": "<<endl;
        for(int j=0; j<res[1].size(); j++){
            cout<<res[i][j]<<endl;
        }
        cout<<endl;
    }

    return 0;
}