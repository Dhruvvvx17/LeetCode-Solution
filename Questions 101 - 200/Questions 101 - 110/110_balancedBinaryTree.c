#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef enum {true, false} bool;

int isBalancedHelper(TreeNode* root){
    
    if(root==NULL) return 0;
    
    int left = isBalancedHelper(root->left);
    if(left==-1) return -1;
    int right = isBalancedHelper(root->right);
    if(right==-1) return -1;
    
    int res = left-right;

    // get absolute height
    res = (res>=0) ? res : 0-res;

    // if height diff greater than 1, return -1
    if(res>1) return -1;

    if(left>right)
        return left+1;
    else
        return right+1;
}

bool isBalanced(TreeNode* root){
    
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;
    
    return (isBalancedHelper(root)==-1) ? false : true;    
}

TreeNode *initTree(){
    TreeNode *head = (TreeNode*)malloc(sizeof(TreeNode));
    head->val = 3;

    head->left = (TreeNode*)malloc(sizeof(TreeNode));
    head->left->val = 9;
    head->left->left = NULL;
    head->left->right = NULL;

    head->right = (TreeNode*)malloc(sizeof(TreeNode));
    head->right->val = 20;

    head->right->left = (TreeNode*)malloc(sizeof(TreeNode));
    head->right->left->val = 15;
    head->right->left->left = NULL;
    head->right->left->right = NULL;

    head->right->right = (TreeNode*)malloc(sizeof(TreeNode));
    head->right->right->val = 7;
    head->right->right->left = NULL;
    head->right->right->right = NULL;
    /*
             3
            / \
           /   \
          9    20
         / \  /  \
        N  N 15   7
             /\   /\
            N  N N  N
    */
   return head;
}

void main(){
    TreeNode *root = initTree();

    if(isBalanced(root)==true)
        printf("Balanced Tree!");
    else
        printf("Unbalanced Tree!");
}