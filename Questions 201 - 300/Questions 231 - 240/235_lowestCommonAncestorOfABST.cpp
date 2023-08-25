#include<iostream>
#include<vector>
using namespace std;

// simple TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// createNode
TreeNode *createNode(int val) {
    TreeNode *root = new TreeNode(val);
    return root;    
}

// insert new node in BST
TreeNode* insertBST(TreeNode *root, int x) {
    TreeNode *p = root;
    
    // reached end of the tree -> this is where new node will be inserted
    if(!root) {
        TreeNode *temp = createNode(x);
        return temp;
    }
    
    if(x > p->val) {
        root->right = insertBST(root->right, x);
    }
    else {
        root->left = insertBST(root->left, x);
    }
    return root;
}

// find min node
TreeNode* min(TreeNode *a, TreeNode *b){
    return (a->val > b->val) ? b : a;
}

// find max node
TreeNode* max(TreeNode *a, TreeNode *b){
    return (a->val > b->val) ? a : b;
}


// for the lowest common ancestor in a BST, use the property of BST.
// compare the minimum and the maximum of the two nodes to reduce search space.
// if the min is smaller than root and max is larger than the root then -> the root is the LCA
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(root == nullptr)
        return nullptr;
    
    if(p->val == root->val || q->val == root->val)
        return root;
    
    TreeNode *min_node = min(p,q);
    TreeNode *max_node = max(p,q);
    
    // if max is on the left of root = go left
    if(max_node->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    
    // if min is on the right of root = go right
    if(min_node->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    
    if(min_node->val < root->val && max_node->val > root->val)
        return root;
    
    else
        return nullptr;
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

    TreeNode *root = nullptr;
    for (int num : nums){
        root = insertBST(root, num);
    }

    // inorder traversal of tree
    inorder(root);
    cout<<endl;

    TreeNode *p = new TreeNode(2);
    TreeNode *q = new TreeNode(8);

    TreeNode *res = lowestCommonAncestor(root, p, q);

    cout<<"Found lowest common ancestor: "<<res->val<<endl;

    return 0;
}