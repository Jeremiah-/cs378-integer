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
    vector<int> correctVector {1, 2, 3, 0};
    vector<int> result(4);

    shift_left_digits(testVector.begin(), testVector.end(), 1, result.begin());
    ASSERT_EQ(correctVector, result);
}


TEST(IntegerFixture, shift_left2) {
    vector<int> testVector {1, 2, 3};
    vector<int> correctVector {1, 2, 3, 0, 0};
    vector<int> result(5);

    shift_left_digits(testVector.begin(), testVector.end(), 2, result.begin());
    ASSERT_EQ(correctVector, result);

}



TEST(IntegerFixture, shift_left3) {
    vector<int> testVector {1, 2, 3};
    vector<int> correctVector {1, 2, 3, 0, 0, 0};
    vector<int> result(6);

    shift_left_digits(testVector.begin(), testVector.end(), 3, result.begin());
    ASSERT_EQ(correctVector, result);

}

TEST(IntegerFixture, shift_left4) {
    vector<int> testVector {1, 2, 3};
    vector<int> correctVector {1, 2, 3};
    vector<int> result(3);

    shift_left_digits(testVector.begin(), testVector.end(), 0, result.begin());
    ASSERT_EQ(correctVector, result);

}


// ----
// shift_right_digits
// ----

TEST(IntegerFixture, shift_right1) {
    vector<int> testVector {1, 2, 3};
    vector<int> correctVector {1, 2};
    vector<int> result (2);

    shift_right_digits(testVector.begin(), testVector.end(), 1, result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, shift_right2) {
    vector<int> testVector {1, 2, 3};
    vector<int> correctVector {1};
    vector<int> result (1);

    shift_right_digits(testVector.begin(), testVector.end(), 2, result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, shift_right3) {
    vector<int> testVector {1, 2, 3};
    vector<int> correctVector {0};
    vector<int> result (1);

    shift_right_digits(testVector.begin(), testVector.end(), 3, result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, shift_right4) {
    vector<int> testVector {1, 2, 3};
    vector<int> correctVector {1, 2, 3};
    vector<int> result (3);

    shift_right_digits(testVector.begin(), testVector.end(), 0, result.begin());
    ASSERT_EQ(correctVector, result);
}


// ----
// plus_digits
// ----

TEST(IntegerFixture, plus_digits1) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3};
    vector<int> correctVector {2, 4, 6};
    vector<int> result (3);

    plus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, plus_digits2) {
    vector<int> testVector1 {1, 2, 3, 4};
    vector<int> testVector2 {1, 2, 3};
    vector<int> correctVector {1, 3, 5, 7};
    vector<int> result (4);

    plus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, plus_digits3) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3, 4};
    vector<int> correctVector {1, 3, 5, 7};
    vector<int> result (4);

    plus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, plus_digits4) {
    vector<int> testVector1 {9, 9, 9};
    vector<int> testVector2 {9, 9, 9};
    vector<int> correctVector {1, 9, 9, 8};
    vector<int> result (4);

    plus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, plus_digits5) {
    vector<int> testVector1 {9, 9, 9, 9, 9, 9, 9, 9, 9};
    vector<int> testVector2 {9, 9, 9};
    vector<int> correctVector {1,0,0,0,0,0,0,9,9,8};
    vector<int> result (10);

    plus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, plus_digits6) {
    vector<int> testVector1 {1,2,3,4,5,6,7,8,9};
    vector<int> testVector2 {1};
    vector<int> correctVector {1,2,3,4,5,6,7,9,0};
    vector<int> result (9);

    plus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, plus_digits7) {
    vector<int> testVector1 {0};
    vector<int> testVector2 {0};
    vector<int> correctVector {0};
    vector<int> result (1);

    plus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

// ----
// minus_digits
// ----

TEST(IntegerFixture, minus_digits1) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3};
    vector<int> correctVector {0};
    vector<int> result (1);

    minus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, minus_digits2) {
    vector<int> testVector1 {1, 2, 3, 4};
    vector<int> testVector2 {1, 2, 3};
    vector<int> correctVector {1, 1, 1, 1};
    vector<int> result (4);

    minus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, minus_digits3) {
    vector<int> testVector1 {0};
    vector<int> testVector2 {0};
    vector<int> correctVector {0};
    vector<int> result (1);

    minus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, minus_digits4) {
    vector<int> testVector1 {4,1,2,3};
    vector<int> testVector2 {7,8,9};
    vector<int> correctVector {3,3,3,4};
    vector<int> result (4);

    minus_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}


// ----
// multiplies_digits
// ----

