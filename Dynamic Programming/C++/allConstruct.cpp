// Given a target string and a list of strings called wordBank, return the number of ways to construct the target string.
// using the wordBank. A word in the wordbank can be used multiple times.
// The trick is to return {{}} when creating "" and {} when failing to create a word.
// Time complexity = polynomial as all combinations have to be generated

#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<string, vector<vector<string>>> cache;

vector<vector<string>> allConstruct(string target, vector<string> wordBank){

    // this is a true case, it is possible to create empty by not picking any word from wordBank
    // result would be an empty vector in a vector of vectors.
    if(target.empty()) {
        vector<vector<string>> ways = {{}};
        return ways;
    }

    if(cache.find(target) != cache.end()) return cache[target];

    // initialize ways for current target to be empty
    vector<vector<string>> totalWays = {};

    // iterate over all words in wordBank
    for(string word: wordBank){
        // if word is a prefix
        if(target.compare(0, word.size(), word) == 0){
            // find ways to make the suffix
            string remainingWord = target.substr(word.size());
            vector<vector<string>> currWays = allConstruct(remainingWord, wordBank);
            // for each way to make a suffix, prepend the current word to it as that creates target
            // this loop can iterate over {{}} as word can be appended to the inner sublist, indicating that {{}} means empty string was reached (i.e., target was generated)
            // this loop will not iterate over {} as it has no elements indicating there is no way to generate target when currWays is {}
            for(vector<string> ways: currWays){
                ways.emplace(ways.begin(), word);
                totalWays.push_back(ways);
            }
        }
    }

    cache[target] = totalWays;
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

    vector<vector<string>> res = allConstruct(target, wordBank);

    if(!res.empty()){
        cout<<target<<" can be constructed in : "<<res.size()<<" ways"<<endl;
        for(vector<string> list : res){
            for(string word : list){
                cout<<word<<" ";
            }
            cout<<endl;
        }       
        cout<<endl;         
    }
    else {
        cout<<target<<" cannot be constructed"<<endl;
    }

    return 0;
}