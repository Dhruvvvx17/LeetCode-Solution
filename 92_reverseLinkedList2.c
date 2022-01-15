#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

Node* reverseBetween(Node* head, int left, int right){
    
    // linked list with 0 or 1 node or left & right positions are same as the original list
    if(head==NULL || head->next==NULL || left==right) return head;
    
    // linked list with two nodes, left=1 and right=2
    if(head->next->next==NULL){
        Node *p = head;
        head->next->next = head;
        head = head->next;
        p->next = NULL;
        return head;
    }
    
    
    // general case: 3 or more nodes - add a sentinel node
    Node *sentinel, *p, *q, *r, *s;
    sentinel = (Node*)malloc(sizeof(Node)*1);    
    sentinel->val = 0;
    sentinel->next = head;
    p = sentinel;       // p points to sentinel node
    q = head;           // q points to first node
    r = head->next;     // r points to second node

    int dist_to_left = left-1, dist_to_right = right-2;
 
    // traverse the list until q points to the 'left' position node
    while(dist_to_left){
        p = q;
        q = r;
        r = r->next;
        dist_to_left--;
        dist_to_right--;
    }
    
    // traverse until s points to 'right' position node
    s = r;
    while(dist_to_right){
        s = s->next;
        dist_to_right--;
    }
    
    // alter the left and right position nodes first
    p->next = s;        // node before left points to node 'right'
    q->next = s->next;  // node 'left' points to node after right
    
    // update pointers
    p = q;
    q = r;
    r = r->next;
    
    // alter the nodes between left and right
    while(q!=s){
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    
    // check if head has to be updated (ie; if left is 1)
    if(left==1)
        head = s;
    
    // free the sentinel node
    free(sentinel);
    
    return head;
}

void main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    // dummy head
    Node *head, *p;
    head = (Node*)malloc(sizeof(Node)*1);
    p = head;

    for(int i=0;i<n;i++){
        printf("Enter node-%d value: ",i);
        Node *new_node = (Node*)malloc(sizeof(Node)*1);
        scanf("%d",&new_node->val);
        p->next = new_node;
        p = new_node;
    }
    // last node->next points to null
    p->next = NULL;

    // update head to real head
    Node *dummy = head;
    head = head->next;
    free(dummy);

    int left, right;
    printf("Enter left value: ");
    scanf("%d",&left);
    printf("Enter right value (greater than left): ");
    scanf("%d",&right);

    head = reverseBetween(head, left, right);

    printf("Updated list: ");
    for(p=head; p!=NULL; p=p->next){
        printf("%d ",p->val);
    }
    printf("\n");
}