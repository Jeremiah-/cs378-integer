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
#include <deque>

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

    shift_left_digits(testVector.begin(), testVector.end(), 1, result.begin());
    ASSERT_EQ(result[0], 2);
    ASSERT_EQ(result[1], 3);
    ASSERT_EQ(result[2], 0);
}


TEST(IntegerFixture, shift_left2) {
    vector<int> testVector {1, 2, 3};
    vector<int> result;

    shift_left_digits(testVector.begin(), testVector.end(), 2, result.begin());
    ASSERT_EQ(result[0], 3);
    ASSERT_EQ(result[1], 0);
    ASSERT_EQ(result[2], 0);
}



TEST(IntegerFixture, shift_left3) {
    vector<int> testVector {1, 2, 3};
    vector<int> result;

    shift_left_digits(testVector.begin(), testVector.end(), 3, result.begin());
    ASSERT_EQ(result[0], 0);
    ASSERT_EQ(result[1], 0);
    ASSERT_EQ(result[2], 0);
}


// ----
// shift_right_digits
// ----

TEST(IntegerFixture, shift_right1) {
    vector<int> testVector {1, 2, 3};
    vector<int> result;

    shift_right_digits(testVector.begin(), testVector.end(), 1, result.begin());
    ASSERT_EQ(result[0], 0);
    ASSERT_EQ(result[1], 1);
    ASSERT_EQ(result[2], 2);
}

TEST(IntegerFixture, shift_right2) {
    vector<int> testVector {1, 2, 3};
    vector<int> result;

    shift_right_digits(testVector.begin(), testVector.end(), 2, result.begin());
    ASSERT_EQ(result[0], 0);
    ASSERT_EQ(result[1], 0);
    ASSERT_EQ(result[2], 1);
}

TEST(IntegerFixture, shift_right3) {
    vector<int> testVector {1, 2, 3};
    vector<int> result;

    shift_right_digits(testVector.begin(), testVector.end(), 3, result.begin());
    ASSERT_EQ(result[0], 0);
    ASSERT_EQ(result[1], 0);
    ASSERT_EQ(result[2], 0);
}


// ----
// plus_digits
// ----

TEST(IntegerFixture, plus_digits1) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3};
    vector<int> result;

    plus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(result[0], 2);
    ASSERT_EQ(result[1], 4);
    ASSERT_EQ(result[2], 6);
}

TEST(IntegerFixture, plus_digits2) {
    vector<int> testVector1 {1, 2, 3, 4};
    vector<int> testVector2 {1, 2, 3};
    vector<int> result;

    plus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 3);
    ASSERT_EQ(result[2], 5);
    ASSERT_EQ(result[3], 7);
}

TEST(IntegerFixture, plus_digits3) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3, 4};
    vector<int> result;

    plus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 3);
    ASSERT_EQ(result[2], 5);
    ASSERT_EQ(result[3], 7);
}


// ----
// minus_digits
// ----

TEST(IntegerFixture, minus_digits1) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3};
    vector<int> result;

    minus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(result[0], 0);
}

TEST(IntegerFixture, minus_digits2) {
    vector<int> testVector1 {1, 2, 3, 4};
    vector<int> testVector2 {1, 2, 3};
    vector<int> result;

    minus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 1);
    ASSERT_EQ(result[2], 1);
    ASSERT_EQ(result[3], 1);
}

TEST(IntegerFixture, minus_digits3) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3, 4};
    vector<int> result;

    minus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 1);
    ASSERT_EQ(result[2], 1);
    ASSERT_EQ(result[3], 1);
}

// ----
// multiplies_digits
// ----

TEST(IntegerFixture, multiplies_digits1) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3};
    vector<int> result;

    multiplies_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 5);
    ASSERT_EQ(result[2], 1);
    ASSERT_EQ(result[3], 2);
    ASSERT_EQ(result[4], 9);
}

TEST(IntegerFixture, multiplies_digits2) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3, 4};
    vector<int> result;

    multiplies_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 5);
    ASSERT_EQ(result[2], 1);
    ASSERT_EQ(result[3], 7);
    ASSERT_EQ(result[4], 8);
    ASSERT_EQ(result[5], 2);
}

TEST(IntegerFixture, multiplies_digits3) {
    vector<int> testVector1 {1, 2, 3, 4};
    vector<int> testVector2 {1, 2, 3};
    vector<int> result;

    multiplies_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 5);
    ASSERT_EQ(result[2], 1);
    ASSERT_EQ(result[3], 7);
    ASSERT_EQ(result[4], 8);
    ASSERT_EQ(result[5], 2);
}


// ----
// divides_digits
// ----

TEST(IntegerFixture, divides_digits1) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3};
    vector<int> result;

    divides_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(result[0], 1);
    // ASSERT_EQ(result[1], 5);
    // ASSERT_EQ(result[2], 1);
    // ASSERT_EQ(result[3], 2);
    // ASSERT_EQ(result[4], 9);
}

TEST(IntegerFixture, divides_digits2) {
    vector<int> testVector1 {1, 2, 3, 4};
    vector<int> testVector2 {1, 2, 3};
    vector<int> result;

    divides_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 0);
    // ASSERT_EQ(result[2], 1);
    // ASSERT_EQ(result[3], 2);
    // ASSERT_EQ(result[4], 9);
}


TEST(IntegerFixture, divides_digits3) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3, 4};
    vector<int> result;

    divides_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(result[0], 0);
    // ASSERT_EQ(result[1], 0);
    // ASSERT_EQ(result[2], 1);
    // ASSERT_EQ(result[3], 2);
    // ASSERT_EQ(result[4], 9);
}

// ----
// equalequal
// ----

TEST(IntegerFixture, equalEqual1) {
    Integer<int> x (123);
    Integer<int> y (321);

    ASSERT_FALSE(x == y);
}

TEST(IntegerFixture, equalEqual2) {
    Integer<int> x (123);
    Integer<int> y (123);

    ASSERT_TRUE(x == y);
}

TEST(IntegerFixture, equalEqual3) {
    Integer<int> x (-123);
    Integer<int> y (123);

    ASSERT_FALSE(x == y);
}

TEST(IntegerFixture, equalEqual4) {
    Integer<int> x (123);
    Integer<int> y (-123);

    ASSERT_FALSE(x == y);
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
