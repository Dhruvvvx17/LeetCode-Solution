#include<iostream>
#include<vector>
using namespace std;

vector<int> call(int n){
    if(n == 0) return vector<int>();
    vector<int> res = call(n-1);
    res.push_back(n);
    return res;
}

int main() {

    vector<int> res = call(5);
    
    for(int x:res){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}