#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k){

    if(head==NULL || k==0)
        return head;
    
    struct ListNode *p = head, *q, *r;
    int count = 1;
    while(p->next != NULL){
        p = p->next;
        count += 1;
    }
        
    if(count==k)
        return head;
    else
        k = k%count;
    
    if(k==0)
        return head;
    
    p->next = head;
    p = head;
    q = head;
    r = head;
    
    for(int i=0;i<k;i++){
        p = p->next;        
    }

    while(p!=head){
        p = p->next;
        r = q;
        q = q->next;
    }
    
    head = q;
    r->next = NULL;
    
    return head;
}

int main(int argc, char const *argv[])
{
    //create a list and input a k value
    return 0;
}
