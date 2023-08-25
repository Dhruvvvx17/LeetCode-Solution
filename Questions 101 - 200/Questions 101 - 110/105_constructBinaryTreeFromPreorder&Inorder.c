#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


int findIndex(int *inorder, int begin, int size, int root_val){
    int index;
    for(int i=begin; i<=size; i++){
        if(inorder[i]==root_val){
            index = i;
            break;
        }        
    }
    return index;
}

TreeNode* buildTreeHelper(int *preorder, int preorderSize, int *inorder, int start, int end, int *globalIndex){
        
    if(start>end)
        return NULL;

    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = preorder[(*globalIndex)++];
        
    // leaf node
    if(start == end){
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    
    // intermediate node
    else{
        int root_index = findIndex(inorder, start, end, root->val);
        root->left = buildTreeHelper(preorder, preorderSize-1, inorder, start, root_index-1, globalIndex);
        root->right = buildTreeHelper(preorder, preorderSize-1, inorder, root_index+1, end, globalIndex);
        return root;
    }
}

TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    int start, end, globalIndex;
    start = 0;
    end = inorderSize-1;
    globalIndex = 0;
    return buildTreeHelper(preorder, preorderSize, inorder, start, end, &globalIndex);
}

void inorderTraversal(TreeNode *root){
    if(root==NULL)
        return;
    
    inorderTraversal(root->left);
    printf(" %d",root->val);
    inorderTraversal(root->right);
}

void main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int *preorder = (int*)malloc(sizeof(int)*n);
    int *inorder = (int*)malloc(sizeof(int)*n);

    printf("Enter elements in preorder traverals: \n");
    for(int i=0; i<n; i++){
        printf("Element %d: ", i);
        scanf("%d",&preorder[i]);
    }

    printf("Enter elements in inorder traverals: \n");
    for(int i=0; i<n; i++){
        printf("Element %d: ", i);
        scanf("%d",&inorder[i]);
    }

    TreeNode *root = buildTree(preorder, n, inorder, n);

    if(root){
        printf("Tree Build Successful!\nInorder traversal - ");
        inorderTraversal(root);
    }
    else{
        printf("Error\n");
    }
}