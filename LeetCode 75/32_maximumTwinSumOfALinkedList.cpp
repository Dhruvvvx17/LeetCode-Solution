#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int pairSum(ListNode* head) {

    if(head == nullptr) return 0;

    if(head->next == nullptr) return head->val;

    if(head->next->next == nullptr) return head->val + head->next->val;

    // break list into two halves
    ListNode *slow = head, *fast = head->next->next;

    while(fast!=nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *revList = slow->next;
    slow->next = nullptr;

    // 2 nodes is the revList (2nd half)
    if(revList->next->next == nullptr) {
        revList->next->next = revList;
        revList = revList->next;
        revList->next->next = nullptr;
    } else {
        ListNode *p, *q, *r;
        p = revList;
        q = revList->next;
        r = revList->next->next;

        p->next = nullptr;
        while(r != nullptr) {
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        revList = q;
    }

    int res = 0;
    ListNode *x = head;
    ListNode *y = revList;

    while(x != nullptr || y != nullptr){
        res = max(res, x->val + y->val);
        x = x->next;
        y = y->next;
    }

    return res;
}

int main() {

    ListNode head = ListNode(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(3);
    head.next->next->next = new ListNode(9);
    head.next->next->next->next = new ListNode(5);
    head.next->next->next->next->next = new ListNode(9);
    
    int value = pairSum(&head);

    cout<<value;

    return 0;
}