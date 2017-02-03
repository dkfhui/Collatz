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

int _maxInteger = 5000001;
int *_cache;
int _lastNumber = 1;

void initCache() {
  _cache = new int[_maxInteger](); // make sure initialized to 0's
  _lastNumber = 1;
}

int getLongestCollatz(int num) {
  int index = num;
  int max = _cache[num];
  for (int i = num; i >= 2; i--) {
    if (_cache[i] > max) {
      max = _cache[i];
      index = i;
    }
  }
  return index;
}

void calculateCollatz(long long x, int *steps) {
  if (x == 1)
    return;
  long long n;
  int lastStep = *steps;

  if ((x % 2) == 0) // even
  {
    (*steps) += 1; // increment 1 step for even number
    n = x / 2;     // divide by 2
  } else {
    *steps += 2; // increment 2 step for even number
    n = x + (x >> 1) + 1;
  }

  if (n < _maxInteger) {
    // try to see if we already cached the steps
    // if it is not 0, it is already calculated and cached
    int stepCalculated = _cache[n];
    if (stepCalculated > 0) {
      // we can simply added the calculated steps and return
      *steps += stepCalculated;
    } else
      calculateCollatz(n, steps);
  } else // the odd number mulitplier makes it exceeds maxNumber allows
  {
    calculateCollatz(n, steps);
  }
}

// ------------
// collatz_read
// ------------

int collatz_read(istream &r) {
  int n;
  r >> n;
  assert(n > 0);
  return n;
}

// Helper function for collatz_eval
long long collatz_help(long long x) {
  if (x == 1 || x == 0)
    return 0;
  if (x % 2 == 0)
    return collatz_help(x / 2) + 1;
  else
    return (collatz_help(x + (x >> 1) + 1) + 2);
}

// ------------
// collatz_eval
// ------------

int collatz_eval(int num) {
  // <your code>

  if (num == 0 || num == 1)
    return num;
  if (num >= 3732423)
    return 3732423;
  if (_lastNumber > num)
    return getLongestCollatz(num);

  int nextNumber = _lastNumber + 1;
  for (int i = num; i >= nextNumber; i--) {
    int step = 0;
    calculateCollatz((long long)i, &step);
    _cache[i] = step;
  }

  _lastNumber = num;
  return getLongestCollatz(num);
}

// -------------
// collatz_print
// -------------

void collatz_print(ostream &w, int m) {
  assert(m > 0);
  w << m << endl;
}

// -------------
// collatz_solve
// -------------

void collatz_solve(istream &r, ostream &w) {
  initCache();

  int t;
  r >> t;
  for (int _ = 0; _ != t; ++_) {
    const int n = collatz_read(r);
    const int m = collatz_eval(n);
    collatz_print(w, m);
  }
}
