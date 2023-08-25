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
vector<int> rightSideView(TreeNode*);
void findNextRightNode(TreeNode*, vector<int>*, int*, int);

vector<int> rightSideView(TreeNode* root) {
    int maxLevel = 0;
    vector<int> res;
    findNextRightNode(root, &res, &maxLevel, 1);        
    return res;
}
    
void findNextRightNode(TreeNode *root, vector<int> *res, int *maxLevel, int level) {
    if(root==NULL)
        return;

    // if you are at a new level then based on below order of function calls,
    // you will be at the right most node
    if(*maxLevel < level) {
        res->push_back(root->val);
        *maxLevel = level;
    }
    
    findNextRightNode(root->right, res, maxLevel, level+1);
    findNextRightNode(root->left, res, maxLevel, level+1);
}    

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> res = rightSideView(root);

    cout<<"Right view of the tree: ";
    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}