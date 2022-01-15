#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node *left;
    struct Node *right;
}Node;

void inorder(Node *root, int *res, int *index){

    // if reached NULL, return
    if(root==NULL)
        return;
    
    // traverse left of parent
    inorder(root->left, res, index);

    // add current value to result
    res[(*index)++] = root->val;

    // traverse right of parent
    inorder(root->right, res, index);    
}


int* inorderTraversal(Node *root, int *returnSize){

    // allocate space for result
    int *res = (int*)malloc(sizeof(int)*100);   // according to constraints, max 100 nodes
    *returnSize = 0;

    inorder(root, res, returnSize);
    
    return res;
}

void main(){

    // hard-coding tree nodes' values
    Node *root = (Node*)malloc(sizeof(Node));
    root->val = 5;

    root->left = (Node*)malloc(sizeof(Node));
    root->left->val = 7;

    root->left->left = NULL;

    root->left->right = (Node*)malloc(sizeof(Node));
    root->left->right->val = 9;

    root->left->right->left = NULL;
    root->left->right->right = NULL;

    root->right = (Node*)malloc(sizeof(Node));
    root->right->val = 11;
    root->right->left = NULL;
    root->right->right = NULL;


    /*
    The above tree looks like:
                5
               / \
              /   \
             7    11
            / \   / \
           N   9 N   N
              / \
             N   N
    */

    int returnSize;
    int *res = inorderTraversal(root, &returnSize);

    printf("In-order traversal of given tree: ");
    for(int i=0; i<returnSize; i++){
        printf("%d ",res[i]);
    }

    free(res);
}