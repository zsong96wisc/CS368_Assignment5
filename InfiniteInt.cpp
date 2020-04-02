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
    digits(new vector<unsigned int>{0})
{}

InfiniteInt::InfiniteInt(unsigned long long val) :
    digits(convertValToVector(val))
{}

InfiniteInt::InfiniteInt(vector<unsigned int>* new_digits) :
    digits(new_digits)
{}

// copy constructor
InfiniteInt::InfiniteInt(const InfiniteInt &obj) :
    digits(obj.digits)
{}

InfiniteInt::~InfiniteInt() {
    delete InfiniteInt::digits;
}

InfiniteInt& InfiniteInt::operator=(const InfiniteInt &rhs) {
    return NULL;
}

ostream& operator<<(ostream &os, const InfiniteInt &rhs) {

    // InfiniteInt& nonconst = rhs;
//  vector<unsigned int>* currDigits = rhs.digits;

    // for (auto currDigit = currDigits->begin(); currDigit != currDigits->end(); currDigit++) {
    //     os << currDigit;
    // }

    return os;
}




// helper method
vector<unsigned int>* InfiniteInt::convertValToVector(unsigned long long val) {

    vector<unsigned int> *new_digits = new vector<unsigned int>;

    unsigned int currInt = 0;
    while(val != 0) {
        currInt = val % 10;
        // TODO delete
        cout << currInt;
        new_digits->push_back(currInt);
        val = val / 10;
    }
    // TOOD delete
    cout << endl;

    return new_digits;
}