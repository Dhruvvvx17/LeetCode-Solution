#include<iostream>
#include<vector>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
        
    if(n==0 || n==1)
        return 0;

    vector<bool> primes(n,true);

    primes[0] = false;
    primes[1] = false;
    
    for(int i=0; i < sqrt(n); i++){
        if(primes[i]) {
            for(int j = i*i; j < n; j += i)
                primes[j] = false;
        }
    }
    
    return count(primes.begin(), primes.end(), true);
}

int main() {

    int n;
    cout<<"Enter value of n: ";
    cin>>n;

    cout<<"Number of primes between 1 and "<<n<<" : "<<countPrimes(n);

    return 0;
}
