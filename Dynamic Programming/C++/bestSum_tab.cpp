// given a target an an array of non-negative integers, return the smallest combination of values that sum up to the target value.
// the numbers can be used repeatedly. If no combination possible return NULL

#include<iostream>
#include<vector>
using namespace std;

vector<int>* createVector() {
    vector<int> *new_v = new vector<int>();
    return new_v;
}

// create a new vector and copies the values from the vector passed as parameter
vector<int>* createVector(vector<int> prev){
    vector<int> *new_v = new vector<int>();

    for(int x: prev){
        new_v->push_back(x);
    }
    return new_v;
}

// compare two vectors to see which is the shorter one
void compareAndProceed(vector<int> *potentialRes, vector<int> *originalRes, int ele){
    return;
}

vector<int>* bestSum_tab(int target, vector<int> arr) {
    // init a vector of vectors where each subvector is initially nullptr
    vector<vector<int>*> table(target+1, nullptr);

    table[0] = createVector();

    for(int i=0; i<table.size(); i++){
        // continue only for valid/true positions
        if(table[i] != nullptr){
            // iterate over all possible shifts (i.e., arr values)
            for(int j=0; j<arr.size(); j++) {

                // check for out of bounds
                if(i + arr[j] < table.size()){
                    // compare the length between the result at new position (if any) and the potential result in this iteration
                    // null -> no comparison simply copy, else compare size and copy if potential result is shorter
                    if(table[i + arr[j]] == nullptr 
                        || table[i + arr[j]]->size() > table[i]->size())
                    {
                        table[i + arr[j]] = createVector(*table[i]);
                        table[i + arr[j]]->push_back(arr[j]);
                    }
                }                
            }
        }
    }
    return table[target];
}


int main() {

    int n, iter = 1, temp, target;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    vector<int> arr;
    while(iter <= n) {
        cout<<"Enter element "<<iter<<": ";
        cin>>temp;
        arr.push_back(temp);
        ++iter;
    }
    
    cout<<"Enter target: ";
    cin>>target;

    vector<int> *bestRes = bestSum_tab(target, arr);

    if(bestRes == nullptr)
        cout<<target<<" cannot be generated from array"<<endl;
    else {
        cout<<target<<" can be generated from array elements: ";
        for(int num : *bestRes){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}