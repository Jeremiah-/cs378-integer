// -----------------------------------
// projects/c++/integer/RunInteger.c++
// Copyright (C) 2015
// Glenn P. Downing
// -----------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <deque>    // deque
#include <time.h>

#include "Integer.h"

// ----
// main
// ----

int main () {
    using namespace std;
    // clock_t t1, t2;
    cout << "RunInteger.c++" << endl << endl;

    // less than 500 ms
    cout << "*** 20th Mersenne prime: 1,332 digits ***" << endl << endl;

    {
    // t1 = clock();
    const Integer<int> n = Integer<int>(2).pow(4423) - 1;
    // t1 = clock() - t1;
    cout << "2^4423 - 1 = " << n << endl << endl;
    }

    {
    // t2 = clock();
    const Integer< int, std::deque<int> > n = Integer< int, std::deque<int> >(2).pow(4423) - 1;
    // t2 = clock() - t2;
    cout << "2^4423 - 1 = " << n << endl << endl;
    }

    // cout << "Time elapsed: " << ((float)(t1 + t2))/CLOCKS_PER_SEC << "s" << endl;

    // --------------------------
    // extra credit (5 bonus pts)
    // --------------------------

    // less than 4 min
    // cout << "*** 30th Mersenne prime: 39,751 digits ***" << endl << endl;

    // {
    // const Integer<int> n = Integer<int>(2).pow(132049) - 1;
    // cout << "2^132049 - 1 = " << n << endl << endl;
    // }

    cout << "Done." << endl;

    return 0;}