#include<iostream>
#include<vector>
using namespace std;

void DFS(int n){

    if(n==5)
        return;

    cout<<"n: "<<n<<endl;

    DFS(++n);
    return;
}

int main(int argc, char const *argv[])
{
    DFS(0);
    return 0;
}
