#include<iostream>
using namespace std;

// tree struct
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// recursive function to get sum node by node
int sumNumbersHelper(TreeNode *root, int sum){

    // case where either child node is NULL, root could end up as NULL
    if(!root) return 0;
    
    // compute current sum until current node
    sum = (sum * 10) + root->val;

    // check for leaf node
    if(!root->left && !root->right) return sum;

    // iteratively compute for both child nodes
    return (sumNumbersHelper(root->left, sum) + sumNumbersHelper(root->right, sum));
}

// primary function calls the recursive function
int sumNumbers(TreeNode* root) {
    if(!root) return 0;
    
    return sumNumbersHelper(root, 0);        
}

TreeNode* initTree(){
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    return root;
    /*
        4
       / \
      9   0
     / \
    5   1

    Root-to-leaf sum: 495 + 491 + 40 = 1026
    */
}

int main(){

    TreeNode *root = initTree();

    cout<<"Root to leaf sum of given tree: "<<sumNumbers(root);

    return 0;
}