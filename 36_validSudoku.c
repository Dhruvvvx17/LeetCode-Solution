#include<stdio.h>
#include<stdlib.h>

void reset(int *visited){
    for(int i=0;i<=9;i++){
        visited[i] = 0;
    }
}

int isValidSudoku(char** board, int boardSize, int* boardColSize){
   
    int visited[10] = {0};
    int curr_num;
    
    //check every row
    for(int i=0;i<9;i++){
        reset(&visited);
        
        for(int j=0;j<9;j++){
            
            if(board[i][j]!='.'){
                curr_num = board[i][j]-'0';
                // repeated number
                if(visited[curr_num]) return 0;
                else visited[curr_num] = 1;
            }  
        }
    }

    
    //check column row
    for(int i=0;i<9;i++){
        reset(&visited);
        
        for(int j=0;j<9;j++){

            if(board[j][i]!='.'){
                curr_num = board[j][i]-'0';
                // repeated number
                if(visited[curr_num]) return 0;
                else visited[curr_num] = 1;
            }  
        }
    }
    
    //check every 3x3 block
    for(int r=0;r<9;r+=3){
        for(int c=0;c<9;c+=3){
            reset(&visited);
    
            for(int i=r;i<r+3;i++){
                for(int j=c;j<c+3;j++){

                    if(board[i][j]!='.'){
                        curr_num = board[i][j]-'0';
                        // repeated number
                        if(visited[curr_num]) return 0;
                        else visited[curr_num] = 1;
                    }
                }
            }
        }        
    }
    
    return 1;
}         

int main(int argc, char const *argv[])
{
    
    char **board = (char*)malloc(sizeof(char*)*9);
    for(int i=0;i<=9;i++)
        board[i] = (char*)malloc(sizeof(char*)*9);

    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            board[i][j] = '.';
        }
    }

    // Set random values of the board to sudoku values then pass the board to the function to check if it is valid

    return 0;
}
