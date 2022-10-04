#include<iostream>
#include<vector>
using namespace std;

struct TrieNode {
    vector<TrieNode*> arr = vector<TrieNode*>(26, NULL);
    bool isLeaf = false;
};

    
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {

    struct TrieNode *pNode =  new TrieNode;
    pNode->isLeaf = false;

    for (int i = 0; i < 26; i++)
        pNode->arr[i] = NULL;

    return pNode;
}

// Insert new word into trie
void insertWord(TrieNode *root, string word) {
    
    TrieNode *p = root;
    for(int i=0; i<word.size(); i++) {
        int index = word[i] - 'a';
        if(!p->arr[index]){
            p->arr[index] = getNode();
        }
        p = p->arr[index];
    }
    p->isLeaf = true;
}

void DFS(vector<vector<char>>& board, int i, int j, TrieNode *root, string word, vector<string>& result) {
    // check for out of bounds
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] == ' ')
        return;
    
    if(root->arr[board[i][j] - 'a'] != NULL) {
        word = word + board[i][j];
        root = root->arr[board[i][j] - 'a'];
        if(root->isLeaf != false){
            result.push_back(word);
            root->isLeaf = false;    
        }
        char c = board[i][j];
        board[i][j] = ' ';
        
        DFS(board, i+1, j, root, word, result);
        DFS(board, i, j+1, root, word, result);
        DFS(board, i-1, j, root, word, result);
        DFS(board, i, j-1, root, word, result);

        board[i][j] = c;
    }
}


vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    
    TrieNode *root = getNode();
    
    // construct trie
    for (string word : words){
        insertWord(root, word);
    }
    
    int rows, cols;
    rows = board.size();
    cols = board[0].size();
    
    vector<string> result;
    
    for(int i=0; i<board.size(); ++i) {
        for(int j=0; j<board[0].size(); ++j) {
            DFS(board, i, j, root, "", result);
        }
    }
    
    return result;  
}

int main() {

    vector<vector<char>> board = 
    {
        {'a', 'b', 'c', 'd'},
        {'a', 'b', 'c', 'd'},
        {'a', 'b', 'c', 'd'},
    };

    vector<string> words = {"abbbcd"};

    vector<string> res = findWords(board, words);  

    for (auto r: res){
        cout<<"Found: "<<r<<endl;
    }
    
    return 0;
}