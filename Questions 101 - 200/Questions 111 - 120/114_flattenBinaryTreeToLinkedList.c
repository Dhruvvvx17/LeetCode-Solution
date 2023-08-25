#include<stdio.h>
#include<stdlib.h>

typedef enum {true, false} bool;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// function declarations
void flatten(TreeNode* root);
void flattenHelper(TreeNode *root);


void flatten(TreeNode* root){

    // check for empty tree or single node tree    
    if(!root || (!root->left && !root->right)) return;
    
    flattenHelper(root);
}

TreeNode* getLeftSubTreeLeaf(TreeNode* root){
    TreeNode *p = root;
    while(p->right!=NULL)
        p = p->right;
    return p;
}

void flattenHelper(TreeNode *root){
    
    //leaf node
    if(root->left==NULL && root->right==NULL) return;

    if(root->right!=NULL)
        flattenHelper(root->right);
    
    if(root->left!=NULL){
        flattenHelper(root->left);
    
        if(root->left!=NULL){
            TreeNode *leftMostLeaf = getLeftSubTreeLeaf(root->left);
            if(leftMostLeaf){
                leftMostLeaf->left = NULL;
                leftMostLeaf->right = root->right;
                root->right = root->left;
                root->left = NULL;        
            }
        }
    }
}

void preOrderTraversal(TreeNode *root){
    if(root==NULL) return;

    printf(" %d",root->val);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

TreeNode *initTree(){
    TreeNode *head = (TreeNode*)malloc(sizeof(TreeNode));
    head->val = 3;

    head->left = (TreeNode*)malloc(sizeof(TreeNode));
    head->left->val = 1;
    head->left->left = NULL;
    head->left->right = NULL;

    head->right = (TreeNode*)malloc(sizeof(TreeNode));
    head->right->val = 4;

    head->right->left = (TreeNode*)malloc(sizeof(TreeNode));
    head->right->left->val = 6;
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
          1     4
         / \    / \
        N  N   6   5
              /\   /\
             N  N N  N
    */
   return head;
}

void main(){
    TreeNode *root = initTree();

    printf("Traversing original tree: ");
    preOrderTraversal(root);
    printf("\n");

    flatten(root);

    printf("Traversing flattened tree: ");
    preOrderTraversal(root);
}