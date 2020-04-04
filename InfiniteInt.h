////////////////////////////////////////////////////////////////////////////////
// Main File: InfiniteInt.h, demo.cpp
// This File: InfiniteInt.h
// Other Files: 	 InfiniteInt.h / InfiniteInt.cpp / demo.cpp
// Semester:         CS 368 Spring 2020
//
// Author:           Ethan Lengfeld
// Email:            elengfeld@wisc.edu
// CS Login:         lengfeld
//
//
// Online sources:   CS368_OperatorOverload slides
//
////////////////////////////////////////////////////////////////////////////////

#ifndef INFINITEINT
#define INFINITEINT

#include <iostream>
#include <vector>

using namespace std;

class InfiniteInt {

    /**
     * Print interger value of InfiniteInt
    **/
    friend ostream& operator<<(ostream &os, const InfiniteInt &rhs);
    
    /**
     * Input stream that allows user to enter infinite digits
     * to create InfiniteInt. Only allows digits and will not 
     * create InfiniteInt if non-digits are entered
    **/
    friend istream& operator>>(istream &is, InfiniteInt &rhs);

    /**
     * Return true if left hand side is LESS than
     * right hand side InfiniteInt, otherwise false
    **/
    friend bool operator<(const InfiniteInt &lhs, const InfiniteInt &rhs);

    /**
     * Return true if left hand side is GREATER than
     * right hand side InfiniteInt, otherwise false
    **/
    friend bool operator>(const InfiniteInt &lhs, const InfiniteInt &rhs);

    /**
     * Return true if left hand side is LESS than
     * or equal to right hand side InfiniteInt, otherwise false
    **/
    friend bool operator<=(const InfiniteInt &lhs, const InfiniteInt &rhs);

    /**
     * Return true if left hand side is GREATER than
     * or equal to right hand side InfiniteInt, otherwise false
    **/
    friend bool operator>=(const InfiniteInt &lhs, const InfiniteInt &rhs);

    /**
     * Return true if left hand side and right hand side
     * InfiniteInt are equal, otherwise false
    **/
    friend bool operator==(const InfiniteInt &lhs, const InfiniteInt &rhs);

    /**
     * Return true if left hand side and right hand side
     * InfiniteInt are not equal, otherwise false
    **/
    friend bool operator!=(const InfiniteInt &lhs, const InfiniteInt &rhs);

    /**
     * Return new InfinteInt that is equal to the sum
     * of left hand side and right hand side
    **/
    friend InfiniteInt operator+(const InfiniteInt &lhs, const InfiniteInt &rhs);

    /**
     * Return new InfinteInt that is equal to the difference
     * between left hand side and right hand side
    **/
    friend InfiniteInt operator-(const InfiniteInt &lhs, const InfiniteInt &rhs);

    public:

        /**
         * A getter function for retrieving the digits.
         * return - vector<unsigned int>* digits
        **/
        vector<unsigned int>* getDigits();

        /**
         * Default constructor for creating an InfiniteInt()
        **/
        InfiniteInt();

        /**
         * Create constructor with val parameter to 
         * set to digits
        **/
        InfiniteInt(unsigned long long val);

        /**
         * Create constructor for InfiniteInt that
         * sets digits to 
        **/
        explicit InfiniteInt(vector<unsigned int>* new_digits);

        /**
         * Copy constructor
        **/
        InfiniteInt(const InfiniteInt &obj);

        /**
         * Copy-assignment that will look to copy
         * passed in InfiniteInt into LHS InfiniteInt
        **/
        InfiniteInt& operator=(const InfiniteInt &rhs);

        /**
         * free all allocated heap memory
        **/
        ~InfiniteInt();

        /**
         * Overload operator that adds right hand side
         * from the left hand side and store in LHS
        **/
        InfiniteInt& operator+=(const InfiniteInt&);

        /**
         * Overload operator that subtracts right hand side
         * from the left hand side and store in LHS
        **/
        InfiniteInt& operator-=(const InfiniteInt&);

        /**
         * Pre-increment ++InfiniteInt that adds
         * 1  to current InfiniteInt  and returns
        **/
        InfiniteInt& operator++();

        /**
         * Pre-decrement --InfiniteInt that subtracts
         * 1  to current InfiniteInt  and returns
        **/
        InfiniteInt& operator--();

        /**
         * Post-increment InfiniteInt++ that adds
         * 1  to current InfiniteInt  and returns
         * the original InfiniteInt
        **/
        InfiniteInt operator++(int);

        /**
         * Post-decrement InfiniteInt-- that subtracts
         * 1  to current InfiniteInt  and returns
         * the original InfiniteInt
        **/
        InfiniteInt operator--(int);


    private:

        /**
         * return 0, 1, or 2
         * 0 all chars are equal
         * 1 left hand side is bigger
         * 2 right hand side is bigger
        */
        static int compareDigitsOfEqualLength(vector<unsigned int>* lhs, vector<unsigned int>* rhs);

        /**
         * Helper method to calculate the sum 
         * of two InfiniteInt and create new
         * digits vector
        **/
        static vector<unsigned int>* calculateSum(vector<unsigned int> *,vector<unsigned int> *, const unsigned int radix);
        
        /**
         * Take a long value and convert it into 
         * a digits vector with the base of radix
        **/        
        vector<unsigned int>* convertValToVector(unsigned long long val, const unsigned int radix);

        /**
         * Vector to store digits that will represent
         * the InfiniteInt.
        **/
        vector<unsigned int>* digits;
        
        /**
         * Represent base of number
        **/
        const unsigned int radix;
};

#endif