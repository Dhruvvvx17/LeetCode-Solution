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

void preorderRecursion(TreeNode* root, vector<int> *res){
    if(!root)
        return;
    
    res->push_back(root->val);

    preorderRecursion(root->left, res);
    preorderRecursion(root->right, res);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorderRecursion(root, &res);
    return res;
}

TreeNode* initTree(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->right = new TreeNode(4);

    /*
        1
       / \
      2   3
           \
            4
    */

   return root;
}

int main(){
    TreeNode *root = initTree();
    vector<int> res = preorderTraversal(root);
    cout<<"Preorder Traversal: ";
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}