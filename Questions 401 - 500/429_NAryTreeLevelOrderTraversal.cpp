#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// method declarations
Node *createTree();
vector<vector<int>> levelOrder(Node* root);
void store_integer_values(vector<Node*> next_level, vector<vector<int>> &res);

int main() {

    Node *root = createTree();

    vector<vector<int>> res = levelOrder(root);

    for(vector<int> v: res){
        cout<<"New Level: ";
        for(int ele: v){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}

Node* createTree(){
    Node *level2_a = new Node(5);
    Node *level2_b = new Node(6);
    Node *level1_a = new Node(3, {level2_a, level2_b});
    Node *level1_b = new Node(2);
    Node *level1_c = new Node(4);
    Node *root = new Node(1, {level1_a, level1_b, level1_c});

    return root;
}

vector<vector<int>> levelOrder(Node* root){

    vector<vector<int>> res = {};

    // edge case: empty tree
    if(!root)
        return res;
    
    // first element is the root
    res = {{root->val}};

    // store the nodes for current level
    vector<Node*> current_level = {root};

    while(current_level.size() > 0){

        // store the nodes to next level
        vector<Node*> next_level;

        for(int i=0; i < current_level.size(); i++){
            vector<Node*> current_children = current_level[i]->children;
            next_level.insert(next_level.end(), current_children.begin(), current_children.end());
        }

        store_integer_values(next_level, res);
        current_level = next_level;
    }

    return res;
}

void store_integer_values(vector<Node*> next_level, vector<vector<int>> &res){
    if(next_level.size()>0){
        vector<int> next_level_int;
        for(Node* n: next_level){
            next_level_int.push_back(n->val);
        }
        res.push_back(next_level_int);
    }
}