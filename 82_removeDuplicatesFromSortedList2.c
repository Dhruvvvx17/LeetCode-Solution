#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

ListNode* deleteDuplicates(ListNode* head){
    
    if(head==NULL) return head;
    if(head->next == NULL) return head;

    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    ListNode *q = p;
    ListNode *r = p;
    
    p->val = 0;
    p->next = head;
    
    while(head!=NULL){
        if(head->next != NULL && head->val == head->next->val){
            while(head->next != NULL && head->val == head->next->val){
                head = head->next;                
            }
            p->next = head->next;        
        }
        else{
            p = p->next;
        }
        head = head->next;
    }
    q = q->next;
    free(r);
    return q;
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