TEST(IntegerFixture, multiplies_digits1) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3};
    vector<int> correctVector {1, 5, 1, 2, 9};
    vector<int> result (5);

    multiplies_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, multiplies_digits2) {
    vector<int> testVector1 {1, 2, 3};
    vector<int> testVector2 {1, 2, 3, 4};
    vector<int> correctVector {1,5,1,7,8,2};
    vector<int> result (6);

    multiplies_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, multiplies_digits3) {
    vector<int> testVector1 {1, 2, 3, 4};
    vector<int> testVector2 {1, 2, 3};
    vector<int> correctVector {1,5,1,7,8,2};
    vector<int> result (6);

    multiplies_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, multiplies_digits4) {
    vector<int> testVector1 {0};
    vector<int> testVector2 {0};
    vector<int> correctVector {0};
    vector<int> result (1);

    multiplies_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

TEST(IntegerFixture, multiplies_digits5) {
    vector<int> testVector1 {1,2,3,4,5,6,7,8,9};
    vector<int> testVector2 {0};
    vector<int> correctVector {0};
    vector<int> result (1);

    multiplies_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
    ASSERT_EQ(correctVector, result);
}

// ----
// divides_digits
// ----

// TEST(IntegerFixture, divides_digits1) {
//     vector<int> testVector1 {1, 2, 3};
//     vector<int> testVector2 {1, 2, 3};
//     vector<int> correctVector {1};
//     vector<int> result (1);

//     divides_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
//     ASSERT_EQ(correctVector, result);
// }

// TEST(IntegerFixture, divides_digits2) {
//     vector<int> testVector1 {1, 2, 3, 4};
//     vector<int> testVector2 {1, 2, 3};
//     vector<int> correctVector {1,0};
//     vector<int> result (2);

//     divides_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
//     ASSERT_EQ(correctVector, result);
// }


// TEST(IntegerFixture, divides_digits3) {
//     vector<int> testVector1 {1, 2, 3};
//     vector<int> testVector2 {1, 2, 3, 4};
//     vector<int> correctVector {0};
//     vector<int> result (1);

//     divides_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
//     ASSERT_EQ(correctVector, result);
// }

// TEST(IntegerFixture, divides_digits5) {
//     vector<int> testVector1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     vector<int> testVector2 {1, 2, 3, 4};
//     vector<int> correctVector {1,0,0,0,4,6};
//     vector<int> result (6);

//     divides_digits(testVector1.begin(), testVector1.end(), testVector2.begin(), testVector2.end(), result.begin());
//     ASSERT_EQ(correctVector, result);
// }

// ----
// equalequal
// ----

TEST(IntegerFixture, equalEqual1) {
    Integer<int> x = 123;
    Integer<int> y = 321;

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

TEST(IntegerFixture, equalEqual5) {
    Integer<int> x (-123);
    Integer<int> y (-123);

    ASSERT_TRUE(x == y);
}

// ----
// less_than
// ----

TEST(IntegerFixture, lessThan1) {
    Integer<int> x (123);
    Integer<int> y (321);

    ASSERT_TRUE(x < y);
}

TEST(IntegerFixture, lessThan2) {
    Integer<int> x (123);
    Integer<int> y (321);

    ASSERT_FALSE(y < x);
}

TEST(IntegerFixture, lessThan3) {
    Integer<int> x (123);
    Integer<int> y (-321);

    ASSERT_FALSE(x < y);
}

TEST(IntegerFixture, lessThan4) {
    Integer<int> x (123);
    Integer<int> y (-321);

    ASSERT_TRUE(y < x);
}


TEST(IntegerFixture, lessThan5) {
    Integer<int> x (123);
    Integer<int> y (-4321);

    ASSERT_TRUE(y < x);
}

TEST(IntegerFixture, lessThan6) {
    Integer<int> x (0);
    Integer<int> y (0);

    ASSERT_FALSE(y < x);
}

TEST(IntegerFixture, lessThan7) {
    Integer<int> x (-54321);
    Integer<int> y (-321);

    ASSERT_FALSE(y < x);
}

TEST(IntegerFixture, lessThan8) {
    Integer<int> x (-123);
    Integer<int> y (-321);

    ASSERT_TRUE(y < x);
}

TEST(IntegerFixture, lessThan9) {
    Integer<int> x (-54321);
    Integer<int> y (-321);

    ASSERT_TRUE(x < y);
}

TEST(IntegerFixture, lessThan10) {
    Integer<int> x (123);
    Integer<int> y (-4321);

    ASSERT_FALSE(x < y);
}

// ----
// outStream
// ----

TEST(IntegerFixture, outStream1) {
    ostringstream o;
    Integer<int> y (123);
    o << y;

    EXPECT_EQ("123", o.str());
}

TEST(IntegerFixture, outStream2) {
    ostringstream o;
    Integer<int> y (-123);
    o << y;

    EXPECT_EQ("-123", o.str());
}

TEST(IntegerFixture, outStream3) {
    ostringstream o;
    Integer<int> y (-123654789);
    o << y;

    EXPECT_EQ("-123654789", o.str());
}

// ----
// stringConstructor
// ----

TEST(IntegerFixture, sConstructor1) {
    Integer<int> x ("123");
    Integer<int> y (123);
    ASSERT_TRUE(x == y);
}

TEST(IntegerFixture, sConstructor2) {
    Integer<int> x ("123");
    Integer<int> y (123);
    ASSERT_TRUE(y == x);
}

TEST(IntegerFixture, sConstructor3) {
    Integer<int> x (0);
    Integer<int> y ("0");
    ASSERT_TRUE(x == y);
}

TEST(IntegerFixture, sConstructor4) {
    Integer<int> x ("123");
    Integer<int> y ("123");
    ASSERT_TRUE(y == x);
}

TEST(IntegerFixture, sConstructor5) {
    Integer<int> x ("123456");
    Integer<int> y ("123");
    ASSERT_FALSE(y == x);
}

TEST(IntegerFixture, sConstructor6) {
    Integer<int> x ("123456");
    Integer<int> y ("-123456");
    ASSERT_FALSE(x == y);
}

TEST(IntegerFixture, sConstructor7) {
    Integer<int> x ("-123456");
    Integer<int> y ("-123456");
    ASSERT_TRUE(x == y);
}

TEST(IntegerFixture, sConstructor8) {
    Integer<int> x ("0");
    Integer<int> y ("0");
    ASSERT_TRUE(x == y);
}


// ----
// plusEqual
// ----

TEST(IntegerFixture, plusEqual1) {
    Integer<int> x (123);
    Integer<int> y (123);
    Integer<int> correct (246);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual2) {
    Integer<int> x (123);
    Integer<int> y (-123);
    Integer<int> correct (0);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual3) {
    Integer<int> x (-123);
    Integer<int> y (123);
    Integer<int> correct (0);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual4) {
    Integer<int> x (-123);
    Integer<int> y (-123);
    Integer<int> correct (-246);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual5) {
    Integer<int> x (-12345);
    Integer<int> y (-123);
    Integer<int> correct (-12468);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual6) {
    Integer<int> x (12345);
    Integer<int> y (-123);
    Integer<int> correct (12222);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual7) {
    Integer<int> x (-12345);
    Integer<int> y (123);
    Integer<int> correct (-12222);
    x += y;
    ASSERT_TRUE(x == correct);
}


TEST(IntegerFixture, plusEqual8) {
    Integer<int> x (-123);
    Integer<int> y (-12345);
    Integer<int> correct (-12468);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual9) {
    Integer<int> x (123);
    Integer<int> y (-12345);
    Integer<int> correct (-12222);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual10) {
    Integer<int> x (-123);
    Integer<int> y (12345);
    Integer<int> correct (12222);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual11) {
    Integer<int> x (0);
    Integer<int> y (-12345);
    Integer<int> correct (-12345);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual12) {
    Integer<int> x (0);
    Integer<int> y (12345);
    Integer<int> correct (12345);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual13) {
    Integer<int> x (12345);
    Integer<int> y (0);
    Integer<int> correct (12345);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual14) {
    Integer<int> x (-12345);
    Integer<int> y (0);
    Integer<int> correct (-12345);
    x += y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, plusEqual15) {
    Integer<int> x (0);
    Integer<int> y (0);
    Integer<int> correct (0);
    x += y;
    ASSERT_TRUE(x == correct);
}

// ----
// minusEqual
// ----

TEST(IntegerFixture, minusEqual1) {
    Integer<int> x (123);
    Integer<int> y (123);
    Integer<int> correct (0);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual2) {
    Integer<int> x (123);
    Integer<int> y (-123);
    Integer<int> correct (246);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual3) {
    Integer<int> x (-123);
    Integer<int> y (123);
    Integer<int> correct (-246);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual4) {
    Integer<int> x (-123);
    Integer<int> y (-123);
    Integer<int> correct (0);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual5) {
    Integer<int> x (-123);
    Integer<int> y (-12345);
    Integer<int> correct (12222);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual6) {
    Integer<int> x (-123);
    Integer<int> y (12345);
    Integer<int> correct (-12468);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual7) {
    Integer<int> x (123);
    Integer<int> y (-12345);
    Integer<int> correct (12468);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual8) {
    Integer<int> x (-12345);
    Integer<int> y (-123);
    Integer<int> correct (-12222);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual9) {
    Integer<int> x (12345);
    Integer<int> y (-123);
    Integer<int> correct (12468);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual10) {
    Integer<int> x (-12345);
    Integer<int> y (123);
    Integer<int> correct (-12468);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual11) {
    Integer<int> x (0);
    Integer<int> y (-12345);
    Integer<int> correct (12345);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual12) {
    Integer<int> x (0);
    Integer<int> y (12345);
    Integer<int> correct (-12345);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual13) {
    Integer<int> x (12345);
    Integer<int> y (0);
    Integer<int> correct (12345);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual14) {
    Integer<int> x (-12345);
    Integer<int> y (0);
    Integer<int> correct (-12345);
    x -= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, minusEqual15) {
    Integer<int> x (0);
    Integer<int> y (0);
    Integer<int> correct (0);
    x -= y;
    ASSERT_TRUE(x == correct);
}


// ----
// timesEqual
// ----

TEST(IntegerFixture, timesEqual1) {
    Integer<int> x (123);
    Integer<int> y (123);
    Integer<int> correct (15129);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual2) {
    Integer<int> x (123);
    Integer<int> y (-123);
    Integer<int> correct (-15129);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual3) {
    Integer<int> x (-123);
    Integer<int> y (123);
    Integer<int> correct (-15129);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual4) {
    Integer<int> x (-123);
    Integer<int> y (-123);
    Integer<int> correct (15129);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual5) {
    Integer<int> x (-123);
    Integer<int> y (-12345);
    Integer<int> correct (1518435);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual6) {
    Integer<int> x (-123);
    Integer<int> y (12345);
    Integer<int> correct (-1518435);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual7) {
    Integer<int> x (123);
    Integer<int> y (-12345);
    Integer<int> correct (-1518435);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual8) {
    Integer<int> x (-12345);
    Integer<int> y (-123);
    Integer<int> correct (1518435);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual9) {
    Integer<int> x (12345);
    Integer<int> y (-123);
    Integer<int> correct (-1518435);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual10) {
    Integer<int> x (-12345);
    Integer<int> y (123);
    Integer<int> correct (-1518435);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual11) {
    Integer<int> x (0);
    Integer<int> y (-12345);
    Integer<int> correct (0);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual12) {
    Integer<int> x (0);
    Integer<int> y (12345);
    Integer<int> correct (0);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual13) {
    Integer<int> x (12345);
    Integer<int> y (0);
    Integer<int> correct (0);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual14) {
    Integer<int> x (-12345);
    Integer<int> y (0);
    Integer<int> correct (0);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual15) {
    Integer<int> x (0);
    Integer<int> y (0);
    Integer<int> correct (0);
    x *= y;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual16) {
    Integer<int> x (123);
    Integer<int> correct (15129);
    x *= x;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, timesEqual17) {
    Integer<int> x (123);
    Integer<int> correct (228886641);
    // std::cout <<"Before computation: " << x << std::endl;
    x *= x;
    // std::cout <<"actual number being computed once: " << x << std::endl;
    x *= x;
    // std::cout <<"actual number being computed twice: " << x << std::endl;
    ASSERT_TRUE(x == correct);
}

// ----
// divideEqual
// ----

// TEST(IntegerFixture, divideEqual1) {
//     Integer<int> x (123);
//     Integer<int> y (123);
//     ASSERT_EQ(1, x /= y);
// }

// TEST(IntegerFixture, divideEqual2) {
//     Integer<int> x (123);
//     Integer<int> y (-123);
//     ASSERT_EQ(-1, x /= y);
// }

// TEST(IntegerFixture, divideEqual3) {
//     Integer<int> x (-123);
//     Integer<int> y (123);
//     ASSERT_EQ(-1, x /= y);
// }

// TEST(IntegerFixture, divideEqual4) {
//     Integer<int> x (-123);
//     Integer<int> y (-123);
//     ASSERT_EQ(1, x /= y);
// }


// ----
// modulusEqual
// ----

// TEST(IntegerFixture, modulusEqual1) {
//     Integer<int> x (123);
//     Integer<int> y (123);
//     ASSERT_EQ(0, x %= y);
// }

// TEST(IntegerFixture, modulusEqual2) {
//     Integer<int> x (123);
//     Integer<int> y (-123);
//     ASSERT_EQ(0, x %= y);
// }

// TEST(IntegerFixture, modulusEqual3) {
//     Integer<int> x (-123);
//     Integer<int> y (123);
//     ASSERT_EQ(0, x %= y);
// }

// TEST(IntegerFixture, modulusEqual4) {
//     Integer<int> x (123456);
//     Integer<int> y (123);
//     ASSERT_EQ(87, x %= y);
// }

// TEST(IntegerFixture, modulusEqual5) {
//     Integer<int> x (123);
//     Integer<int> y (123456);
//     ASSERT_EQ(123, x %= y);
// }


// ----
// bitShiftLeftEqual
// ----

TEST(IntegerFixture, bitShiftLeftEqual1) {
    Integer<int> x (123);
    Integer<int> correct (1230);
    x <<= 1;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, bitShiftLeftEqual2) {
    Integer<int> x (123);
    Integer<int> correct (12300);
    x <<= 2;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, bitShiftLeftEqual3) {
    Integer<int> x (123);
    Integer<int> correct (123000);
    x <<= 3;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, bitShiftLeftEqual4) {
    Integer<int> x (123);
    Integer<int> correct (1230000);
    x <<= 4;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, bitShiftLeftEqual5) {
    Integer<int> x (123);
    Integer<int> correct (12300000);
    x <<= 5;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, bitShiftLeftEqual6) {
    Integer<int> x (123);
    Integer<int> correct (123);
    x <<= 0;
    ASSERT_TRUE(x == correct);
}

// ----
// bitShiftRightEqual
// ----

TEST(IntegerFixture, bitShiftRightEqual1) {
    Integer<int> x (12345);
    Integer<int> correct (1234);
    x >>= 1;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, bitShiftRightEqual2) {
    Integer<int> x (12345);
    Integer<int> correct (123);
    x >>= 2;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, bitShiftRightEqual3) {
    Integer<int> x (12345);
    Integer<int> correct (12);
    x >>= 3;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, bitShiftRightEqual4) {
    Integer<int> x (12345);
    Integer<int> correct (1);
    x >>= 4;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, bitShiftRightEqual5) {
    Integer<int> x (12345);
    Integer<int> correct (0);
    x >>= 5;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, bitShiftRightEqual6) {
    Integer<int> x (12345);
    Integer<int> correct (12345);
    x >>= 0;
    ASSERT_TRUE(x == correct);
}

// ----
// abs
// ----

TEST(IntegerFixture, abs1) {
    Integer<int> x (123);
    Integer<int> correct (123);
    x.abs();
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, abs2) {
    Integer<int> x (-123);
    Integer<int> correct (123);
    x.abs();
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, abs3) {
    Integer<int> x ("-123");
    Integer<int> correct (123);
    x.abs();
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, abs4) {
    Integer<int> x (0);
    Integer<int> correct (0);
    x.abs();
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, abs5) {
    Integer<int> x ("123");
    Integer<int> correct (123);
    x.abs();
    ASSERT_TRUE(x == correct);
}

// ----
// pow
// ----

TEST(IntegerFixture, pow1) {
    Integer<int> x (123);
    Integer<int> correct (123);
    x.pow(1);
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, pow2) {
    Integer<int> x (-123);
    Integer<int> correct (-123);
    x.pow(1);
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, pow3) {
    Integer<int> x (123);
    Integer<int> correct (15129);
    x.pow(2);
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, pow4) {
    Integer<int> x (-123);
    Integer<int> correct (15129);
    x.pow(2);
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, pow5) {
    Integer<int> x (123);
    Integer<int> correct (1860867);
    x.pow(3);
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, pow6) {
    Integer<int> x (-123);
    Integer<int> correct (-1860867);
    x.pow(3);
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, pow7) {
    Integer<int> x (123);
    Integer<int> correct (1);
    x.pow(0);
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, pow8) {
    Integer<int> x (-123);
    Integer<int> correct (1);
    x.pow(0);
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, pow9) {
    Integer<int> x (2);
    Integer<int> correct (33554432);
    x.pow(25);
    ASSERT_TRUE(x == correct);
}


// ----
// negate
// ----

TEST(IntegerFixture, negate1) {
    Integer<int> x (123);
    Integer<int> correct (-123);
    x = -x;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, negate2) {
    Integer<int> x (-123);
    Integer<int> correct (123);
    x = -x;
    ASSERT_TRUE(x == correct);
}

TEST(IntegerFixture, negate3) {
    Integer<int> x (0);
    Integer<int> correct (0);
    x = -x;
    ASSERT_TRUE(x == correct);
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
