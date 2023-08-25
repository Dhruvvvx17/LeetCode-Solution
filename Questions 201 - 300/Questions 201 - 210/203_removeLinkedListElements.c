#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode* removeElements(ListNode* head, int val){
    
    if(head==NULL) return head;
    
    // travers to the first valid value, incase head->val == val
    while(head != NULL && head->val == val){
        head = head->next;
    }
    
    ListNode *p, *q;
    p = head;
    q = p;

    // arranging nodes to skip the val
    while(p!=NULL) {
        if(p->val == val){
            q->next = p->next;
            free(p);
            p = q;
        }
        else {
            q = p;
            p = p->next;
        }
    }
    
    return head;
}

void main() {
    int n;
    printf("Enter number of nodes: ");
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

    printf("Initial List: ");
    for(ListNode *q=head; q!=NULL; q = q->next) {
        printf("%d ",q->val);
    }
    printf("\n");

    int val;
    printf("Enter value to remove: ");
    scanf("%d",&val);

    ListNode *newHead = removeElements(head, val);

    printf("Final List: ");
    for(ListNode *q=newHead; q!=NULL; q = q->next) {
        printf("%d ",q->val);
    }

    free(newHead);
}