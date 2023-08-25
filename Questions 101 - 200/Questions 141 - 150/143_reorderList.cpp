#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    if((!head) || (!head->next) || (!head->next->next)) return;
    
    stack<ListNode*> temp_stack;
    
    // save all elements in stack
    ListNode *p = head;
    while(p){
        temp_stack.push(p);
        p = p->next;
    }
        
    // reset p to point to head
    p = head;
    int size = temp_stack.size();

    // fetch nodes from stack, insert stack top between two existing nodes of the list
    for(int i=0; i<=size/2; i++){
        ListNode *e = temp_stack.top();
        temp_stack.pop();
        e->next = p->next;
        p->next = e;
        p = p->next->next;
    }
    p->next = NULL;
}

ListNode *initList(){
    ListNode *head = new ListNode(1);

    int i=2;
    ListNode *p = head;
    while(i<=50){
        p->next = new ListNode(i);
        p = p->next;
        ++i;
    }
    p->next = NULL;

    return head;
}

int main(){
    ListNode *head = initList();

    cout<<"Inital list: ";
    for(ListNode *p=head; p!=NULL; p=p->next){
        cout<<p->val<<" ";
    }
    cout<<endl;

    reorderList(head);

    cout<<"Reordered list: ";
    for(ListNode *p=head; p!=NULL; p=p->next){
        cout<<p->val<<" ";
    }
    cout<<endl;
    
    return 0;
}