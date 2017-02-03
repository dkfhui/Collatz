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

long long cycle_cache[74];

void init_cache(){

    cycle_cache[0] = 35655;
    cycle_cache[1] = 77031;
    cycle_cache[2] = 142587;
    cycle_cache[3] = 156159;
    cycle_cache[4] = 230631;
    cycle_cache[5] = 230631;
    cycle_cache[6] = 230631;
    cycle_cache[7] = 230631;
    cycle_cache[8] = 410011;
    cycle_cache[9] = 410011;
    cycle_cache[10] = 511935;
    cycle_cache[11] = 511935;
    cycle_cache[12] = 626331;
    cycle_cache[13] = 626331;
    cycle_cache[14] = 626331;
    cycle_cache[15] = 626331;
    cycle_cache[16] = 837799;
    cycle_cache[17] = 837799;
    cycle_cache[18] = 837799;
    cycle_cache[19] = 837799;
    cycle_cache[20] = 837799;
    cycle_cache[21] = 837799;
    cycle_cache[22] = 1126015;
    cycle_cache[23] = 1126015;
    cycle_cache[24] = 1126015;
    cycle_cache[25] = 1126015;
    cycle_cache[26] = 1126015;
    cycle_cache[27] = 1126015;
    cycle_cache[28] = 1126015;
    cycle_cache[29] = 1126015;
    cycle_cache[30] = 1501353;
    cycle_cache[31] = 1564063;
    cycle_cache[32] = 1564063;
    cycle_cache[33] = 1564063;
    cycle_cache[34] = 1723519;
    cycle_cache[35] = 1723519;
    cycle_cache[36] = 1723519;
    cycle_cache[37] = 1723519;
    cycle_cache[38] = 1723519;
    cycle_cache[39] = 1723519;
    cycle_cache[40] = 1723519;
    cycle_cache[41] = 1723519;
    cycle_cache[42] = 1723519;
    cycle_cache[43] = 1723519;
    cycle_cache[44] = 2298025;
    cycle_cache[45] = 2298025;
    cycle_cache[46] = 2298025;
    cycle_cache[47] = 2298025;
    cycle_cache[48] = 2298025;
    cycle_cache[49] = 2298025;
    cycle_cache[50] = 2298025;
    cycle_cache[51] = 2298025;
    cycle_cache[52] = 2298025;
    cycle_cache[53] = 2298025;
    cycle_cache[54] = 2298025;
    cycle_cache[55] = 2298025;
    cycle_cache[56] = 2298025;
    cycle_cache[57] = 2298025;
    cycle_cache[58] = 2298025;
    cycle_cache[59] = 2298025;
    cycle_cache[60] = 3064033;
    cycle_cache[61] = 3064033;
    cycle_cache[62] = 3064033;
    cycle_cache[63] = 3064033;
    cycle_cache[64] = 3064033;
    cycle_cache[65] = 3064033;
    cycle_cache[66] = 3064033;
    cycle_cache[67] = 3064033;
    cycle_cache[68] = 3064033;
    cycle_cache[69] = 3542887;
    cycle_cache[70] = 3542887;
    cycle_cache[71] = 3542887;
    cycle_cache[72] = 3542887;
    cycle_cache[73] = 3732423;
}

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
    if(x==1 || x==0)
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
    /*long long start;
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
    return ans;*/

    long long block = num/50000;
    long long start;
    long long cycle_length = num;
    int ans = 0;
    long long max_length = 0;

    if(num == 0 || num == 1)
        return num;
    if(num >= 3732423)
        return 3732423;

    /*if(block==0)
        start = num/2+1;
    else
        start = num/2+1;*/
    start = num/2+1;

    if(num >= cycle_cache[block]){
        return cycle_cache[block];
    }
    else{
        for(long long i=start; i<=num; ++i){
            cycle_length = collatz_help(i);
            if(max_length <= cycle_length){
                ans = i;
                max_length = cycle_length;
            }
        }
        return ans;
    }
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
    init_cache();

    int t;
    r >> t;
    for (int _ = 0; _ != t; ++_) {
        const int n = collatz_read(r);
        const int m = collatz_eval(n);
        collatz_print(w, m);}}
