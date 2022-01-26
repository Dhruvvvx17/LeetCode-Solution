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

TreeNode* buildTreeHelper(int *postorder, int postorderSize, int *inorder, int start, int end, int *globalIndex) {
        
    if(start>end)
        return NULL;

    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = postorder[(*globalIndex)--];
            
    // leaf node
    if(start == end){
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    
    // intermediate node
    else{
        int root_index = findIndex(inorder, start, end, root->val);
        root->right = buildTreeHelper(postorder, postorderSize-1, inorder, root_index+1, end, globalIndex);
        root->left = buildTreeHelper(postorder, postorderSize-1, inorder, start, root_index-1, globalIndex);
        return root;
    }
}

TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    int start, end, globalIndex;
    start = 0;
    end = inorderSize-1;
    globalIndex = postorderSize-1;
    return buildTreeHelper(postorder, postorderSize, inorder, start, end, &globalIndex);
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

    int *postorder = (int*)malloc(sizeof(int)*n);
    int *inorder = (int*)malloc(sizeof(int)*n);

    printf("Enter elements in inorder traverals: \n");
    for(int i=0; i<n; i++){
        printf("Element %d: ", i);
        scanf("%d",&inorder[i]);
    }

    printf("Enter elements in postorder traverals: \n");
    for(int i=0; i<n; i++){
        printf("Element %d: ", i);
        scanf("%d",&postorder[i]);
    }

    TreeNode *root = buildTree(inorder, n, postorder, n);

    if(root){
        printf("Tree Build Successful!\nInorder traversal - ");
        inorderTraversal(root);
    }
    else{
        printf("Error\n");
    }
}