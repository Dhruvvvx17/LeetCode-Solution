#include<iostream>
#include<vector>
using namespace std;

void dfs(int i, int j, vector<vector<char>> &board, int rows, int cols){
    if(i < 0 || i == rows || j < 0 || j == cols)
        return;

    if(board[i][j] == 'O'){
        board[i][j] = 'T';
        dfs(i+1, j, board, rows, cols);
        dfs(i, j+1, board, rows, cols);
        dfs(i-1, j, board, rows, cols);
        dfs(i, j-1, board, rows, cols);
        return;
    }
}


void solve(vector<vector<char>>& board) {
    int rows = board.size();
    int cols = board[0].size();

    // convert all safe O's to T's
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(i == 0 || i == rows-1 || j == 0 || j == cols-1)
                dfs(i, j, board, rows, cols);
        }
    }

    // convert all other O's to X's and T's to O's
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(board[i][j] == 'T')
                board[i][j] = 'O';
        }
    }
}

int main(){

    vector<vector<char>> board = {
        {'O', 'X', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'X'},
    };

    solve(board);

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}