#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

ListNode* deleteDuplicates(ListNode* head){
    
    if(head==NULL){
        return head;
    }
    
    ListNode *p, *q;
    p = head;
    q = head;
    
    while(p!=NULL){
        if(p->val == q->val){
            p = p->next;
        }
        else {
            q->next = p;
            q = q->next;
            p = p->next;
        }
    }
    q->next = NULL;
    return head;
}

void main(){
    int n;
    printf("Enter number of nodes(n): ");
    scanf("%d",&n);

    ListNode *head,*p;

    head = NULL;

    for(int i=0;i<n;i++){
        ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
        printf("Enter node %d value: ",i);
        scanf("%d",&new_node->val);
        if(i==0){
            head = new_node;
            p = head;
        }
        else{
            p->next = new_node;
            p = p->next;
        }
    }
    p->next = NULL;

    ListNode *new_head = deleteDuplicates(head);


    printf("New List: ");
    for(p = new_head;p!=NULL;p=p->next){
        printf("%d ",p->val);
    }
}