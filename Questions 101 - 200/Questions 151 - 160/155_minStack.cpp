#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    
    stack<int> actual_stack;
    stack<int> min_stack;
    
    MinStack() { }
    
    void push(int val) {
        actual_stack.push(val);

        if(min_stack.empty() || min_stack.top()>=val)
            min_stack.push(val);
    }
    
    void pop() {
        if(!actual_stack.empty()){
            if(actual_stack.top()==min_stack.top()){
                min_stack.pop();
            }
            actual_stack.pop();
        }
    }
    
    int top() {
        return actual_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

int main() {
    MinStack *obj = new MinStack();
    obj->push(5);
    cout<<"Stack top: "<<obj->top()<<endl;

    obj->push(2);
    obj->push(4);
    obj->push(-1);
    obj->push(7);

    cout<<"Stack top: "<<obj->top()<<endl;
    cout<<"Stack min: "<<obj->getMin()<<endl;

    obj->pop();
    obj->pop();

    cout<<"Stack top: "<<obj->top()<<endl;
    cout<<"Stack min: "<<obj->getMin()<<endl;

    return 0;
}