#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *newListHead, *p, *q, *r;
    
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    
    p = l1;
    q = l2;
    
    // For the first node
    if(p->val < q->val){
        newListHead = p;
        r = newListHead;
        p = p->next;
    }
    else{
        newListHead = q;
        r = newListHead;
        q = q->next;
    }
    
    
    while(p!=NULL && q!=NULL){
        if(p->val < q->val){
            r->next = p;
            p = p->next;
            r = r->next;
        }
        else{
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    
    while(p!=NULL){
        r->next = p;
        p = p->next;
        r = r->next;
    }

    while(q!=NULL){
        r->next = q;
        q = q->next;
        r = r->next;
    }
    
    return(newListHead);
    
}

int main(int argc, char const *argv[])
{
    //create two lists
    // pass the two lists to the function
    // print merged list
    return 0;
}
