#include<iostream>
#include<vector>
using namespace std;

// the original numbers LSB is considers and result's LSB is set accordingly
// the original number is right shifted and result is left shifted
// this opposite movement results in the bits being mirrored
uint32_t reverseBits(uint32_t n) {
    
    // declare based on return type
    // assume the below res as 32 bit all zeros
    uint32_t res = 0;

    // iterate over all 32 bits
    for(int i=0; i<32; i++){
        
        // left shift -> add a 0 as new LSB
        res = res<<1;
        
        // if the original number's LSB is 1 then
        // update result's LSB to 1 (res++)
        if(n&1 == 1){
            res++;
        }
        
        // right shift -> original number's LSB has been handled
        // consider the left of LSB as new LSB for next iteration
        n = n>>1;
    }
    
    return res;
}

int main() {

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Reverse bit number: "<<reverseBits(n);

    return 0;
}