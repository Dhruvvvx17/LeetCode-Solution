#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}; 
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    ListNode *fast, *slow;
    fast = head;
    slow = head;
    
    // move fast pointer n times
    for(int i=0; i<n; i++){
        fast = fast->next;
    }
    
    // last node
    if(fast==NULL) {
        head = head->next;
        return head;        
    }
    
    while(fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    slow->next = slow->next->next;
    return head;
}

int main() {

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n;
    cout<<"Enter n value: ";
    cin>>n;

    head = removeNthFromEnd(head, n);

    cout<<"New List: ";
    ListNode* p = head;
    while(p != NULL){
        cout<<p->val<<" ";
        p = p->next;
    }

    return 0;
}