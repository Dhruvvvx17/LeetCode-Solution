#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// TreeNode structure
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// function declarations
int maxDepth(TreeNode*);
TreeNode *initTree();

// function to find maxDepth
int maxDepth(TreeNode* root){
    if(root==NULL) return 0;
    
    int lheight = maxDepth(root->left);
    int rheight = maxDepth(root->right);
    
    if(lheight>rheight)
        return lheight+1;
    else
        return rheight+1;
}

// function to initialize a tree manually for quick testing
TreeNode *initTree(){
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
    head->left->right->val = 4;
    head->left->right->left = NULL;
    head->left->right->right = NULL;    
    /*
        Depth: 3

            5           level-1
           / \
          3    7        level-2
         / \  / \
        N  4 N   N      level-3
          / \
         N   N
    */
   return head;
}

void main(){
    TreeNode *root = initTree();
    printf("Max depth of tree: %d",maxDepth(root));
}