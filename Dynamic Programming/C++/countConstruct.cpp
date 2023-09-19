// Given a target string and a list of strings called wordBank, return the number of ways to construct the target string.
// using the wordBank. A word in the wordbank can be used multiple times.
// Brute force time complexity: O((n^m) * m) = O((branching factor ^ height) * string copying at remainingWord)
// Memoized time complexity: O(n * m * m) = O(unique recursive calls * string copying at remainingWord)
// Space complexity for both: O(m * m) = O(cache size at max * suffix string at every call)

#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<string, int64_t> cache;

int countConstruct(string target, vector<string> wordBank){

    if(target.empty()) return 1;

    if(cache.find(target) != cache.end()) return cache[target];

    int ways = 0;
    for(string word: wordBank){
        if(target.compare(0, word.size(), word) == 0){
            string remainingWord = target.substr(word.size());
            ways +=  countConstruct(remainingWord, wordBank);
        }
    }
    cache[target] = ways;
    return cache[target];
}


int main() {
    string target;
    cout<<"Enter target string: ";
    cin>>target;

    int n, iter=0;
    cout<<"Enter the number of words in wordbank: ";
    cin>>n;

    vector<string> wordBank;
    string temp;
    while(iter < n){
        cout<<"Enter word "<<iter<<": ";
        cin>>temp;
        wordBank.push_back(temp);
        ++iter;
    }    

    int64_t res = countConstruct(target, wordBank);

    if(res > 0)
        cout<<target<<" can be constructed in "<<res<<" ways"<<endl;
    else
        cout<<target<<" cannot be constructed"<<endl;

    return 0;
}