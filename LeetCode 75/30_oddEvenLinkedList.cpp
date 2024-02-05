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

ListNode* oddEvenList(ListNode* head) {
    // edge case - 0, 1 or 2 nodes
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return head;

    ListNode *odd = head, *even = head->next;
    ListNode *p = odd, *q = even;

    while(p->next != nullptr && q->next != nullptr){
        p->next = q->next;
        p = p->next;
        q->next = p->next;
        q = q->next;
    }

    p->next = even;

    return head;
}

int main() {

    ListNode head = ListNode(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(3);
    head.next->next->next = new ListNode(4);
    head.next->next->next->next = new ListNode(5);
    
    ListNode *res = oddEvenList(&head);

    ListNode *p = res;
    while(p != nullptr) {
        cout<<p->val<<" ";
        p = p->next;
    }

    return 0;
}