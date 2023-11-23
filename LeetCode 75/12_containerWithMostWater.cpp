#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size()-1;
    int h, area = 0;

    while(left < right) {
        h = min(height[left], height[right]);
        area = max(area, h * (right-left));

        if(height[left]==h) left++;
        if(height[right]==h) right--;
    }

    return area;
}

int main() {

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int res = maxArea(height);

    cout<<"Max area: "<<res;

    return 0;
}