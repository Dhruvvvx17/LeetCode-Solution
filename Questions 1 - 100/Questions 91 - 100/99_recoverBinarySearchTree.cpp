#include<iostream>
#include<vector>

// custom structure fro tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *prev = NULL;
TreeNode *first = NULL;
TreeNode *second = NULL;

void inorderTraversal(TreeNode *root) {
    if(root == NULL)
        return;
    
    // go left
    inorderTraversal(root->left);
    
    // compare nodes
    if(prev != NULL && prev->val >= root->val) {
        if(first == NULL)
            first = prev;
        second = root;
    }
    
    prev = root;
    
    //go right
    inorderTraversal(root->right);
    return;
}

void recoverTree(TreeNode* root) {
    
    inorderTraversal(root);
    
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
    
    return;
}

void printInorder(TreeNode *root) {
    if(root == NULL)
        return;
    
    printInorder(root->left);
    std::cout<<root->val<<" ";
    printInorder(root->right);
}

int main() {

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = new TreeNode(2);
    root->right->right = NULL;


    printInorder(root);
    std::cout<<std::endl;

    recoverTree(root);

    printInorder(root);
    std::cout<<std::endl;
    
    return 0;
}