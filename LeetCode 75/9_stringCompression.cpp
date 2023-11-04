#include<iostream>
#include<vector>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();

    if(n==1) return 1;

    int res_position = 0;
    int chars_position = 0;

    while(chars_position < n){
        char c = chars[chars_position];
        int count = 1;

        while(chars_position < n-1 && chars[chars_position+1] == c){
            count++;
            chars_position++;
        }

        chars[res_position++] = c;

        if(count > 1){
            string countStr = to_string(count);
            for(auto digit : countStr){
                chars[res_position++] = digit;
            }
        }

        chars_position++;
    }
    return res_position;
}

int main() {

    vector<char> chars = {'a', 'a', 'b', 'b', 'b', 'c', 'd', 'd'};

    int end = compress(chars);

    for(int i = 0; i<end; i++){
        cout<<chars[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}