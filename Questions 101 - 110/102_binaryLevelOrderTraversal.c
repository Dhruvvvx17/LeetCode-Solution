#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
 
int height(TreeNode *root){
    if(root==NULL) return 0;

    else{
        int lheight = height(root->left);
        int rheight = height(root->right);
        if(lheight > rheight)
            return lheight+1;
        else
            return rheight+1;
    }
}

void getLevelOrder(TreeNode *root, int level, int *temp, int *temp_size){
    if(root==NULL)
        return;
    if(level==0){
        temp[(*temp_size)++] = root->val;
    }
    else{
        getLevelOrder(root->left, level-1, temp, temp_size);
        getLevelOrder(root->right, level-1, temp, temp_size);
    }
}

int maxNodesPerLevel(int level){
    return (level<=20)?pow(2, level):2048;
}

int** levelOrder(TreeNode* root, int* returnSize, int** returnColumnSizes){
    
    // get height of the tree
    int h = height(root);
    
    // number of levels = height
    *returnSize = h;


    // create an array of array, where number of sub-arrays = number of levels = height
    int **result = (int**)malloc(sizeof(int*)*h);
    
    // number of columns = number of levels = height
    *returnColumnSizes = (int*)malloc(sizeof(int)*h);
   
    // fetch level order from level(0) to level(height-1)
    for(int i=0;i<h;i++){
        int *temp = (int*)malloc(sizeof(int)*maxNodesPerLevel(i));
        int temp_size = 0;
        getLevelOrder(root, i, temp, &temp_size);
        
        // add current level nodes to result
        result[i] = temp;
        returnColumnSizes[0][i] = temp_size;
    }
    
    return result;
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
    TreeNode *root = initTree();

    int returnSize;

    int *returnColumnSizes;

    int **result = levelOrder(root, &returnSize, &returnColumnSizes);

    for(int i=0;i<returnSize;i++){
        printf("Level %d - ",i);
        for(int j=0;j<returnColumnSizes[i];j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}