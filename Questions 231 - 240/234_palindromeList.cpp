#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    
ListNode* reverse(ListNode *head) {
    
    // 0 nodes
    if(!head) return NULL;
    
    // 1 node
    if(!head->next) return head;
    
    // 2 nodes
    if(!head->next->next) {
        head->next->next = head;
        head = head->next;
        head->next->next = NULL;
        return head;
    }
    
    // 3 or more nodes
    ListNode *prev = head, *curr = prev->next, *fwd = curr->next;
    prev->next = NULL;
    while(fwd){
        curr->next = prev;
        prev = curr;
        curr = fwd;
        fwd = fwd->next;
    }
    curr->next = prev;
    return curr;
}

bool isPalindrome(ListNode* head) {
    
    if(!head) return false;
    
    if(!head->next) return true;
    
    ListNode *slow = head, *fast = head, *pre_slow = head;
    
    // iterate with slow and fast
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        pre_slow = slow;
        slow = slow->next;
    }
    
    // reverse second half of list
    pre_slow->next = reverse(slow);
    
    ListNode *l1 = head, *l2 = pre_slow->next;
    
    while(l1 != pre_slow->next) {
        if(l1->val != l2->val)
            return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    return true;
}

int main() {

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if(isPalindrome(head))
        cout<<"Palindrome!";
    else
        cout<<"Not a palindrome!";

    return 0;
}