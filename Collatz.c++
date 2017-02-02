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

// ------------
// collatz_read
// ------------

int collatz_read (istream& r) {
    int n;
    r >> n;
    assert(n > 0);
    return n;}

// ------------
// collatz_eval
// ------------

int collatz_eval (long long num) {
    // <your code>
    int cycle_length;
    long long check = 0;
    long long placeholder;
    int max_length = 0;
    int ans;

    while(check<=num){
        cycle_length = 0;
        placeholder = check;
        while(placeholder > 1){
            if(placeholder%2==0){
                placeholder = placeholder / 2;
                ++cycle_length;
            }
            else{
                placeholder = placeholder + (placeholder >> 1) + 1;         //Synonymous with (3*placeholder +1)/2
                ++++cycle_length;                
            }
        }
        if(cycle_length >= max_length){
            max_length = cycle_length;
            ans = check;            
        }
        ++check;
    }
    return ans;}

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
    int t;
    r >> t;
    for (int _ = 0; _ != t; ++_) {
        const int n = collatz_read(r);
        const int m = collatz_eval(n);
        collatz_print(w, m);}}
