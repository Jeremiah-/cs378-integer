// ------------------------------
// projects/c++/integer/Integer.h
// Copyright (C) 2015
// Glenn P. Downing
// ------------------------------

#ifndef Integer_h
#define Integer_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector
#include <deque>     // deque

// -----------------
// shift_left_digits
// -----------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * ([b, e) << n) => x
 */
template <typename II, typename FI>
FI shift_left_digits (II b, II e, int n, FI x) {
    x = std::copy(b, e, x);
    fill(x, x + n, 0);
    return x + n;}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * ([b, e) >> n) => x
 */
template <typename II, typename FI>
FI shift_right_digits (II b, II e, int n, FI x) {
    if(e - b < n){
        std::fill(x, x + 1, 0);
        x = x + 1;
    }
    else{
        x = std::copy(b, e - n, x);
    }
    return x;}

// -----------
// plus_digits
// -----------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the sum of the two input sequences into the output sequence
 * ([b1, e1) + [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    int size1 =  e1 - b1;
    int size2 = e2 - b2;

    int smallest_size = std::min(size1, size2);

    std::deque<int> result;
    int carry_num = 0;
    int counter = 0;
    // int back1 = size1 - 1;
    // int back2 = size2 - 1;
    --e1; --e2;
    while (smallest_size > counter) {
        int added_number = *e1 + *e2 + carry_num; // will never be over 18
        if (added_number > 9) {
            carry_num = added_number / 10;
            result.push_front(added_number % 10);
        } else {
            result.push_front(added_number);
            carry_num = 0;
        }
        ++counter;
        --e1; --e2;
    }
    if (e1 - b1 >= 0) {
        while (b1 - 1 != e1) {
            int added_number = *e1 + carry_num; // will never be over 18
            if (added_number > 9) {
                carry_num = 1;
                result.push_front(added_number % 10);
            } else {
                result.push_front(added_number);
                carry_num = 0;
            }
            --e1;
        }
    } else if (e2 - b2 >= 0) {
        while (b2 - 1 != e2) {
            int added_number = *e2 + carry_num; // will never be over 18
            if (added_number > 9) {
                carry_num = added_number / 10;
                result.push_front(added_number % 10);
            } else {
                result.push_front(added_number);
                carry_num = 0;
            }
            --e2;
        }
    }
    if(carry_num > 0){
        while(carry_num > 0){
            result.push_front(carry_num % 10);
            carry_num /= 10;
        }
    }
    
    x = std::copy(result.begin(), result.end(), x);

    // std::copy(ret.begin(), ret.end(), x);

    return x;}

// ------------
// minus_digits
// ------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the difference of the two input sequences into the output sequence
 * ([b1, e1) - [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    std::deque<int> result;
    --e1;
    --e2;
    bool borrowed = false;
    while(b1 - 1 != e1){
        int top = *e1;
        int bottom = 0;
        if(e2 - b2 >= 0){
            bottom = *e2; 
        }
        if(borrowed){
            ++bottom;
        }
        if(top < bottom){
            top += 10;
            borrowed = true;
        } else {
            borrowed = false;
        }
        result.push_front(top - bottom);
        --e1;
        if(e2 - b2 >= 0){
            --e2;
        }
        // if borrowed, do stuff
    }
    if(result[0] == 0){
        std::fill(x, x+1, 0);
        x += 1;
    } else {
        x = std::copy(result.begin(), result.end(), x);
    }
    
    return x;}

// -----------------
// multiplies_digits
// -----------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the product of the two input sequences into the output sequence
 * ([b1, e1) * [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    
    int first_size = e1 - b1;
    int second_size = e2 - b2;

    std::deque<int> result {0};

    std::deque<std::deque<int>> cache (10, std::deque<int>(first_size, 0));

    cache[0] = {0};
    std::copy(b1, e1, cache[1].begin());
    // std::cout << "size: " << cache[1].size() << std::endl;
    // std::cout << "cache at temp: " << cache[1].at(2) << std::endl;
    // for(int i = 0; i < cache[1].size(); i++){
    //     std::cout << "at " << i << " value is: " << cache[1].at(i) << std::endl;
    // }

    // initialize the cache with multiples of [b1, e1)
    // ex. for 123 * 24, cache[0] = 0. [1] = 12, [2] = 24, [3] = 36
    for(int i = 2; i < 10; i++){

        // this is to give the deque an extra space in case a new digit is added
        // ex. 99 + 1 = 100
        // make it -1 to help keep track of it
        cache[i].push_back(-1);

        // ERROR: this line is causing "Conditional jump or move depends on uninitialised value(s)"
        int j = i-1;
        
        plus_digits(b1, e1, cache[j].begin(), cache[j].end(), cache[i].begin());
        
        // if the space wasn't used, get rid of it.
        if (cache[i].back() == -1) {
            cache[i].pop_back();
        }
    }

    int shift = 0;
    std::deque<std::deque<int>> shifted_numbers (second_size, std::deque<int>());

    --e2;

    // this loop gets the first number * the current digit, and shifts it appropriately
    // for 123 * 243, cache[2] * 100, cache[4] * 10, cache[3]
    while(b2 - 1 != e2) {
        int num = *e2;

        // using shift just because. No reason
        // resize the deque to the size of the shifted number
        shifted_numbers[shift].resize(cache[num].size() + shift);
        for (int i = 0; i < shift; ++i) {
            shifted_numbers[shift].push_back(-1); // add in for space
        }


        shift_left_digits(cache[num].begin(), cache[num].end(), shift, shifted_numbers[shift].begin());




        // get rid of any unused space
        while (shifted_numbers[shift].back() == -1) {
            shifted_numbers[shift].pop_back();
        }
        // size is cache[num].size() + shift
        ++shift;
        --e2;
    }

    // make a temp to help with computation
    std::deque<int> temp = shifted_numbers[0];
    
    // this loop adds all the shifted numbers together, which produces the answer
    for (int i = 1; i < second_size; ++i) {
        // resize to the biggest of the ones that are going to be added
        result.resize(std::max(shifted_numbers[i - 1].size(), shifted_numbers[i].size()));
        
        // push for extra size
        result.push_back(-1);


        plus_digits(shifted_numbers[i].begin(), shifted_numbers[i].end(), temp.begin(), temp.end(), result.begin());
        
        // get rid of spaced if it is not used
        if (result.back() == -1) {
            result.pop_back();
        }

        // put result in temp so accumulate the actual result
        // resize the temp so result will fit in it
        temp.resize(result.size());
        std::copy(result.begin(), result.end(), temp.begin());
    }

    if (result[0] == 0) {
        result = {0};
    }
    x = std::copy(result.begin(), result.end(), x);
    return x;}

// --------------
// divides_digits
// --------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the division of the two input sequences into the output sequence
 * ([b1, e1) / [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    int int1 = 0;
    while(b1 != e1){
        int1 *= 10;
        int1 += *b1;
        ++b1;
    }
    int int2 = 0;
    while(b2 != e2){
        int2 *= 10;
        int2 += *b2;
        ++b2;
    }
    int num = int1 / int2;
    std::deque<int> ret;
    while(num > 0){
        ret.push_front(num % 10);
        num /= 10;
    }

    // std::copy(ret.begin(), ret.end(), x);
    return x;}

// -------
// Integer
// -------

template < typename T, typename C = std::vector<T> >
class Integer {
    // -----------
    // operator ==
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator == (const Integer& lhs, const Integer& rhs) {
        // <your code>
        if(lhs._x.size() != rhs._x.size() || lhs.is_neg != rhs.is_neg){
            return false;
        }
        for(int i = 0; i < lhs._x.size(); i++){
            if(lhs._x[i] != rhs._x[i]){
                return false;
            }
        }
        return true;}

    // -----------
    // operator !=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator != (const Integer& lhs, const Integer& rhs) {
        return !(lhs == rhs);}

    // ----------
    // operator <
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator < (const Integer& lhs, const Integer& rhs) {
        // <your code>
        if(lhs._x.size() > rhs._x.size() || (!lhs.is_neg && rhs.is_neg) ){
            return false;
        } else if (lhs._x.size() < rhs._x.size() || (lhs.is_neg && !rhs.is_neg) ){
            return true;
        } else {
            for(int i = 0; i < lhs._x.size(); i++){
                if(lhs._x[i] < rhs._x[i]){
                    return true;
                } else if (lhs._x[i] > rhs._x[i]){
                    return false;
                }
            }
        }
        return false;}

    // -----------
    // operator <=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator <= (const Integer& lhs, const Integer& rhs) {
        return !(rhs < lhs);}

    // ----------
    // operator >
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator > (const Integer& lhs, const Integer& rhs) {
        return (rhs < lhs);}

    // -----------
    // operator >=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator >= (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);}

    // ----------
    // operator +
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator + (Integer lhs, const Integer& rhs) {
        return lhs += rhs;}

    // ----------
    // operator -
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator - (Integer lhs, const Integer& rhs) {
        return lhs -= rhs;}

    // ----------
    // operator *
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator * (Integer lhs, const Integer& rhs) {
        return lhs *= rhs;}

    // ----------
    // operator /
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs == 0)
     */
    friend Integer operator / (Integer lhs, const Integer& rhs) {
        return lhs /= rhs;}

    // ----------
    // operator %
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs <= 0)
     */
    friend Integer operator % (Integer lhs, const Integer& rhs) {
        return lhs %= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator << (Integer lhs, int rhs) {
        return lhs <<= rhs;}

    // -----------
    // operator >>
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator >> (Integer lhs, int rhs) {
        return lhs >>= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     */
    friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
        // <your code>
        return lhs << "0";}

    // ---
    // abs
    // ---

    /**
     * absolute value
     * <your documentation>
     */
    friend Integer abs (Integer x) {
        return x.abs();}

    // ---
    // pow
    // ---

    /**
     * power
     * <your documentation>
     * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
     */
    friend Integer pow (Integer x, int e) {
        return x.pow(e);}

    private:
        // ----
        // data
        // ----

        C _x; // the backing container
        // <your data>


    private:
        // -----
        // valid
        // -----

        bool valid () const { // class invariant
            // <your code>
            return true;}
        bool is_neg = false;

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        Integer (int value) {
            // <your code>
            if(value < 0){
                is_neg = true;
                value = std::abs(value);
            }
            int result = 0;
            while(value > 0){
                result *= 10;
                result += value % 10;
                value /= 10;
            }
            int mod;
            while(result > 0){
                mod = result % 10;
                _x.push_back(mod);
                result -= mod;
                result /= 10;
            }
            assert(valid());}

        /**
         * <your documentation>
         * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
            // <your code>
            if (!valid())
                throw std::invalid_argument("Integer::Integer()");}

        // Default copy, destructor, and copy assignment.
        // Integer (const Integer&);
        // ~Integer ();
        // Integer& operator = (const Integer&);

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         */
        Integer operator - () const {
            // <your code>
            return Integer(0);}

        // -----------
        // operator ++
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator ++ () {
            *this += 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator += (const Integer& rhs) {
            // <your code>

            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -= (const Integer& rhs) {
            // <your code>
            // if (this.is_neg && rhs.is_neg) {
            //     // subtraction to smaller neg
            // } else if (!this.is_neg && rhs.is_neg) {
            //     // addition to bigger positive
            // } else if (this.is_neg && !rhs.is_neg) {
            //     // addition to bigger neg
            // } else { // both positive
            //     // subtraction to smaller postive
            // }
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator *= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator %=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            // <your code>
            return *this;}

        // ------------
        // operator <<=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator <<= (int n) {
            // <your code>
            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator >>= (int n) {
            // <your code>
            return *this;}

        // ---
        // abs
        // ---

        /**
         * absolute value
         * <your documentation>
         */
        Integer& abs () {
            // <your code>
            return *this;}

        // ---
        // pow
        // ---

        /**
         * power
         * <your documentation>
         * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
         */
        Integer& pow (int e) {
            // <your code>
            return *this;}};

#endif 
// Integer_h