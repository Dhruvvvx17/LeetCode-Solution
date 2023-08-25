#include<iostream>
#include<map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    
    if(!head) return head;
    
    map<Node*, Node*> myMap;
    Node *p = head;
    while(p!=NULL){
        myMap[p] = new Node(p->val);
        p = p->next;
    }
    
    Node *q = head;
    while(q!=NULL){
        myMap[q]->next = myMap[q->next];
        myMap[q]->random = myMap[q->random];
        q = q->next;
    }

    return myMap[head];
}

Node* initList(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->random = head->next->next->next;
    head->next->random = head->next->next;
    head->next->next->random = head->next;
    head->next->next->next->random = head;

    return head; 
}

void printList(Node *head){
    Node *p = head;
    while(p!=NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    Node *head = initList();
    cout<<"List 1: ";
    printList(head);

    Node *newHead = copyRandomList(head);
    cout<<"List 2: ";
    printList(newHead);

    return 0;
}