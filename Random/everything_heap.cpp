#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v1 = {5,10,15,20,25,30,35,40};

    cout<<"All vector elements: "<<endl;
    for(int i=0; i<v1.size(); ++i){
        cout<<v1[i]<<" ";
    }
    cout<<endl;


    // convert vector into heap
    make_heap(v1.begin(), v1.end());
    
    // front() will return the largest element of the heap
    cout<<"Heap max: "<<v1.front()<<endl;

    cout<<"All heap elements: "<<endl;
    for(int i=0; i<v1.size(); ++i){
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    return 0;
}