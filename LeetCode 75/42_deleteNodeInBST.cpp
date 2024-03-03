#include<iostream>
#include<map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* deleteNode(TreeNode* root, int val) {

        if(root == nullptr) return root;

        if(root->val < val)
            root->right = deleteNode(root->right, val);
        
        else if(root->val > val)
            root->left = deleteNode(root->left, val);
        
        else {
            // 3 choices
            // 1. if node is a leaf
            if(root->left == nullptr && root->right == nullptr)
                return nullptr;

            // 2. if node has atmost one child
            else if(root->left == nullptr || root->right == nullptr)
                return (root->left) ? root->left : root->right;

            // 3. if node is a non-left with both child
            else {
                TreeNode *temp = root->right;
                while(temp->left != nullptr) temp = temp->left;
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }

        return root;
    }

int main() {

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode *res = deleteNode(root, 2);

    if(res)
        cout<<"Node Deleted!";

    return 0;
}