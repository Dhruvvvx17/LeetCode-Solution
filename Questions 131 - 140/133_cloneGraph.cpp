#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public: 
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        // create copy of first node and push to queue
        Node *copyNode = new Node(node->val, {});
        copies[node] = copyNode;

        // queue is for the original graph, it will contain next nodes to traverse
        queue<Node*> myQueue;
        myQueue.push(node);
        
        while(!myQueue.empty()) {
            Node *curr = myQueue.front();
            myQueue.pop();
            
            for(Node *neighbor : curr->neighbors) {
                // if copy is not yet found in map
                if(copies.find(neighbor) == copies.end()) {
                    
                    Node *copyNode = new Node(neighbor->val, {});
                    copies[neighbor] = copyNode;

                    myQueue.push(neighbor);
                }
                
                // to the current copy node neighbors add copy neighbors (added in previous for loop)
                copies[curr]->neighbors.push_back(copies[neighbor]);
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};

Node *initGraph(){
    Node *n1 = new Node(5);
    Node *n2 = new Node(7);
    Node *n3 = new Node(9);
    Node *n4 = new Node(11);

    n1->neighbors.insert(n1->neighbors.end(), {n2,n3});
    n2->neighbors.insert(n2->neighbors.end(), {n1,n3});
    n3->neighbors.insert(n3->neighbors.end(), {n1,n2,n4});
    n4->neighbors.insert(n4->neighbors.end(), {n3});
    
    return n1;
    /*
    1 - 2
    | /
    3 - 4
    */
}

// not the best way to verify graph copy, this just checks for hardcoded values not the relationships between nodes
bool verifyGraph(Node *head){
    if(head->val!=5  || head->neighbors[0]->val != 7 || head->neighbors[1]->val != 9 || head->neighbors[1]->neighbors[2]->val != 11)
        return false;
    else
        return true;
}

int main(){

    Solution *s = new Solution();
    Node *head = initGraph();
    Node *new_head = s->cloneGraph(head);

    if(verifyGraph(new_head))
        cout<<"Graph copy successful!"<<endl;
    else
        cout<<"Graph copy unsuccessful"<<endl;    

    return 0;
}