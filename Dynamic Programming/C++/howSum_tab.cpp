// given a target an an array of non-negative integers, return a combination of values that sum up to the target value.
// the numbers can be used repeatedly. If no combination possible return NULL

//  Time: O(m * n * m)    (iterating through table * iterating through nums * copying array elements at a new location)


#include<iostream>
#include<vector>
using namespace std;

// method overloading for createVector()

// simply creates a new vector without any entries 
vector<int>* createVector(){
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

vector<int>* howSum_tab(int target, vector<int> arr) {
    // init a vector of vectors where each subvector has -1
    vector<vector<int>*> table(target+1, nullptr);

    // set the first element of the table to an empty vector
    table[0] = createVector();

    for(int i=0; i< table.size(); i++){
        // for valid/true positions
        if(table[i] != nullptr){
            // iterate over all possible shifts (i.e., arr values)
            for(int j=0; j<arr.size(); j++){
                // check for out of bounds
                if(i + arr[j] < table.size()){
                    // copy over the previous array at position i
                    table[i + arr[j]] = createVector(*table[i]);    // this step accounts for the last 'm' factor in time complexity
                    // insert the new element arr[j]
                    table[i + arr[j]]->push_back(arr[j]);
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

    vector<int> *res = howSum_tab(target, arr);

    if(res == nullptr)
        cout<<target<<" cannot be generated from array"<<endl;
    else {
        cout<<target<<" can be generated from array elements [ ";
        for(int num : *res){
            cout<<num<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}