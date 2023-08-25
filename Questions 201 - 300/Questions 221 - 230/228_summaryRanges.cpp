#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    
    vector<string> res;

    if(nums.size()==0) return res;
    
    int prev = nums[0];
    int curr, i = 1, range_dist = 1;
    string range = to_string(prev);
    
    while(i < nums.size()) {
        curr = nums[i];

        if(prev + 1 != curr) {
            
            // if range is single number avoid the '->'
            if(range_dist == 1) {
                // update result
                res.push_back(range);
            }
            else {                
                // update result
                range = range + "->" + std::to_string(prev);
                res.push_back(range);
            }

            // reset range
            range = std::to_string(curr);
            prev = curr;
            range_dist = 1;
        }

        else {
            prev = curr;
            range_dist++;
        }

        // update loop counter
        i++;
    }
    
    // finally update res based on range_dist
    if(range_dist == 1) res.push_back(range);
    else {
        range = range + "->" + std::to_string(prev);
        res.push_back(range);
    }
    
    return res;
}

int main() {

    int n, temp;
    cout<<"enter number of elements: ";
    cin>>n;

    vector<int> nums;

    cout<<"Enter array number: "<<endl;
    for(int i=0; i<n; i++) {
        cout<<"element "<<i<<" : ";
        cin>>temp;
        nums.push_back(temp);
    }

    vector<string> res = summaryRanges(nums);

    cout<<"Ranges in the given array: ";
    for(auto x: res){
        cout<<x<<" ";
    }

    return 0;
}