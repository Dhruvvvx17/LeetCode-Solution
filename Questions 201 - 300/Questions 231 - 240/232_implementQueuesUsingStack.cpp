#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
    
    stack<int> main, helper;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(main.size()) {
            helper.push(main.top());
            main.pop();
        }
        main.push(x);
        while(helper.size()) {
            main.push(helper.top());
            helper.pop();
        }
        cout<<"Pushed "<<x<<endl;
    }
    
    int pop() {
        int x = main.top();
        main.pop();
        cout<<"Popped "<<x<<endl;
        return x;
    }
    
    int peek() {
        cout<<"Peeked "<<main.top()<<endl;
        return main.top();
    }
    
    bool empty() {
        return (main.size() == 0) ? true : false;
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(2);
    obj->push(3);
    obj->push(4);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    obj->push(5);
    int param_5 = obj->peek();
    return 0;
}
