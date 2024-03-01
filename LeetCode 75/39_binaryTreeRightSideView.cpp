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


void helper(TreeNode *root, vector<int> &res, int &maxLevel, int currLevel) {
    if(root == nullptr) return;

    if(currLevel > maxLevel) {
        res.push_back(root->val);
        maxLevel = currLevel;
    }

    helper(root->right, res, maxLevel, currLevel+1);
    helper(root->left, res, maxLevel, currLevel+1);
}


vector<int> rightSideView(TreeNode* root) {
    vector<int> res = {};
    int maxLevel = -1;

    helper(root, res, maxLevel, 0);
    return res;
}


int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> res = rightSideView(root);

    cout<<"Right Side View: ";
    for(int x: res){
        cout<<x<<" ";
    }
    
    return 0;
}