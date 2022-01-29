#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


int minDepth(struct TreeNode* root){
    if(!root) return 0;

    if(!root->left && !root->right) return 1;
    
    if(!root->left) return minDepth(root->right)+1;
    
    if(!root->right) return minDepth(root->left)+1;
    
    return minDepth(root->left) < minDepth(root->right) ? minDepth(root->left)+1 : minDepth(root->right)+1;
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

    printf("Min Depth: %d", minDepth(root));
}