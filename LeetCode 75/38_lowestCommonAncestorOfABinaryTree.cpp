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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) return root;

    if(root->val == p->val || root->val == q->val) return root;

    TreeNode* lca1 = lowestCommonAncestor(root->left, p, q);
    TreeNode* lca2 = lowestCommonAncestor(root->right, p, q);

    if(lca1 && lca2) return root;
    if(lca1 != nullptr) return lca1;
    return lca2;
}

int main() {

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *p = new TreeNode(6);
    TreeNode *q = new TreeNode(4);

    TreeNode *res = lowestCommonAncestor(root, p, q);

    cout<<"Lowest Common Ancestor: "<<res->val<<endl;
    
    return 0;
}