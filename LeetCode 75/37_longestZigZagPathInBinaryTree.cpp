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

int getMax(int a, int b, int c) {
    return (a>b) ? (a>c) ? a : c : (b>c) ? b : c;
}

int dfs(TreeNode *root, int depth, int direction) {
    if(root == nullptr) return depth;

    int maxDepth = 0;

    // going right, go left
    if(direction) {
        maxDepth = getMax(
            depth,
            dfs(root->left, depth+1, 0),
            dfs(root->right, 0, 1)
        );
    }

    // going left
    else {
        maxDepth = getMax(
            depth,
            dfs(root->right, depth+1, 1),
            dfs(root->left, 0, 0)
        );
    }

    return maxDepth;
}

int longestZigZag(TreeNode* root) {
    int left = dfs(root->left, 0, 0); 
    int right = dfs(root->right, 0, 1);

    if(left > right)
        return left;
    else
        return right;
}

int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);

    root->left->right = new TreeNode(1);

    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(1);
    
    int res = longestZigZag(root);

    cout<<"Longest zigzag: "<<res;
    
    return 0;
}