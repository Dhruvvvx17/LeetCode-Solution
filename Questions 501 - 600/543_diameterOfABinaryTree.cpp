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

// function declarations
int solve(TreeNode*);
int diameterOfBinaryTree(TreeNode*);
int getMax(int, int);

// global variable
int diameter = 0;

int diameterOfBinaryTree(TreeNode* root) {
    solve(root);
    return diameter;
}

int getMax(int a, int b){
    return (a>b) ? a : b;
}

int solve(TreeNode *root){

    // -1 just for the math to make sense
    if(!root)
        return -1;

    // a leaf node in itself has 0 diameter
    if(!root->left && !root->right)
        return 0;

    // get left and right "height"
    int left = solve(root->left);
    int right = solve(root->right);

    // diameter is max of global diameter and leftHeight + rightHeight + 2
    // -1 for null helps here with +2 making the next diameter for a leaf node 0
    diameter = getMax(diameter, left + right + 2);

    // return height of the subtree, diameter is stored in the global variable
    return getMax(left, right) + 1;
}

int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    cout<<"Diameter of binary tree: "<<diameterOfBinaryTree(root);

    return 0;
}