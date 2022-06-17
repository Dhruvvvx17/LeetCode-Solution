#include<iostream>
#include<vector>
using namespace std;

class MyStack {
    vector<int> queue;
    vector<int> temp_queue;

public:    
    MyStack() {
        
    }
    
    void push(int x) {
        // enque - insert at the front
        queue.insert(queue.begin(), x);
    }
    
    int pop() {
        int n = queue.size(), x;
        for(int i=n-1; i>0; --i) {
            x = queue[i];
            queue.pop_back();                           // dequeue - remove from the main queue
            temp_queue.insert(temp_queue.begin(), x);   // enque - add in front of temporary queue
        }
        int pop = queue[0];
        queue.pop_back();

        // i = n-2 becuase -1 for zero indexed and another -1 as one element is popped
        for(int i=n-2; i>=0; --i) {
            x = temp_queue[i];
            temp_queue.pop_back();              // dequeue - remove from temporary queue
            queue.insert(queue.begin(), x);     // enque - add in front of main queue
        }
        
        return pop;
    }
    
    int top() {
        return queue[0];        
    }
    
    bool empty() {
        return (queue.size()==0) ? true : false;
    }
};

int main() {

    MyStack *stack = new MyStack();

    (stack->empty()) ? cout<<"Stack empty"<<endl : cout<<"Stack not empty"<<endl;
    
    stack->push(1);
    cout<<"Pushed 1"<<endl;

    stack->push(2);
    cout<<"Pushed 2"<<endl;

    stack->push(3);
    cout<<"Pushed 3"<<endl;

    cout<<"Stack top: "<<stack->top()<<endl;

    cout<<"Popped: "<<stack->pop()<<endl;

    cout<<"Popped: "<<stack->pop()<<endl;

    (stack->empty()) ? cout<<"Stack empty"<<endl : cout<<"Stack not empty"<<endl;

    cout<<"Popped: "<<stack->pop()<<endl;

    (stack->empty()) ? cout<<"Stack empty"<<endl : cout<<"Stack not empty"<<endl;

    return 0;
}