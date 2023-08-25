#include<iostream>
#include<vector>
using namespace std;

int res;

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
        res += 1;
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


int countNQueens(int n) {
    
    vector<string> board(n, string (n,'.'));
    
    DFS(board, 0);        
    
    return res;
}


int main() {

    int n;
    cout<<"Enter board size (n): ";
    cin>>n;

    int res = countNQueens(n);    

    cout<<"Possible solutions for "<<n<<"x"<<n<<" board: "<<res<<endl;

    return 0;
}