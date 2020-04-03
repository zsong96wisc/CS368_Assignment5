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

// TODO delete
void printDigits(vector<unsigned int> *newDigits) {

    cout << "Printing digits..." << endl;
    int numDigits = newDigits->size();

    for(int i = 0; i < numDigits; i++) {
        cout << newDigits->at(i);
    }

    cout << endl;
}




vector<unsigned int>* InfiniteInt::getDigits() {
    return digits;
}


InfiniteInt::InfiniteInt() : 
    digits(new vector<unsigned int>(1,0))
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
    // cout << "numDigits " << numDigits << endl;
    // for(int i = 0; i < numDigits; i++) {
    //     cout <<"value here=" << currDigits->at(i) << endl;
    // }

    // vector<unsigned int>* currDigits2 = this->digits;
    // int numDigits2 = currDigits2->size();

    // for(int k = 0; k < numDigits2; k++) {
    //     cout <<"value here of this original=" << currDigits2->at(k) << endl;
    // }

    if(this != &rhs) {
        // cout << "in here"<< endl;
        delete this->digits;

        vector<unsigned int>* newDigits = rhs.digits;
        int numDigits = newDigits->size();

        for(int i = 0; i < numDigits; i++) {
            this->digits->at(i) = newDigits->at(i);
        }
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

    vector<unsigned int>* currDigits = rhs.digits;
    int numDigits = currDigits->size();

    for(int i = 0; i < numDigits; i++) {
        os << currDigits->at(i);
    }

    return os;
}

// TODO
istream& operator>>(istream &is, InfiniteInt &rhs) {

    string inputString;
    is >> inputString;

    char currChar = '0';
    unsigned int currCharVal = 0;
    vector<unsigned int>* newDigits = new vector<unsigned int>;
    for(unsigned int i = 0; i < inputString.size(); i++) {
        currChar = inputString.at(i);
        // cout << "currChar = " << currChar << " " << endl;
        if(isdigit(currChar)) {
            // cout << "currChar = " << currChar << " " << endl;
            currCharVal = currChar - '0';
            newDigits->push_back(currCharVal);
        } else {
            cout << "Invalid entry" << endl;
            delete newDigits;
            return is;
        }
    }
    // delete old digits and add new ones
    delete rhs.digits;
    rhs.digits = newDigits;
    
    return is;
}

// done
bool operator<(const InfiniteInt &lhs, const InfiniteInt &rhs) {

    if(lhs.digits->size() < rhs.digits->size()) {
        return true;
    } else if (lhs.digits->size() > rhs.digits->size()) {
        return false;
    }

    if(InfiniteInt::compareDigitsOfEqualLength(lhs.digits, rhs.digits) == 2) {
        return true;
    }

    return false;
}

// done
bool operator>(const InfiniteInt &lhs, const InfiniteInt &rhs) {

    if(lhs.digits->size() > rhs.digits->size()) {
        return true;
    } else if (lhs.digits->size() < rhs.digits->size()) {
        return false;
    }

    if(InfiniteInt::compareDigitsOfEqualLength(lhs.digits, rhs.digits) == 1) {
        return true;
    }

    return false;
}

// done
bool operator<=(const InfiniteInt &lhs, const InfiniteInt &rhs) {

    return !(lhs > rhs);

}

// done
bool operator>=(const InfiniteInt &lhs, const InfiniteInt &rhs) {

    return !(lhs < rhs);

}


bool operator==(const InfiniteInt &lhs, const InfiniteInt &rhs) {
    if(lhs.digits->size() == rhs.digits->size() ) {
        if(InfiniteInt::compareDigitsOfEqualLength(lhs.digits, rhs.digits) == 0) {
            return true;
        }
    }
    return false;
}


bool operator!=(const InfiniteInt &lhs, const InfiniteInt &rhs) {
    return !(lhs == rhs);
}


InfiniteInt operator+(const InfiniteInt &lhs, const InfiniteInt &rhs) {
    // unsigned long long lhsVal = InfiniteInt::convertVectorToVal(lhs.digits);
    // unsigned long long rhsVal = InfiniteInt::convertVectorToVal(rhs.digits);

    // InfiniteInt newInt(lhsVal + rhsVal);

    // return newInt;
    return rhs;
}


InfiniteInt operator-(const InfiniteInt &lhs, const InfiniteInt &rhs) {
    // unsigned long long lhsVal = InfiniteInt::convertVectorToVal(lhs.digits);
    // unsigned long long rhsVal = InfiniteInt::convertVectorToVal(rhs.digits);
    // unsigned long long difference;
    // if (rhsVal >= lhsVal) {
    //     difference = 0;
    // } else {
    //     difference = lhsVal - rhsVal;
    // }
    // InfiniteInt newInt(difference);

    // return newInt;
    return rhs;
}


// TODO
InfiniteInt& InfiniteInt::operator+=(const InfiniteInt &rhs) {
    *this = *this + rhs;
    return *this;
}

// TODO
InfiniteInt& InfiniteInt::operator-=(const InfiniteInt &rhs) {
    *this = *this - rhs;
    return *this;
}

// TODO
// pre-fix ++InfiniteInt
InfiniteInt& InfiniteInt::operator++() {
    *this += 1;
    return *this;
}

// TODO
// pre-fix --InfiniteInt
InfiniteInt& InfiniteInt::operator--() {
    *this -= 1;
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


/**
 * return 0, 1, or 2
 * 0 all chars are EQUAL
 * 1 left hand side (LHS) is bigger
 * 2 right hand side is bigger
*/
int InfiniteInt::compareDigitsOfEqualLength(vector<unsigned int> *lhs, vector<unsigned int> *rhs) {
    int index = 0;
    int size = lhs->size();
    // cout << "size = " << size << endl;
    while(index < size) {
        //cout << "comparing lhsDigit = " << lhs->at(index) << " and rhsDigit = " << rhs->at(index) << endl;
        if(lhs->at(index) > rhs->at(index)) {
            return 1;
        } else if (lhs->at(index) < rhs->at(index)) {
            return 2;
        }
        index++;
    }
    return 0;
}


// helper method
vector<unsigned int>* InfiniteInt::convertValToVector(unsigned long long val) {

    vector<unsigned int> *newDigits = new vector<unsigned int>;

    // iterator to insert at the beginning of vector
    vector<unsigned int>::iterator itr;

    itr = newDigits->begin();

    // cout << "val = " << val << endl;
    // cout << "radix = " << radix << endl;
    unsigned int currInt = 0;

    while (val != 0) {
        currInt = val % 10;

        itr = newDigits->insert(itr,currInt);
        // cout << "currInt is = " << currInt << endl;
        // printDigits(newDigits);
        val = val / 10;
        itr = newDigits->begin();
    }

    // printDigits(newDigits);

    return newDigits;
}