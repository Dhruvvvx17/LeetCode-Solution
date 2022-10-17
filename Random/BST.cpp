// find distance between nodes of BST -> valkyrie trading test

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
 * Complete the 'BSTdistance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY values
 *  2. INTEGER nodeA
 *  3. INTEGER nodeB
 */
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *createNode(int val) {
    TreeNode *root = new TreeNode(val);
    return root;    
}

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

void inorder(TreeNode *root){
    if(!root)
        return;
    inorder(root->left);
    std::cout<<root->val<<" ";
    inorder(root->right);
    return;
}

bool nodeExists(TreeNode *root, int value) {    

    // negative base case
    if(root == nullptr)
        return false;
    
    // positive base case
    if(root->val == value)
        return true;
        
    return (nodeExists(root->left, value) || nodeExists(root->right, value));
}

TreeNode *findAncestor(TreeNode *root, int nodeA, int nodeB) {
    
    // null case
    if(!root)
        return nullptr;

    // found either of the nodes        
    if(root->val == nodeA || root->val == nodeB)
        return root;
    
    // recursively search left subtree
    TreeNode *left = findAncestor(root->left, nodeA, nodeB);
    
    // recursively search right subtree
    TreeNode *right = findAncestor(root->right, nodeA, nodeB);
    
    // if both nodes found, current node is ancestor
    if(left && right)
        return root;
        
    // if both nodes found in left
    if(left)
        return left;
        
    // if both nodes found in right
    else
        return right;
}

int findDist(TreeNode *root, int node_val, int level) {
    
    // end of tree
    if(!root)
        return -1;
        
    if(root->val == node_val)
        return level;
        
    int left = findDist(root->left, node_val, level+1);
    
    if(left != -1)
        return left;
        
    int right = findDist(root->right, node_val, level+1);
    
    return right;
    
    // return will not be -1 here as it has been confirmed that the node exists
}

int BSTdistance(std::vector<int> values, int nodeA, int nodeB) {
    
    // no BST to create or tree with one node
    if(values.empty() || values.size()==1) return -1;
    
    // if same nodes
    if(nodeA == nodeB) return 0;    
    
    TreeNode *root = createNode(values[0]);
    for(int i=1; i<values.size(); i++) {
        insertBST(root, values[i]);
    }
    
    // check insertion order
    // inorder(root); 
    
    // to check distance between the two nodes,
    // should find the lowest common ancestor and sum distance from ancestor to nodes
    TreeNode *ancestor = nullptr;
    
    if( nodeExists(root, nodeA) && nodeExists(root, nodeB)) {
        ancestor = findAncestor(root, nodeA, nodeB);
        // std::cout<<"Ancestor: "<<ancestor->val<<std::endl;
    }
    else {
        return -1;
    }
    
    // sum distance from ancestor to node1 and node2
    int d1 = findDist(ancestor, nodeA, 0);
    int d2 = findDist(ancestor, nodeB, 0);
    
    // std::cout<<"d1: "<<d1<<" d2: "<<d2<<std::endl;
    return d1 + d2;
}


// modify main
int main() {
    std::ofstream fout(std::getenv("OUTPUT_PATH"));

    std::string inputString;
    std::getline(std::cin, inputString);
    inputString.erase(std::remove(inputString.begin(), inputString.end(), ','), inputString.end());
    std::stringstream input(inputString);
    
    std::string vectorInputString;
    std::getline(input, vectorInputString, '{');
    std::getline(input, vectorInputString, '}');
    std::stringstream vectorInput(vectorInputString);
    
    int v;
    std::vector<int> values;
    while (vectorInput >> v)
        values.push_back(v);
    
    int nodeA;
    int nodeB;
    input >> nodeA;
    input >> nodeB;

    fout << BSTdistance(values, nodeA, nodeB);

    fout.close();

    return 0;
}