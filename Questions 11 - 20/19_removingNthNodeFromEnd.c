// Works on leet code, some problem in main function

#include<stdio.h>
#include<stdlib.h>

//  Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };

// ONE PASS SOLUTION WITH A FAST AND SLOW POINTER
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    if(head==NULL || n==0){
        return head;
    }
    
    struct ListNode *fast, *slow;
    fast = head;
    slow = head;
    int count = 0;

    // push fast node n nodes from the start
    for(int i=0;i<n;i++){
        fast = fast->next;
        count += 1;
        if(fast==NULL)
            break;
    }
    
    // removing first node if n==size of linked list
    if(fast==NULL){
        if(count==n)
            return head->next;
        else
            return head;
    }
        
        
    // now push both nodes simultaneously, until fast reaches end of the list
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    
    // removing last node
    if(n==1){
        slow->next = NULL;
        return head;
    }
        
    //removing intermediate node
    slow->next = slow->next->next;
    return head;
}

int main(int argc, char const *argv[])
{
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *new_node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *new_node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *new_node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *new_node4 = (struct ListNode*)malloc(sizeof(struct ListNode));

    head->val = 1;
    head->next = new_node1;
    new_node1->val = 2;
    new_node1->next = new_node2;
    new_node2->val = 3;
    new_node2->next = new_node3;
    new_node3->val = 4;
    new_node3->next = new_node4;
    new_node4->val = 5;
    new_node4->next = NULL;

    int n = 3;

    printf("Original List: ");
    struct ListNode *p = head;
    while(p!=NULL){
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");

    head = removeNthFromEnd(head,n);

    printf("After removing %dth node from the end, new list: ",n);
    struct ListNode *q = head;
    while(q!=NULL){
        printf("%d ",q->val);
        q = q->next;
    }
    printf("\n");
    return 0;
}






/*TWO PASS SOLUTION*/

//     if(head==NULL || n==0)
//         return head;
    
//     int num_of_nodes = 0;
//     struct ListNode *p = head;
//     while(p!=NULL){
//         num_of_nodes += 1;
//         p = p->next;
//     }
    
//     printf("Number of nodes: %d",num_of_nodes);
    
//     if(n>num_of_nodes){
//         return head;
//     }
//     if(n==num_of_nodes){
//         return (head->next);
//     }
    
//     int index_to_remove = num_of_nodes - n;
//     p = head;
//     struct ListNode *q = p;
//     int i = 0;
//     while(i!=index_to_remove){
//         q = p;
//         p = p->next;
//         i++;  
//     } 
//     q->next = p->next;
//     free(p);
//     return head;
// }