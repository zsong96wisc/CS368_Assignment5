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
// Online sources:   http://www.cplusplus.com/reference/vector/vector/erase/
//
////////////////////////////////////////////////////////////////////////////////

#include "InfiniteInt.h"

vector<unsigned int>* InfiniteInt::getDigits() {
    return digits;
}


InfiniteInt::InfiniteInt() {
    vector<unsigned int>* newDigits = new vector<unsigned int>;
    newDigits->push_back(0);
    digits = newDigits;
}


InfiniteInt::InfiniteInt(unsigned long long val) :
    digits(convertValToVector(val))
{}


InfiniteInt::InfiniteInt(vector<unsigned int>* new_digits) :
    digits(new_digits)
{}


// copy constructor
InfiniteInt::InfiniteInt(const InfiniteInt &obj) {

    vector<unsigned int>* copyDigits = new vector<unsigned int>;

    vector<unsigned int>* newDigits = obj.digits;
    int numDigits = newDigits->size();

    for(int i = 0; i < numDigits; i++) {
        copyDigits->push_back(newDigits->at(i));
    }
    
    digits = copyDigits;
}


InfiniteInt& InfiniteInt::operator=(const InfiniteInt &rhs) {

    if(this != &rhs) {
        delete this->digits;
        vector<unsigned int>* copyDigits = new vector<unsigned int>;
        vector<unsigned int>* newDigits = rhs.digits;
        int numDigits = newDigits->size();
        for(int i = 0; i < numDigits; i++) {
            copyDigits->push_back(newDigits->at(i));
        }
        this->digits = copyDigits;
    }

    return *this;
}

InfiniteInt::~InfiniteInt() {
    delete this->digits;
}


ostream& operator<<(ostream &os, const InfiniteInt &rhs) {

    vector<unsigned int>* currDigits = rhs.digits;
    int numDigits = currDigits->size();

    for(int i = 0; i < numDigits; i++) {
        os << currDigits->at(i);
    }

    return os;
}


