#include<iostream>
#include<vector>
using namespace std;

bool validate(vector<vector<char>>& board, int i, int j, char val) {
    int row, column;
    row = i - i%3;
    column = j - j%3;
    
    // validate row
    for(int x=0; x<9; x++) if(board[i][x] == val) return false;
    
    // validate column
    for(int y=0; y<9; y++) if(board[y][j] == val) return false;
    
    // validate 3x3 square
    for(int x=row; x<row+3; x++) {
        for(int y=column; y<column+3; y++) {
            if(board[x][y] == val) return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>& board, int i, int j) {

    // rows go from 0 -> 8, 9th row would mean board has been solved
    if(i == 9) return true;
    
    // columns go from 0 -> 8, 9th column would mean current row is solved, go to next row
    if(j == 9) return solve(board, i+1, 0);

    if(board[i][j] != '.') return solve(board, i, j+1);

    // c is all possible digits 1 -> 9
    for(char c='1'; c<='9'; c++) {
        
        if(validate(board, i, j, c)) {
            board[i][j] = c;
            if(solve(board, i, j+1)) return true;
            board[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board, 0, 0);
}

int main() {

    // create a 9 x 9 sudoku with all positions initially blank
    vector<vector<char>> board (9, vector<char>(9, '.'));
    int val;

    cout<<"Blank sudoku: "<<endl;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout<<"Value at position row = "<<i<<" column = "<<j<<" (To leave it blank enter -1): ";
            cin>>val;
            if( val >= 1 and val <= 9)
                board[i][j] = '0' + val;
        }
    }

    cout<<"Initial sudoku: "<<endl;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    solveSudoku(board);

    cout<<"Solved sudoku: "<<endl;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}