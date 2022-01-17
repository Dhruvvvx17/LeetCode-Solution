#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// function declarations
TreeNode *initTree();
int validateBSTHelper(TreeNode*, TreeNode*, TreeNode*);
int isValidBST(TreeNode* );

int isValidBST(TreeNode* root){

    if(root == NULL || (root->left==NULL && root->right==NULL)) return 1;
    
    return validateBSTHelper(root, NULL, NULL);
}

int validateBSTHelper(TreeNode* root, TreeNode *max, TreeNode *min){
    
    if(root == NULL) return 1;
    
    if(max && root->val >= max->val) return 0;
    
    if(min && root->val <= min->val) return 0;
    
    return validateBSTHelper(root->left,root,min) && validateBSTHelper(root->right,max,root);
}

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
            5
           / \
          3    7
         / \  / \
        N  4 N   N
    */
   return head;
}

void main(){
    TreeNode *head = initTree();

    if(isValidBST(head)){
        printf("Valid Binary Search Tree");
    } else {
        printf("Invalid Binary Search Tree");
    }
}