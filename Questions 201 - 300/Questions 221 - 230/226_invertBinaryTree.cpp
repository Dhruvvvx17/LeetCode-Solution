#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
    
    if(root==NULL) return NULL;
    
    // cout<<"root->val: "<<root->val<<endl;
    
    if ((root->left == NULL) && (root->right == NULL)) return root;
    
    TreeNode *temp_left = invertTree(root->left);
    TreeNode *temp_right = invertTree(root->right);

    root->left = temp_right;
    root->right = temp_left;
    
    return root;
}

void printTree(TreeNode *root) {
    if(root==NULL)
        return;

    printTree(root->left);
    cout<<root->val<<" ";
    printTree(root->right);
    return;
}

int main() {
    TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    printTree(root);
    cout<<endl;

    TreeNode *new_root = invertTree(root);
    printTree(new_root);
    cout<<endl;

    return 0;
}