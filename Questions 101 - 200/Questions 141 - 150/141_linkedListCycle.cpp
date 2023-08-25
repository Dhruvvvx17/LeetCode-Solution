#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}; 
};

bool hasCycle(ListNode *head) {
    if(!head) return false;
    
    ListNode *slow = head;
    ListNode *fast = head;
    
    while(slow->next && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow==fast) return true;
    }
    
    return false;
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
    if(hasCycle(head_1))
        cout<<"Linked list 1 has a loop"<<endl;
    else
        cout<<"Linked list 1 does not have a loop"<<endl;


    ListNode *head_2 = createLinkedListWithoutCycle();
    if(hasCycle(head_2))
        cout<<"Linked list 2 has a loop"<<endl;
    else
        cout<<"Linked list 2 does not have a loop"<<endl;
    
    return 0;
}
