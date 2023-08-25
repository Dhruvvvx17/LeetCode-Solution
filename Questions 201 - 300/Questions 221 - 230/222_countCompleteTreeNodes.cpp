#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder_count(TreeNode* root, int &count) {
    if(!root)
        return;
    
    inorder_count(root->left, count);
    
    count += 1;
    
    inorder_count(root->right, count);

    return;
}
    
int left_height(TreeNode *root) {
    return (root==NULL) ? 0 : 1 + left_height(root->left);
} 

int right_height(TreeNode *root) {
    return (root==NULL) ? 0 : 1 + right_height(root->right);
} 


int countNodes(TreeNode* root) {
    
    if(root==NULL)
        return 0;
    
    int count = 0;

    // one way to solve - O(N):
    // inorder_count(root, count);

    // another way to solve - O(logN):
    int lh = left_height(root->left);
    int rh = right_height(root->right);
    
    if( lh == rh )
        count = (pow(2,lh)-1)*2 + 1;
    
    else if(rh < lh)
        // count = left_sub_tree + root + right_sub_tree
        count = countNodes(root->left) + 1 + countNodes(root->right);

    return count;
}

int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);    
    
    cout<<"Number of nodes in the tree: "<<countNodes(root);

    return 0;
}