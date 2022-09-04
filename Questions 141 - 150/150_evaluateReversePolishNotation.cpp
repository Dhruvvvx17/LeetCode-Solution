#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
    
    stack<int> stack;
    
    for(auto token: tokens) {
        
        if(token.size()>1 || isdigit(token[0])) stack.push(stoi(token));

        else {
            auto y = stack.top();
            stack.pop();
            auto x = stack.top();
            stack.pop();

            if(token[0] == '+') x = x + y;
            if(token[0] == '-') x = x - y;
            if(token[0] == '*') x = x * y;
            if(token[0] == '/') x = x / y;

            stack.push(x);
        }
    }

    return stack.top();
}

int main() {

    int n;
    string ele;
    cout<<"Enter number of tokens: ";
    cin>>n;

    vector<string> tokens;
    for(int i=0; i<n; i++) {
        cout<<"Enter token (number/operator): ";
        cin>>ele;
        tokens.push_back(ele);
    }

    cout<<"Solution of the expression: "<<evalRPN(tokens);

    return 0;
}