#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}; 
};


// using floyd's algorithm to detect start of the cycle
ListNode *detectCycle(ListNode *head) {
    if(!head) return NULL;

    ListNode *fast = head, *slow = head;
    int cycle_found = 0;
    
    while(fast->next && fast->next->next && slow->next){
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast==slow){
            cycle_found = 1;
            break;
        }
    }
    
    if(cycle_found){
        ListNode *p = head;
        ListNode *q = fast;
        while(p!=q){
            p = p->next;
            q = q->next;            
        }
        return p;
    }
    else {
        return NULL;
    }
}

ListNode *createLinkedListWithCycle(){
    ListNode *head;
    ListNode *cycleNode;

    head = new ListNode(5);
    ListNode *p = head;

    // add 5 nodes to the list
    int n=4;
    while(n>=0){
        p->next = new ListNode(n);
        p = p->next;
        --n;
    }

    cycleNode = p;

    // add another 3 nodes
    n = 3;
    while(n>0){
        p->next = new ListNode(n);
        p = p->next;
        --n;
    }

    p->next = cycleNode;
    return head;
}

ListNode *createLinkedListWithoutCycle(){
    ListNode *head = new ListNode(5);
    ListNode *p = head;

    // add 10 nodes to the list
    int n=9;
    while(n>=0){
        p->next = new ListNode(n);
        p = p->next;
        --n;
    }
    p->next = NULL;
    return head;
}

int main(){
    ListNode *head_1 = createLinkedListWithCycle();
    ListNode *c = detectCycle(head_1);
    if(c)
        cout<<"Linked list 1 has a loop at node "<<c->val<<endl;
    else
        cout<<"Linked list 1 does not have a loop"<<endl;


    ListNode *head_2 = createLinkedListWithoutCycle();
    ListNode *d = detectCycle(head_2);
    if(d)
        cout<<"Linked list 2 has a loop at node "<<c->val<<endl;
    else
        cout<<"Linked list 2 does not have a loop"<<endl;
    
    return 0;
}
