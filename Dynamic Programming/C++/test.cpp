// understanding recursive function calls

#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<vector<int>> gloablRes;

map<int, vector<int>> cache;

vector<int> recursive(int n){

    cout<<n<<endl;

    if(n==0) return {};

    if(n < 0) return {-1};

    if(cache.find(n) != cache.end()) return cache[n];

    vector<int> left = recursive(n-1);
    vector<int> right = recursive(n-2);
    cout<<"Left: ";
    for(int x: left){
        cout<<x<<" ";
    }
    cout<<endl;    


    vector<int> res = {};

    // both subtrees returned -1 (no solution possible from current node)
    if((!left.empty() && left[0] == -1) && (!right.empty() && right[0] == -1))
        res.push_back(-1);

    // solution possible from current node
    else{
        // check if left branch has a solution
        if(left.empty() || left[0] != -1)
            res.insert(res.end(), left.begin(), left.end());
        // check if right branch has a solution
        if(right.empty() || right[0] != -1)
            res.insert(res.end(), right.begin(), right.end());
        // push current element into res
        res.push_back(n);
    }
    

    cout<<"In loop: ";
    for(int x: res){
        cout<<x<<" ";
    }
    cout<<endl;    

    // save current state in global variable
    cache[n] = res;
    return res;
}

int main() {

    vector<int> res;
    res = recursive(5);

    cout<<"In res: ";
    for(int x: res){
        cout<<x<<" ";
    }
    cout<<endl;

    for(auto p: cache){
        cout<<"Number: "<<p.first<<" Value: ";
        for(int x: p.second){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}