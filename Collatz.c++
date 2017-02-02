// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2017
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

using namespace std;

long long* cache;

// ------------
// collatz_read
// ------------

int collatz_read (istream& r) {
    int n;
    r >> n;
    assert(n > 0);
    return n;}

//Helper function for collatz_eval
long long collatz_help(long long x){
    if(x==1)
        return 0;
    if(x%2==0)
        return collatz_help(x/2)+1;
    else
        return(collatz_help(x + (x>>1) + 1) + 2);
}

// ------------
// collatz_eval
// ------------

int collatz_eval (long long num) {
    // <your code>
    long long start;
    long long max_length;
    int ans = 0;
    long long cycle_length;

    if(num == 0 || num == 1)
        return num;
    if(num >= 3732423)
        return 3732423;

    start = num/2+1;
    max_length = 0;
    
    for(long long i=start; i<=num; ++i){
        cycle_length = collatz_help(i);
        if(max_length <= cycle_length){
            ans = i;
            max_length = cycle_length;
        }
    }
    return ans;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int m) {
    assert(m > 0);
    w << m << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    cache = new long long[3750000]();
    int t;
    r >> t;
    for (int _ = 0; _ != t; ++_) {
        const int n = collatz_read(r);
        const int m = collatz_eval(n);
        collatz_print(w, m);}}
