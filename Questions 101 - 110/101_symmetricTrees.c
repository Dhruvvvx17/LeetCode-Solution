#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


int isSymmetricHelper(struct TreeNode* left, struct TreeNode* right){
    if(left==NULL && right==NULL) return 1;
    
    if((left==NULL && right!=NULL)||(left!=NULL && right==NULL)) return 0;
    
    if((left->val==right->val) && isSymmetricHelper(left->left,right->right) && isSymmetricHelper(left->right,right->left)) return 1;
    
    return 0;
}

int isSymmetric(struct TreeNode* root){
    
    if(root==NULL || (root->left==NULL && root->right==NULL)) return 1;
    
    return isSymmetricHelper(root->left,root->right);
}

TreeNode* initTree(){
    TreeNode *head = (TreeNode*)malloc(sizeof(TreeNode));
    head->val = 1;

    head->left = (TreeNode*)malloc(sizeof(TreeNode));
    head->left->val = 2;
    head->left->right = NULL;

    head->right = (TreeNode*)malloc(sizeof(TreeNode));
    head->right->val = 2;
    head->right->left = NULL;

    head->left->left = (TreeNode*)malloc(sizeof(TreeNode));
    head->left->left->val = 4;
    head->left->left->left = NULL;
    head->left->left->right = NULL;
    

    head->right->right = (TreeNode*)malloc(sizeof(TreeNode));
    head->right->right->val = 4;
    head->right->right->left = NULL;
    head->right->right->right = NULL;    

    /*
            1
           / \
          2   2
         / \ / \
        4  N N  4
    */
   return head;
}

void main(){
    TreeNode *head = initTree();

    if(isSymmetric(head)){
        printf("Tree is symmetric");
    }else{
        printf("Tree is asymmetric");
    }
}