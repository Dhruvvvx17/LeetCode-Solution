#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *createNode(int val) {
    TreeNode *p = new TreeNode(val);
    cout<<"Inserted "<<p->val<<endl;
    return p;    
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if(root==nullptr)
        return nullptr;
    
    if(root->val == p->val || root->val == q->val)
        return root;
    
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    
    if(left && right)
        return root;
    
    if(left)
        return left;
    
    else
        return right;        
}

void inorder(TreeNode *root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
    return;
}

int main() {

    vector<int> nums = {6, 2, 8, 0, 4, 7, 9, 3, 5};

    TreeNode *root = createNode(6);
    root->left = createNode(2);
    root->right = createNode(8);
    root->left->left = createNode(0);
    root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(9);
    root->left->left->left = createNode(3);
    root->left->left->right = createNode(5);
    
    // inorder traversal of tree
    inorder(root);
    cout<<endl;

    TreeNode *p = new TreeNode(3);
    TreeNode *q = new TreeNode(4);

    TreeNode *res = lowestCommonAncestor(root, p, q);

    cout<<"Found lowest common ancestor: "<<res->val<<endl;

    return 0;
}