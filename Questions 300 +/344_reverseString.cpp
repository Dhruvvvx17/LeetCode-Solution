#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
    int n = s.size();
    char temp;
    for(int i = 0; i<n/2; ++i) {
        temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
    
    return;
}

int main() {

    int n;
    char temp;
    vector<char> s;

    cout<<"Enter number of characters: ";
    cin>>n;

    cout<<"Enter characters: "<<endl;
    for(int i=0; i<n; ++i) {
        cout<<"char "<<i<<": ";
        cin>>temp;
        s.push_back(temp);
    }

    reverseString(s);

    for(int i=0; i<n; ++i) {
        cout<<s[i]<<" ";
    }

    return 0;
}