#include<iostream>
#include<vector>
using namespace std;

int original;

int guess(int g){
    if(g==original)
        return 0;
    else if(g>original)
        return -1;
    else
        return 1;
}


int guessNumber(int n) {
    int start = 1;
    int end = n;
    int res = -1;

    while(1){
        // int g = int((std::int64_t(start) + std::int64_t(end)) / 2);  // overflow
        int g = (end-start)/2 + start;

        if(guess(g) == 0){
            res = g;
            break;
        }

        else if(guess(g) == 1){
            start = g+1;
        }

        else{
            end = g;
        }
        cout<<"New guess: "<<g<<endl;
    }
    return res;
}

int main() {

    int n;
    cout<<"Enter range (0-n): ";
    cin>>n;

    cout<<"Enter original number: ";
    cin>>original;

    int res = guessNumber(n);
    cout<<"Your number: "<<res;

    return 0;
}