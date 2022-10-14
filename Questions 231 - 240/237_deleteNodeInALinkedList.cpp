#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    
    ListNode *p = node;
    p->val = p->next->val;
    p->next = p->next->next;
    return;
}

int main(){

    ListNode *p = new ListNode(5);
    ListNode *q = p;
    q->next = new ListNode(10);
    q = q->next;
    q->next = new ListNode(15);
    q = q->next;
    ListNode *r = q;
    q->next = new ListNode(20);
    q = q->next;
    q->next = new ListNode(25);
    q = q->next;

    for(q=p; q!=NULL; q = q->next){
        cout<<q->val<<" ";
    }
    cout<<endl;

    deleteNode(r);

    for(q=p; q!=NULL; q = q->next){
        cout<<q->val<<" ";
    }
    cout<<endl;


    return 0;
}