istream& operator>>(istream &is, InfiniteInt &rhs) {

    string inputString;
    is >> inputString;

    vector<unsigned int>* newDigits = new vector<unsigned int>;
    char currChar = '0';
    unsigned int currCharVal = 0;
    for(unsigned int i = 0; i < inputString.size(); i++) {
        currChar = inputString.at(i);

        if(isdigit(currChar)) {
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


bool operator<=(const InfiniteInt &lhs, const InfiniteInt &rhs) {

    return !(lhs > rhs);

}


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
    vector<unsigned int> *sum;

    if (lhs.digits->size() >= rhs.digits->size()) {

        sum = InfiniteInt::calculateSum(lhs.digits, rhs.digits);

    } else {
        sum = InfiniteInt::calculateSum(rhs.digits, lhs.digits);
    }

    InfiniteInt sumInt(sum);

    return sumInt;
}


InfiniteInt operator-(const InfiniteInt &lhs, const InfiniteInt &rhs) {

    if(lhs <= rhs) {
        return InfiniteInt();
    }

    vector<unsigned int> *difference = new vector<unsigned int>;

    int sizeOfLHS = lhs.digits->size()-1;
    int indexOfRHS = rhs.digits->size()-1;

    unsigned int digitToAdd = 0;
    unsigned int varL = 0;
    unsigned int varR = 0;
    unsigned int carry = 0;
    vector<unsigned int>::iterator itr;

    itr = difference->begin();

    for(int indexOfLHS = sizeOfLHS; indexOfLHS >= 0; indexOfLHS--) {
        if(indexOfRHS == -1) {

            varL = lhs.digits->at(indexOfLHS);
            if (carry == 1) {
                if(varL == 0) {
                    varL = 9;
                    // cause it was 0, carry wasn't satisfied
                    carry = 1;
                } else {
                    varL -= 1;
                    carry = 0;
                }
            }
            digitToAdd = varL;

        } else {

            varL = lhs.digits->at(indexOfLHS);
            varR = rhs.digits->at(indexOfRHS);
            if (carry == 1) {
                if(varL == 0) {
                    varL = 9;
                    // cause it was 0, carry wasn't satisfied
                    carry = 1;
                } else {
                    varL -= 1;
                    carry = 0;
                }
            }

            if(varL >= varR) {
                digitToAdd = varL - varR;
            } else {
                digitToAdd = (varL + 10) - varR;
                carry = 1;
            }

            indexOfRHS--;

        }
        if(indexOfLHS != 0) {
            itr = difference->insert(itr,digitToAdd);
            itr = difference->begin();
        } else if (digitToAdd != 0) {
            itr = difference->insert(itr,digitToAdd);
            itr = difference->begin();
        }
        // printDigits(difference);
    }

    // remove extra zeros
    // auto it = difference->begin();
    // int index = 0;
    // while(it !=  difference->end()) {
    //     cout << *it << endl;
    //     if(*it == 0){
    //         difference->erase(difference->begin()+index);
    //     } else {
    //         break;
    //     }
    //     it++;
    //     index++;
    // }
    int size = difference->size();
    int numZeros = 0;
    for(int i = 0; i < size; i++) {
        if(difference->at(i) == 0) {
            numZeros++;
        } else {
            break;
        }
    }
    difference->erase(difference->begin(),difference->begin()+numZeros);

    InfiniteInt diffInt(difference);

    return diffInt;
}


InfiniteInt& InfiniteInt::operator+=(const InfiniteInt &rhs) {
    *this = *this + rhs;
    return *this;
}


InfiniteInt& InfiniteInt::operator-=(const InfiniteInt &rhs) {
    *this = *this - rhs;
    return *this;
}


// pre-fix ++InfiniteInt
InfiniteInt& InfiniteInt::operator++() {
    *this += 1;
    return *this;
}


// pre-fix --InfiniteInt
InfiniteInt& InfiniteInt::operator--() {
    *this -= 1;
    return *this;
}


// post-fix InfiniteInt++
InfiniteInt InfiniteInt::operator++(int) {
    InfiniteInt toReturn(*this);
    ++(*this);
    return toReturn;
}


// post-fix InfiniteInt++
InfiniteInt InfiniteInt::operator--(int) {
    InfiniteInt toReturn(*this);
    --(*this);
    return toReturn;
}


// ------------------ HELPER METHODS ---------------------------- //

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
vector<unsigned int>* InfiniteInt::calculateSum(vector<unsigned int> *lhs,vector<unsigned int> *rhs) {

    vector<unsigned int> *sum = new vector<unsigned int>;
    int indexOfLHS = lhs->size()-1;
    int indexOfRHS = rhs->size()-1;

    unsigned int digitToAdd = 0;
    unsigned int varL = 0;
    unsigned int varR = 0;
    unsigned int carry = 0;

    vector<unsigned int>::iterator itr;

    itr = sum->begin();
    for (; indexOfLHS >= 0; indexOfLHS--) {
        if(indexOfRHS == -1) {
            
            varL = lhs->at(indexOfLHS);
            digitToAdd = varL + carry;
            carry = 0;
            if (digitToAdd > 9) {
                digitToAdd = digitToAdd % 10;
                carry = 1;
            }

        } else {
            varL = lhs->at(indexOfLHS);
            varR = rhs->at(indexOfRHS);
            digitToAdd = varL + varR + carry;
            carry = 0;

            if (digitToAdd > 9) {
                digitToAdd = digitToAdd % 10;
                carry = 1;
            }
            indexOfRHS--;
        }
        itr = sum->insert(itr,digitToAdd);
        itr = sum->begin();

    }
    if (carry == 1) {
        itr = sum->insert(itr,carry);
    }
    return sum;
}


// helper method
vector<unsigned int>* InfiniteInt::convertValToVector(unsigned long long val) {

    vector<unsigned int> *newDigits = new vector<unsigned int>;
    if( val == 0) {
        newDigits->push_back(0);
        return newDigits;
    }

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