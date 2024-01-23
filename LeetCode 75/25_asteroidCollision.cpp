#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> asteroidCollision(vector<int>& ast) {
    stack<int> s;

    // positive -> right
    // negative -> left

    for(int i=0; i<ast.size(); i++){
        // empty stack
        if(s.empty()) s.push(ast[i]);

        // stack top going left - no collision possible
        else if(s.top()<0){
            s.push(ast[i]);
        }

        // stack top going right
        else {
        // new ast going left
            if(ast[i] < 0) {
                bool destroyed = false;
                while(!s.empty() && s.top() > 0 && !destroyed) {
                    if(abs(s.top()) < abs(ast[i])) s.pop();
                    else if(s.top() == -ast[i]) {
                        s.pop(); 
                        destroyed = true;
                    }
                    else destroyed = true;
                }
                if(!destroyed) s.push(ast[i]);
            }
            // new ast also going right
            else {
                s.push(ast[i]);
            }
        }
    }

    vector<int> res;
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}

int main() {

    vector<int> ast = {5,10,-5};

    vector<int> res = asteroidCollision(ast);

    cout<<"Final asteroids: ";
    for(auto x: res){
        cout<<x<<" ";
    }

    return 0;
}