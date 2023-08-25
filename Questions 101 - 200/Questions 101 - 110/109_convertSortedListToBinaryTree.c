#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode *currentNode;

TreeNode* buildTree(int start, int end){

    if(start>=end) return NULL;

    // get middle node index 
    int mid = start + ((end-start)>>1);
    
    // allocate memory for root
    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    
    // build left subTree
    root->left = buildTree(start,mid);
    
    // set current value and increment to next node in linked list
    root->val = currentNode->val;
    currentNode = currentNode->next;

    // build right subTree
    root->right = buildTree(mid+1,end);
    
    return root;    
}

TreeNode* sortedListToBST(ListNode* head){
    if(head==NULL){
        TreeNode *root = NULL;
        return root;
    }
    
    currentNode = head;
    int len = 0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    
    return buildTree(0,len);
}

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

ListNode* initList(){
    ListNode *head;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 2;

    head->next = (ListNode*)malloc(sizeof(ListNode));
    head->next->val = 4;

    head->next->next = (ListNode*)malloc(sizeof(ListNode));
    head->next->next->val = 6;

    head->next->next->next = (ListNode*)malloc(sizeof(ListNode));
    head->next->next->next->val = 8;

    head->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
    head->next->next->next->next->val = 10;

    head->next->next->next->next->next = NULL;

    return head;
}

void main(){
    ListNode *head = initList();

    TreeNode *root = sortedListToBST(head);

    printf("Inorder Traversal: ");
    inorder(root);
}
