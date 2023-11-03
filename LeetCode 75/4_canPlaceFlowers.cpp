#include<iostream>
#include<vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if(n==0) return true;

    for(int i=0; i<flowerbed.size(); i++){
        if(flowerbed[i] == 0 && (i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0)){
            flowerbed[i] = 1;
            n--;
        }
        if(n==0) return true;
    }
    return false;
}

int main() {

    vector<int> flowerbed = {1,0,0,0,1};
    int n = 1;

    if(canPlaceFlowers(flowerbed, n))
        cout<<"Can place when n = "<<n<<endl;
    else
        cout<<"Cannot place when n = "<<n<<endl;

    n = 2;
    if(canPlaceFlowers(flowerbed, n))
        cout<<"Can place when n = "<<n<<endl;
    else
        cout<<"Cannot place when n = "<<n<<endl;
    
    return 0;
}