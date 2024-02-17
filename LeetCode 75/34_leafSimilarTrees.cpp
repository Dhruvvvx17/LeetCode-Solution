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


void dfs(TreeNode*, string &);

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    string s1, s2;
    dfs(root1, s1);
    dfs(root2, s2);
    return s1 == s2;
}

void dfs(TreeNode *root, string &s) {
    if(root->left==nullptr && root->right==nullptr) 
        s += (to_string(root->val) + "_");

    if(root->left) dfs(root->left, s);
    if(root->right) dfs(root->right, s);

    return;
}

int main() {

    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(9);
    root2->left->right = new TreeNode(15);

    if(leafSimilar(root1, root2))
        cout<<"Root Similar!";
    else
        cout<<"Root not similar!";

    return 0;
}