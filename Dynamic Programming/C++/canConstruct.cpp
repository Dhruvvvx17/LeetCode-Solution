// Given a target string and a list of strings called wordBank, return True if target string can be created using combinations
// of strings from the wordBank. A word in the wordbank can be used multiple times.
// Brute force time complexity: O((n^m) * m) = O((branching factor ^ height) * string copying at remainingWord)
// Memoized time complexity: O(n * m * m) = O(unique recursive calls * string copying at remainingWord)
// Space complexity for both: O(m * m) = O(cache size at max * suffix string at every call)

#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<string, bool> cache;

bool canConstruct(string target, vector<string> wordBank){

    // base case
    if(target.empty()) return true;

    if(cache.find(target) != cache.end()) return cache[target];

    // for every word check if its a prefix of target
    for(string word: wordBank){
        if(target.compare(0, word.size(), word) == 0){
            string remainingTarget = target.substr(word.size());
            // also check if the remaining string can be constructed
            if(canConstruct(remainingTarget, wordBank)){
                cache[target] = true;
                return true;
            }
        }
    }
    cache[target] = false;
    return false;
}


int main() {

    string target;
    cout<<"Enter target string: ";
    cin>>target;

    int n, iter=0;
    cout<<"Enter the number of words in wordback: ";
    cin>>n;

    vector<string> wordBank;
    string temp;
    while(iter < n){
        cout<<"Enter word "<<iter<<": ";
        cin>>temp;
        wordBank.push_back(temp);
        ++iter;
    }    

    if(canConstruct(target, wordBank))
        cout<<target<<" can be constructed"<<endl;
    else
        cout<<target<<" cannot be constructed"<<endl;
    
    return 0;
}