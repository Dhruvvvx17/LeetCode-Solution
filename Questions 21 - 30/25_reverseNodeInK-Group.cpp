// draw and verify, kind of difficult to visualize

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

ListNode* reverseKGroup(ListNode* head, int k) {

    if(k==1) return head;

    ListNode *dummy = new ListNode();
    dummy->next = head;
    
    ListNode *before, *after, *prev, *curr, *next;
    before = dummy;
    after = head;
    prev = nullptr;
    curr = nullptr;
    next = nullptr;
    
    while(true) {
        
        ListNode *cursor = after;
        for(int i=0; i<k; i++) {                
            if(cursor == nullptr) return dummy->next;
            cursor = cursor->next;
        }
        
        prev = before;
        curr = after;
        
        for(int i=0; i<k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        before->next = prev;
        after->next = curr;
        before = after;
        after = curr;
    }
}

int main() {

    int n, temp, k;
    cout<<"Enter number of nodes: ";
    cin>>n;

    ListNode *dummyHead = new ListNode();
    ListNode *p = dummyHead;

    for(int i=0; i<n; i++) {
        cout<<"Enter node "<<i<<" value: ";
        cin>>temp;
        p->next = new ListNode(temp);
        p = p->next;
    }
    ListNode *head = dummyHead->next;
    free(dummyHead);

    cout<<"Enter k value for groups: ";
    cin>>k;

    cout<<"Original List: ";
    for(p = head; p != nullptr; p = p->next){
        cout<<p->val<<" ";
    }
    cout<<endl;

    head = reverseKGroup(head, k);

    cout<<"New List: ";
    for(p = head; p != nullptr; p = p->next){
        cout<<p->val<<" ";
    }
    cout<<endl;

    // free memory
    ListNode *q;
    for(p = head; p != nullptr; ){
        q = p;
        p = p->next;
        free(q);
    }

    cout<<"Memory released"<<endl;

    return 0;
}