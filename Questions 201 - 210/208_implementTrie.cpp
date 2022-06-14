#include<iostream>
#include<vector>
using namespace std;

class TrieNode {

    public:
        // a trieNode is a custom data structure
        // that has an array of 26 pointers for a-z
        // and a bool indicating if it is a leaf or not.
        TrieNode *next[26];
        bool isLeaf;
    
        TrieNode() {
            for(int i=0; i<26; i++) {
                next[i] = NULL;
            }
            isLeaf = false;
        }
};

class Trie {

    TrieNode *root;

    public: 
        Trie() {
            root = new TrieNode();
        }

        ~Trie(){
            clear(root);
        }

        // method to insert new word in trie
        void insert(string word) {
            TrieNode *p = root;
            int index;
            for(int i=0; i<word.size(); i++) {
                index = word[i]-'a';

                // create new TrieNode as current letter points to NULL
                if(!p->next[index])
                    p->next[index] = new TrieNode();

                // move on to the next node based on current letter
                p = p->next[index];
            }
            // end of word => mark isLeaf as true
            p->isLeaf = true;
        }

        // method to search if word exists in trie
        bool search(string word) {
            TrieNode *p = find(word);
            return (p!=NULL && p->isLeaf) ? true : false;
        }

        // method to search if the prefix word exists in trie
        bool startsWith(string word) {
            TrieNode *p = find(word);
            return (p!=NULL) ? true : false;
        }

    private:
        // helper method to traverse the trie for given word
        TrieNode *find(string word) {
            TrieNode *p = root;
            int index;
            for(int i=0; i<word.size(); i++) {
                index = word[i]-'a';

                // if current letter does exists in trie
                if(!p->next[index])
                    return NULL;

                p = p->next[index];
            }
            return p;
        }

        // helper method to clear memory
        void clear(TrieNode *root){
            for(int i = 0; i < 26; i++){
                if(root->next[i] != nullptr){
                    clear(root->next[i]);
                }
            }
            delete root;
        }
};

int main() {

    Trie *trie = new Trie();

    trie->insert("apple");
    cout<<"apple inserted"<<endl;
    if(trie->search("apple")){
        cout<<"apple exist"<<endl;
    }
    if(!trie->search("app")){
        cout<<"app does not exist"<<endl;
    }
    if(trie->startsWith("app")){
        cout<<"a word in trie starts with app"<<endl;
    }
    trie->insert("app");
    cout<<"app inserted"<<endl;
    if(trie->search("app")){
        cout<<"app exist"<<endl;
    }

    delete trie;

    return 0;
}