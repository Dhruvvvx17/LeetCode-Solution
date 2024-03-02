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

void helper(TreeNode *root, map<int, int> &map, int level) {

    if(root == nullptr) return;

    if(map.find(level) != map.end()) {
        map[level] += root->val;
    }
    else map[level] = root->val;

    helper(root->left, map, level+1);
    helper(root->right, map, level+1);
}

int maxLevelSum(TreeNode* root) {
        map<int, int> map;
        int res = INT_MAX;
        int res_sum = INT_MIN;

        helper(root, map, 1);

        for(auto x: map){
            // cout<<x.first<<" "<<x.second<<endl;
            if(x.second > res_sum) {
                res_sum = x.second;
                res = x.first;
            }
        }

        return res;
    }

int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);

    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    int res = maxLevelSum(root);

    cout<<"Max level sum at level: "<<res<<endl;
    
    return 0;
}