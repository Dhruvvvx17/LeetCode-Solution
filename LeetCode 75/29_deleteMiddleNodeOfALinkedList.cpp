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


ListNode* deleteMiddle(ListNode* head) {

    if(head->next == nullptr)
        return nullptr;

    if(head->next->next == nullptr) {
        head->next = nullptr;
        return head;
    }

    ListNode *slow, *fast, *p;

    slow = head;
    fast = head->next->next;

    while(fast->next != nullptr){
        if(fast->next->next == nullptr)
            fast = fast->next;
        else
            fast = fast->next->next;

        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
}

int main() {

    ListNode head = ListNode(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(3);
    head.next->next->next = new ListNode(4);
    head.next->next->next->next = new ListNode(5);
    
    ListNode *res = deleteMiddle(&head);

    ListNode *p = res;
    while(p != nullptr) {
        cout<<p->val<<" ";
        p = p->next;
    }
    
    return 0;
}
