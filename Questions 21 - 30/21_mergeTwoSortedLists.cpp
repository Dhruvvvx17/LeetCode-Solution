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


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    ListNode *dummy = new ListNode(-1);
    
    ListNode *p = list1, *q = list2, *r = dummy;
    
    while(p!=nullptr && q!=nullptr) {
        if(p->val < q->val) {
            r->next = p;
            p = p->next;
            r = r->next;
        }
        else {
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    
    if(p != nullptr) {
        r->next = p;
    }
    
    if(q != nullptr) {
        r->next = q;
    }
    
    return dummy->next;
}

int main() {

    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);
    
    ListNode *head2 = new ListNode(2);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(6);


    ListNode *res = mergeTwoLists(head1, head2);

    cout<<"Merged list: ";
    for(ListNode *p = res; p != nullptr; p = p->next)
        cout<<p->val<<" ";
    cout<<endl;


    ListNode *p, *q;
    p = res;
    q = p->next;

    while(q != nullptr){
        free(p);
        p = q;
        q = q->next;
    }
    free(p);

    return 0;
}