#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
        
    // NULL or only head
    if(!head || !head->next)
        return head;
    
    // 2 nodes
    if(head->next->next == NULL) {
        head->next->next = head;
        head = head->next;
        head->next->next = NULL;
        return head;
    }
    
    // 3 nodes or more
    ListNode *p, *q, *r;
    p = head;
    q = head->next;
    r = head->next->next;

    // set next of first node to NULL
    p->next = NULL;
    
    while(r!= NULL){
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    head = q;
    
    return head;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *p = head;
    cout<<"Original linked list: ";
    while(p != NULL) {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;

    p = reverseList(head);

    cout<<"Reversed linked list: ";
    while(p != NULL) {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;

    return 0;
}