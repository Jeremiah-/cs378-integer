// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair
#include <vector>

#include "gtest/gtest.h"

#include "Integer.h"

using namespace std;

// -----------
// TestInteger
// -----------


// ----
// shift_left_digits
// ----

TEST(IntegerFixture, shift_left1) {
    vector<int> testVector {1, 2, 3};
    vector<int> result;

    result = shift_left_digits(testVector.begin(), testVector.end(), 1, result);
    ASSERT_EQ(result[0], 2);
    ASSERT_EQ(result[1], 3);
    ASSERT_EQ(result[2], 0);
}


TEST(IntegerFixture, shift_left2) {
    vector<int> testVector {1, 2, 3};
    vector<int> result;

    result = shift_left_digits(testVector.begin(), testVector.end(), 2, result);
    ASSERT_EQ(result[0], 3);
    ASSERT_EQ(result[1], 0);
    ASSERT_EQ(result[2], 0);
}



TEST(IntegerFixture, shift_left3) {
    vector<int> testVector {1, 2, 3};
    vector<int> result;

    result = shift_left_digits(testVector.begin(), testVector.end(), 3, result);
    ASSERT_EQ(result[0], 0);
    ASSERT_EQ(result[1], 0);
    ASSERT_EQ(result[2], 0);
}


// ----
// eval
// ----

TEST(IntegerFixture, shift_right1) {
    vector<int> testVector {1, 2, 3};
    vector<int> result;

    result = shift_right_digits(testVector.begin(), testVector.end(), 1, result);
    ASSERT_EQ(result[0], 0);
    ASSERT_EQ(result[1], 1);
    ASSERT_EQ(result[2], 2);
}

TEST(IntegerFixture, shift_right2) {
    vector<int> testVector {1, 2, 3};
    vector<int> result;

    result = shift_right_digits(testVector.begin(), testVector.end(), 2, result);
    ASSERT_EQ(result[0], 0);
    ASSERT_EQ(result[1], 0);
    ASSERT_EQ(result[2], 1);
}

TEST(IntegerFixture, shift_right3) {
    vector<int> testVector {1, 2, 3};
    vector<int> result;

    result = shift_right_digits(testVector.begin(), testVector.end(), 3, result);
    ASSERT_EQ(result[0], 0);
    ASSERT_EQ(result[1], 0);
    ASSERT_EQ(result[2], 0);
}




/*
% ls -al /usr/include/gtest/
...
gtest.h
...



% locate libgtest.a
/usr/lib/libgtest.a
...



% locate libpthread.a
...
/usr/lib32/libpthread.a



% locate libgtest_main.a
/usr/lib/libgtest_main.a
...



% g++-4.8 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -lpthread



% valgrind TestCollatz        >  TestCollatz.out 2>&1
% gcov-4.8 -b Collatz.c++     >> TestCollatz.out
% gcov-4.8 -b TestCollatz.c++ >> TestCollatz.out



% cat TestCollatz.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestCollatz
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Collatz
[ RUN      ] Collatz.read
[       OK ] Collatz.read (31 ms)
[ RUN      ] Collatz.eval_1
[       OK ] Collatz.eval_1 (5 ms)
[ RUN      ] Collatz.eval_2
[       OK ] Collatz.eval_2 (3 ms)
[ RUN      ] Collatz.eval_3
[       OK ] Collatz.eval_3 (3 ms)
[ RUN      ] Collatz.eval_4
[       OK ] Collatz.eval_4 (3 ms)
[ RUN      ] Collatz.print
[       OK ] Collatz.print (17 ms)
[ RUN      ] Collatz.solve
[       OK ] Collatz.solve (10 ms)
[----------] 7 tests from Collatz (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'Collatz.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Collatz.c++.gcov'
...
File 'TestCollatz.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestCollatz.c++.gcov'
...
*/