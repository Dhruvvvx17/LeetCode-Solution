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

void findPaths(TreeNode *root, string curr, vector<string>& paths) {
        if(root->left==NULL && root->right==NULL){
            paths.push_back(curr);
            return;
        }
        
        if(root->left != NULL)
            findPaths(root->left, curr+"->"+to_string(root->left->val), paths);
        
        if(root->right != NULL)
            findPaths(root->right, curr+"->"+to_string(root->right->val), paths);
        
        return;
    }
    
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    string curr = to_string(root->val);
    findPaths(root, curr, paths);
    
    return paths;
}

int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    
    vector<string> res = binaryTreePaths(root);

    cout<<"Root to leaf paths: "<<endl;
    for(string r: res){
        cout<<r<<endl;
    }

    return 0;
}