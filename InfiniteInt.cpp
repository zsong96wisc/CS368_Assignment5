////////////////////////////////////////////////////////////////////////////////
// Main File: InfiniteInt.h, demo.cpp
// This File: InfiniteInt.cpp
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

#include "InfiniteInt.h"

vector<unsigned int>* InfiniteInt::getDigits() {
    return digits;
}


InfiniteInt::InfiniteInt() : 
    digits(new vector<unsigned int>)
{}

InfiniteInt::InfiniteInt(unsigned long long val) :
    digits(convertValToVector(val))
{}

InfiniteInt::InfiniteInt(vector<unsigned int>* new_digits) :
    digits(new_digits)
{}

// copy constructor
InfiniteInt::InfiniteInt(const InfiniteInt &obj) :
// TODO not sure
    digits(obj.digits)
{}

// TODO not sure
InfiniteInt& InfiniteInt::operator=(const InfiniteInt &rhs) {
    // vector<unsigned int>* currDigits = rhs.digits;
    // int numDigits = currDigits->size();

    // for(int i = 0; i < numDigits; i++) {
    //     cout <<"value here=" << currDigits->at(i) << endl;
    // }

    if(this != &rhs) {
        this->digits = rhs.digits;
    }

    // vector<unsigned int>* currDigits1 = this->digits;
    // int numDigits1 = currDigits1->size();

    // for(int j = 0;  j < numDigits1; j++) {
    //     cout <<"value here in this=" << currDigits1->at(j) << endl;
    // }

    return *this;
}

InfiniteInt::~InfiniteInt() {
    delete InfiniteInt::digits;
}

ostream& operator<<(ostream &os, const InfiniteInt &rhs) {
    //     vector<unsigned int>* currDigits1 = rhs.digits;
    // int numDigits1 = currDigits1->size();

    // for(int j = 0; j < numDigits1; j++) {
    //     cout <<"value here=" << currDigits1->at(j) << endl;
    // }

    vector<unsigned int>* currDigits = rhs.digits;

    //InfiniteInt::convertVectorToVal(currDigits);

    int numDigits = currDigits->size();
    //os << endl << "num digits = " << numDigits << endl;
    for(int i = 0; i < numDigits; i++) {
        os << currDigits->at(i);
    }

    return os;
}

// TODO
istream& operator>>(istream &is, const InfiniteInt &rhs) {

    return is;
}

// TODO - check
bool operator<(const InfiniteInt &lhs, const InfiniteInt &rhs) {

    return InfiniteInt::convertVectorToVal(lhs.digits) < InfiniteInt::convertVectorToVal(rhs.digits);
}

// TODO - check
bool operator>(const InfiniteInt &lhs, const InfiniteInt &rhs) {

    return InfiniteInt::convertVectorToVal(lhs.digits) > InfiniteInt::convertVectorToVal(rhs.digits);;
}

// TODO - check
bool operator<=(const InfiniteInt &lhs, const InfiniteInt &rhs) {

    return InfiniteInt::convertVectorToVal(lhs.digits) <= InfiniteInt::convertVectorToVal(rhs.digits);
}

// TODO - check
bool operator>=(const InfiniteInt &lhs, const InfiniteInt &rhs) {

    return InfiniteInt::convertVectorToVal(lhs.digits) >= InfiniteInt::convertVectorToVal(rhs.digits);
}

// TODO - check
bool operator==(const InfiniteInt &lhs, const InfiniteInt &rhs) {

    return InfiniteInt::convertVectorToVal(lhs.digits) == InfiniteInt::convertVectorToVal(rhs.digits);
}

// TODO - check
bool operator!=(const InfiniteInt &lhs, const InfiniteInt &rhs) {

    return !(lhs == rhs);
}

// TODO - check
InfiniteInt operator+(const InfiniteInt &lhs, const InfiniteInt &rhs) {
    unsigned long long lhsVal = InfiniteInt::convertVectorToVal(lhs.digits);
    unsigned long long rhsVal = InfiniteInt::convertVectorToVal(rhs.digits);

    InfiniteInt newInt(lhsVal + rhsVal);

    return newInt;
}

// TODO - check
InfiniteInt operator-(const InfiniteInt &lhs, const InfiniteInt &rhs) {
    unsigned long long lhsVal = InfiniteInt::convertVectorToVal(lhs.digits);
    unsigned long long rhsVal = InfiniteInt::convertVectorToVal(rhs.digits);
    unsigned long long difference;
    if (rhsVal >= lhsVal) {
        difference = 0;
    } else {
        difference = lhsVal - rhsVal;
    }
    InfiniteInt newInt(difference);

    return newInt;
}

// TODO - check
InfiniteInt& InfiniteInt::operator+=(const InfiniteInt &rhs) {
    *this = *this + rhs;
    return *this;
}

// TODO - check
InfiniteInt& InfiniteInt::operator-=(const InfiniteInt &rhs) {
    *this = *this - rhs;
    return *this;
}

// TODO
// pre-fix ++InfiniteInt
InfiniteInt& InfiniteInt::operator++() {

    return *this;
}

// TODO
// pre-fix --InfiniteInt
InfiniteInt& InfiniteInt::operator--() {

    return *this;
}

// TODO
// post-fix InfiniteInt++
InfiniteInt InfiniteInt::operator++(int) {

    return *this;
}

// TODO
// post-fix InfiniteInt++
InfiniteInt InfiniteInt::operator--(int) {

    return *this;
}


// helper method
unsigned long long InfiniteInt::convertVectorToVal(vector<unsigned int>* digits) {
    unsigned long long val = 0;

    int lastPos = (digits->size())-1;


    int base = 1;
    for(int i = lastPos; i >= 0; i--) {
        val += (base * digits->at(i));
        base *= 10;
    }
    // cout << "Here's the value I got from the vector = " << val;
    return val;
}


// helper method
vector<unsigned int>* InfiniteInt::convertValToVector(unsigned long long val) {

    vector<unsigned int> *new_digits = new vector<unsigned int>;

    // iterator to insert at the beginning of vector
    vector<unsigned int>::iterator itr;

    itr = new_digits->begin();

    unsigned int currInt = 0;
    while (val != 0) {
        currInt = val % 10;
        itr = new_digits->insert(itr,currInt);
        val = val / 10;
        itr = new_digits->begin();
    }

    return new_digits;
}