#include <iostream>
#include <string>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include "FibLFSR.hpp"
using namespace std;

FibLFSR::FibLFSR(string seed){
    if(seed.length() == 16){
        int i;
        bits = new int[16];
        if (bits != NULL){
        for(i = 0; (int)i < (int)seed.length(); i++){
            bits[i] = seed.at(i) - '0'; // atoi wasnt working
            }
        }
        }
        else{
            bits = NULL;
        }
} // constructor to create LFSR with the given initial seed and tap
int FibLFSR::step(){
    int i;
    if (bits != NULL){
    int copy_bits[16]; // new 16 bit number after step
    int newbit = ((bits[0]^bits[2])^bits[3])^bits[5];
    copy_bits[15] = newbit;
    for(i = 0; i < 15; i++){ // shifts bits
        copy_bits[i] = bits[i+1];
    }
     for(i = 0; i < 16; i++){ // copys new bit into Fiblfsr
        bits[i] = copy_bits[i];
    }
    return bits[14];
    }
    else return -1; // no bit string
} // simulate one step and return the new bit as 0 or 1
int FibLFSR::generate(int k){
if (bits != NULL && k > 0){
    int step_bit;
    int sum = 0;
    while(k > 0){
        step_bit = step();
        sum += (step_bit * pow(2, k-1));
        k--;
    }
    return sum;
    }
    else return -1; // no  valid bit string and/or invalid input int
} // simulate k steps and return k-bit integer
std::ostream& operator<< (std::ostream &out, const FibLFSR &FibLFSR)
{
    int i;
    for(i = 0; i < 16; i++){
    out << FibLFSR.bits[i];
    }
    return out;
}

