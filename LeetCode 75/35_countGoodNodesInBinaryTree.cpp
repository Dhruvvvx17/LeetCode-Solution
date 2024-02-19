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

void dfs(TreeNode *root, int &count, int currMax) {
    if(root == nullptr) return;

    if(root->val >= currMax) {
        currMax = root->val;
        count += 1;
    }

    dfs(root->left, count, currMax);
    dfs(root->right, count, currMax);
    return;
}

int goodNodes(TreeNode* root) {
    int count = 1, currMax = root->val;
    dfs(root->left, count, currMax);
    dfs(root->right, count, currMax);
    return count;
}

int main() {

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);

    root->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);    

    int res = goodNodes(root);

    cout<<"Number of good nodes: "<<res;
    
    return 0;
}