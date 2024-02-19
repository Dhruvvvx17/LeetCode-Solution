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

int64_t count = 0;

void dfs(TreeNode* root, int64_t targetSum) {
    if(root == nullptr) return;

    if(root->val == targetSum) count+=1;
    dfs(root->left, targetSum - root->val);
    dfs(root->right, targetSum - root->val);
}

int pathSum(TreeNode* root, int64_t targetSum) {
    if(root) {
        dfs(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
    }
    return count;
}

int main() {

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);


    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);

    root->right->right = new TreeNode(11);

    int targetSum = 8;

    int64_t res = pathSum(root, targetSum);

    cout<<"Number of paths = "<<res;

    return 0;
}