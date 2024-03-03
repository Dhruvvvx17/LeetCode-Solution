#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {} 
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    if(root == nullptr || root->val == val) return root;

    if(root->val < val)
        return searchBST(root->right, val);
    else
        return searchBST(root->left, val);
}


int main() {

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    TreeNode *res = searchBST(root, 2);

    if(res)
        cout<<"Found value in tree";
    else
        cout<<"Value not found in tree";

    return 0;
}