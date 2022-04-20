#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) return NULL;
    
    ListNode* p1 = headA;
    ListNode* p2 = headB;
            
    while( p1 && p2 && p1!=p2 ){
        p1 = p1->next;
        p2 = p2->next;
        
        if(p1==p2) return p1;
        
        if(p1==NULL) p1 = headB;
        if(p2==NULL) p2 = headA;
    }
    return p1;
}

int main(){
    ListNode *list1 = new ListNode(5);
    ListNode *p = list1;
    ListNode *intersection;
    p->next = new ListNode(10);
    p = p->next;
    intersection = new ListNode(15);
    p->next = intersection;
    p = p->next;
    p->next = new ListNode(20);
    p = p->next;
    p->next = NULL;


    ListNode *list2 = new ListNode(1);
    ListNode *q = list2;
    q->next = new ListNode(2);
    q = q->next;
    q->next = new ListNode(3);
    q = q->next;
    q->next = new ListNode(4);
    q = q->next;
    q->next = intersection;

    ListNode *res = getIntersectionNode(list1, list2);

    int x = 1;
    p = list1;
    while(p!=res){
        p = p->next;
        x+=1;
    }

    cout<<"Intersection point is at node: "<<x;
    return 0;
}