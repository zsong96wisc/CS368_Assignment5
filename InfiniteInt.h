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
// Online sources:   
//
////////////////////////////////////////////////////////////////////////////////

#ifndef INFINITEINT
#define INFINITEINT

#include <vector>
#include <iostream>

using namespace std;

class InfiniteInt {

    friend ostream& operator<<(ostream &os, const InfiniteInt &rhs);
    
    friend istream& operator>>(istream &is, const InfiniteInt &rhs);

    friend bool operator<(const InfiniteInt &lhs, const InfiniteInt &rhs);

    friend bool operator>(const InfiniteInt &lhs, const InfiniteInt &rhs);

    friend bool operator<=(const InfiniteInt &lhs, const InfiniteInt &rhs);

    friend bool operator>=(const InfiniteInt &lhs, const InfiniteInt &rhs);

    friend bool operator==(const InfiniteInt &lhs, const InfiniteInt &rhs);

    friend bool operator!=(const InfiniteInt &lhs, const InfiniteInt &rhs);

    friend InfiniteInt operator+(const InfiniteInt &lhs, const InfiniteInt &rhs);

    friend InfiniteInt operator-(const InfiniteInt &lhs, const InfiniteInt &rhs);

    public:

        vector<unsigned int>* getDigits();

        // default constructor
        InfiniteInt();

        InfiniteInt(unsigned long long val);

        explicit InfiniteInt(vector<unsigned int>* new_digits);

        // copy constructor
        InfiniteInt(const InfiniteInt &obj);

        InfiniteInt& operator=(const InfiniteInt &rhs);

        // deconstructor - free all allocated heap memory
        ~InfiniteInt();


        InfiniteInt& operator+=(const InfiniteInt&);

        InfiniteInt& operator-=(const InfiniteInt&);

        // pre-fix ++InfiniteInt
        InfiniteInt& operator++();

        // pre-fix --InfiniteInt
        InfiniteInt& operator--();

        // post-fix InfiniteInt++
        InfiniteInt operator++(int);

        // post-fix InfiniteInt++
        InfiniteInt operator--(int);


    private:
        vector<unsigned int>* convertValToVector(unsigned long long val);

        vector<unsigned int>* digits;
        const unsigned int radix = 10;
};

#endif