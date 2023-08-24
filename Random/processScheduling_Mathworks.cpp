#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int getMax(int a, int b) {
    return (a>b) ? a : b;
}


// Time complexity = O(m)
// Space complexity = O(m)
int scheduleTime(vector<int> processes, int k) {

    int max_capacity = -1;
    for(int capacity: processes) {
        max_capacity = getMax(max_capacity, capacity);
    }

    vector<int> arr(max_capacity+1, 0);

    for(int capacity: processes) {
        arr[capacity] += 1;
    }

    int res = 0;

    // go right to left to get minimum time
    int index = max_capacity;

    while(index >=0 ){

        if(arr[index] > 0){

            int v = index * arr[index];

            // consume entire capacity
            if(v < k) {
                
                // reduce k
                k = k - v;

                // increment capacity at floor(index/2)
                int reduced_cap = floor(index/2);
                arr[reduced_cap] += 1;

                // increment time taken (result)
                res += arr[index];

                // set current index to 0, as it is completely used
                arr[index] = 0;
            }
            // can consume only partial capacity
            else {
                if( v % k == 0){
                    res += (k/index);
                    return res;
                }
                else {
                    res += (k/index) + 1;
                    return res;
                }
            }
        }
        --index;
    }

    return -1;
}



int main() {

    int n, k, t;
    vector<int> processes;

    cout<<"Enter number of processors: ";
    cin>>n;

    for(int i=1; i<=n; i++){
        cout<<"Enter processor "<<i<<" capacity: ";
        cin>>t;
        processes.push_back(t);
    }

    cout<<"Enter number of processes to schedule: ";
    cin>>k;

    int res = scheduleTime(processes, k);
    if(res == -1)
        cout<<"Cannot schedule the given processes!"<<endl;
    else
        cout<<"It will take "<<res<<" seconds to schedule given processes!"<<endl;

    return 0;
}