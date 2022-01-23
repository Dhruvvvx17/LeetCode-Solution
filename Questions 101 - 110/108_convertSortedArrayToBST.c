#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* helper(int *nums, int left, int right){
    if(left<=right){
        int mid = (right+left)/2;
        TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
        root->val = nums[mid];
        root->left = helper(nums, left, mid-1);
        root->right = helper(nums, mid+1, right);
        return root;
    }
    else{
        return NULL;
    }
}

TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return helper(nums, 0, numsSize-1);
}

void inorderTraversal(TreeNode *root){
    if(root==NULL) return;
    inorderTraversal(root->left);
    printf("%d ",root->val);
    inorderTraversal(root->right);
    return;
}

void main(){
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        printf("Enter array value %d: ",i);
        scanf("%d",&arr[i]);
    }

    TreeNode *root = sortedArrayToBST(arr, n);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
}