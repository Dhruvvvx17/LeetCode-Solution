#include<iostream>
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
    
    if(!head)
        return nullptr;

    Node *p = head;
    // first pass - create clones assign them to original->next
    while(p){
        Node *newNode = new Node(p->val);
        newNode->next = p->next;
        newNode->random = nullptr;
        p->next = newNode;
        p = newNode->next;
    }

    p = head;
    // second pass - assign random to clones
    while(p){
        if(p->random){
            p->next->random = p->random->next;
        } else {
            p->next->random = nullptr;
        }
        p = p->next->next;
    }

    // main iterator
    p = head;

    // secondary original iterator
    Node *originals = p;
    // secondary clone iterator
    Node *clones = p->next;

    // pointer to the cloned list
    Node *res = clones;
    p = p->next;

    // third pass - fix next pointers for clones
    while(p){
        originals->next = p->next;
        p = p->next;

        if(p){
            clones->next = p->next;
            p = p->next;
        } else {
            clones->next = nullptr;
        }

        // update following pointers
        originals = originals->next;
        clones = clones->next;
    }

    return res;
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