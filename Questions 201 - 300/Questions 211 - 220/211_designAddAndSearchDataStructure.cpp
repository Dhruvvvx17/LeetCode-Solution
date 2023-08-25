#include<iostream>
using namespace std;


// simple TrieNode class
class TrieNode {
public: 
    bool isLeaf;
    TrieNode *children[26];
    
    TrieNode() {
        isLeaf = false;
        for(int i=0; i<26; i++)
            children[i] = nullptr;
    }
};

class WordDictionary {    
private:
    TrieNode *root = new TrieNode();
    
    // search for a given word letter by letter,
    // if '.' is found go through all 26 characters to find valid characters.
    // recursively follow the characters and backtrack to find if word exists or not
    bool search(const char* word, TrieNode *p) {
        for(int i=0; word[i] && p; i++){
            char c = word[i];
            if(c != '.')
                p = p->children[c - 'a'];
            else {
                TrieNode *temp = p;
                for(int j=0; j<26; j++){
                    p = temp->children[j];
                    if(search(word+1+i, p)){
                        return true;
                    }
                }
            }
        }
        return p && p->isLeaf;
    }
    
public:
    WordDictionary() {
        
    }
    
    // insert word into trie
    void addWord(string word) {
        TrieNode *p = root;

        for(char c: word) {
            // check if letter is marked valid before
            if(p->children[c - 'a']==NULL) {
                p->children[c - 'a'] = new TrieNode();
            }
            // move further down the trie
            p = p->children[c - 'a'];
        }
        p->isLeaf = true;
        cout<<"Word "<<word<<" added successfully!"<<endl;
    }
    
    // call internal search function
    bool search(string word) {
        return search(word.c_str(), root);
    }
};

int main() {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("apple");
    obj->addWord("orange");

    if(obj->search("app"))
        cout<<"app found"<<endl;
    else
        cout<<"app not found"<<endl;

    if(obj->search("oran.e"))
        cout<<"oran.e found"<<endl;
    else
        cout<<"oran.e not found"<<endl;

    if(obj->search("app.."))
        cout<<"app.. found"<<endl;
    else
        cout<<"app.. not found"<<endl;

    return 0;
}