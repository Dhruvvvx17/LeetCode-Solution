#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// changing bool to int - 0=false and 1=true
int isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p==NULL && q==NULL) return 1;
    
    if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)) return 0;
    
    if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && (p->val==q->val)) return 1;
        
    return 0;
}

// hard-coding a tree, returns the head of the new tree created
TreeNode* initTree(){
    TreeNode *head = (TreeNode*)malloc(sizeof(TreeNode));
    head->val = 5;

    head->left = (TreeNode*)malloc(sizeof(TreeNode));
    head->left->val = 3;
    head->left->left = NULL;

    head->right = (TreeNode*)malloc(sizeof(TreeNode));
    head->right->val = 7;
    head->right->left = NULL;
    head->right->right = NULL;

    head->left->right = (TreeNode*)malloc(sizeof(TreeNode));
    head->left->right->val = 10;
    head->left->right->left = NULL;
    head->left->right->right = NULL;    
    /*
             5
           /  \
          3    7
         / \  / \
        N  10 N  N
    */
   return head;
}

void main(){
    // using the same initTree function hence two same trees are generated
    TreeNode *head1 = initTree();
    TreeNode *head2 = initTree();

    int res = isSameTree(head1, head2);

    if(res){
        printf("The two trees are the same");
    }
    else{
        printf("The two trees are different");
    }
}