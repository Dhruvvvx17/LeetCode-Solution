#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}; 
};


ListNode* middleNode(ListNode* head) {
    ListNode *fast = head;
    ListNode *slow = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

ListNode *initList(){
    int val;
    cout<<"Enter head value: ";
    cin>>val;

    ListNode *h = new ListNode(val);
    ListNode *p = h;

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"Enter node "<<i+1<<": ";
        cin>>val;
        p->next = new ListNode(val);
        p = p->next;
    }
    p->next = NULL;

    return h;
}

int main(){
    ListNode *head = initList();

    cout<<"Inital list: ";
    for(ListNode *p=head; p!=NULL; p=p->next){
        cout<<p->val<<" ";
    }
    cout<<endl;

    ListNode *mid = middleNode(head);

    cout<<"Middle node: "<<mid->val;
    
    return 0;
}