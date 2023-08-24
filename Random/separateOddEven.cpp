#include<iostream>
#include<vector>
using namespace std;

int minMoves(vector<int> arr) {

    int left, right, moves;
    left = 0;
    right = arr.size();
    moves = 0;

    while(left < right) {
        // odd character found on the left
        if ( arr[left]%2 != 0){

            // search for the first position from right with a odd number 
            while( right > left && arr[right]%2 != 0 ){
                --right;
            }

            // valid position for swap
            if( right > left) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;

                // decrement right
                --right;
                // increment moves
                ++moves;
            }
        }

        // increment left
        ++ left;
    }
    return moves;
}

int main() {

    vector<int> arr = {1,2,4,6,8,10,11,12,14,16,18,20,21};
    
    cout<<"Minimum number of moves required to separate odd and even: "<<minMoves(arr);

    return 0;
}