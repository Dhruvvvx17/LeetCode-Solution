#include<iostream>
#include<vector>
using namespace std;

bool DFS(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int index, int i, int j, int rows, int cols) {
    
    // end of word check
    if(index == word.size())
        return true;
    
    // boundary check
    if( i<0 || j<0 || i>=rows || j>=cols ){
        return false;
    }
    
    if(visited[i][j]) {
        return false;
    }
    
    // if current position at board has the current character at string then DFS
    if(board[i][j] == word[index]){
                    
        visited[i][j] = 1;            
        
        bool left = DFS(board, visited, word, index+1, i, j-1, rows, cols);
        bool right = DFS(board, visited, word, index+1, i, j+1, rows, cols);
        bool up = DFS(board, visited, word, index+1, i-1, j, rows, cols);
        bool down = DFS(board, visited, word, index+1, i+1, j, rows, cols);
        
        visited[i][j] = 0;

        if(left || right || up || down)
            return true;
        else {
            return false;
        }
    }
    return false;
}


bool exist(vector<vector<char>>& board, string word) {
    
    int rows, cols, index;
    rows = board.size();
    cols = board[0].size();
    index = 0;
    
    vector<vector<int>> visited (rows, vector<int>(cols, 0));
    
    bool res = false;
    
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++){
            res = DFS(board, visited, word, index, i, j, rows, cols);
            if(res)
                return true;
        }
    }
    
    return false;
}

int main() {

    vector<vector<char>> board
    {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    
    string word = "ABCCED";

    if(exist(board, word))
        cout<<word<<" exists in board"<<endl;
    else
        cout<<word<<" does not exists in board"<<endl;
    return 0;
}