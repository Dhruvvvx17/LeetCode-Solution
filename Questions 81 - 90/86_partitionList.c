#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

struct ListNode* partition(struct ListNode* head, int x){
    
    if(head==NULL || head->next==NULL) return head;
    
    struct ListNode *lesser, *greater, *p, *l, *g;
    
    p = head;
    lesser = NULL;
    greater = NULL;
    
    while(p!=NULL){
        if(p->val<x){
            // first lesser node
            if(lesser==NULL){
                lesser = p;
                l = lesser;
            }
            // regular lesser nodes
            else{
                l->next = p;
                l = l->next;
            }
        }
        else {
            // first greater node
            if(greater==NULL){
                greater = p;
                g = greater;
            }
            // regular greater nodes
            else{
                g->next = p;
                g = g->next;
            }
        }
        p = p->next;
    }
    
    // check if partial sublists are empty
    if(lesser==NULL){
        head = greater;
        g->next = NULL;
    } 
    else if(greater==NULL){
        head = lesser;
        l->next = NULL;
    }
    else{    
        head = lesser;
        l->next = greater;
        g->next = NULL;
    }    
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

    int x;
    printf("Enter partition number: ");
    scanf("%d",&x);

    ListNode *new_head = partition(head,x);


    printf("New List: ");
    for(p = new_head;p!=NULL;p=p->next){
        printf("%d ",p->val);
    }
}