#include<stdio.h>
#include<stdlib.h>

typedef enum {true, false} bool;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


bool hasPathSum(struct TreeNode* root, int targetSum){

    if(root==NULL) return false;

    // leaf node
    if(!root->left && !root->right && root->val == targetSum) return true;

    return (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val));
}

TreeNode *initTree(){
    TreeNode *head = (TreeNode*)malloc(sizeof(TreeNode));
    head->val = 3;

    head->left = (TreeNode*)malloc(sizeof(TreeNode));
    head->left->val = -1;
    head->left->left = NULL;
    head->left->right = NULL;

    head->right = (TreeNode*)malloc(sizeof(TreeNode));
    head->right->val = 4;

    head->right->left = (TreeNode*)malloc(sizeof(TreeNode));
    head->right->left->val = -2;
    head->right->left->left = NULL;
    head->right->left->right = NULL;

    head->right->right = (TreeNode*)malloc(sizeof(TreeNode));
    head->right->right->val = 5;
    head->right->right->left = NULL;
    head->right->right->right = NULL;
    /*
             3
            / \
           /   \
         -1     4
         / \   /  \
        N  N  -2   5
              /\   /\
             N  N N  N
    */
   return head;
}

void main(){
    TreeNode *root = initTree();

    if(hasPathSum(root,5)){
        printf("Given tree has the path sum 5");
    } else {
        printf("Given tree does not have any path sum 5");
    }
}