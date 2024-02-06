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

ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;

    if(head->next->next == nullptr){
        head->next->next = head;
        head = head->next;
        head->next->next = nullptr;
        return head;
    }

    ListNode *p, *q, *r;
    p = head;
    q = head->next;
    r = head->next->next;

    // first node becomes last
    p->next = nullptr;

    while(r!=nullptr){
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

    ListNode head = ListNode(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(3);
    head.next->next->next = new ListNode(4);
    head.next->next->next->next = new ListNode(5);
    
    ListNode *res = reverseList(&head);

    ListNode *p = res;
    while(p != nullptr) {
        cout<<p->val<<" ";
        p = p->next;
    }

    return 0;
}