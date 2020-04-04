////////////////////////////////////////////////////////////////////////////////
// Main File: InfiniteInt.h, demo.cpp
// This File: demo.cpp
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

int main() {
    // Make sure to first implement stream insertion operator!
    
    // Testing long param constructor and no-arg constructor
    cout << "Constructing n1 and n2..." << endl;
    InfiniteInt n1(412);
    InfiniteInt n11(412);
    n1.getDigits();
    InfiniteInt n2 = InfiniteInt();
    if((n1.getDigits()) != (n2.getDigits())) {
        cout << "They are not equal" << endl;
    }

    if((n1.getDigits()) != (n11.getDigits())) {
        cout << "They are equal" << endl;
    }
    cout << "n1 should be 412: " << n1 << endl;
    cout << "n2 should be 0: " << n2 << endl;
    cout << endl;

    // // Testing copy Op=
    std::cout << "Changing value of n2..." << std::endl;
    n2 = 3;
    std::cout << "n2 should be 3: " << n2 << std::endl;
    std::cout << std::endl;

    // Testing copy constructor
    std::cout << "Constructing n3..." << std::endl;
    InfiniteInt n3(n2);
    std::cout << "n3 should be 3: " << n3 << std::endl;

    // Testing <<
    cout << endl << "Testing >> by changing n2" << endl;
    cin >> n2;
    cout << "The NEW digits for n2 are " << n2 << endl;

    // Testing < and > 
    cout << endl << "Testing < and  > " << endl;
    InfiniteInt n4(4087359802512345);
    InfiniteInt n5(4087359802512346);

    if( n4 < n5) {
        cout << "n4=" << n4 << " is LESS than "  << n5 << endl;
    }
    if(n5 > n4) {
        cout << "n5=" << n5 << " is GREATER than " << n4 << endl;
    }

    InfiniteInt n6(34);
    InfiniteInt n7(34);
    InfiniteInt n8(25);
    InfiniteInt n9(12834124);

    // Testing <= and >=
    cout << endl << "Testing <= and  >= " << endl;
    if( n6 <= n7) {
        cout << "n6=" << n6 << " is EQUAL to n7=" << n7 << endl;
    }
    if(n8 <= n6) {
        cout << "n8=" << n8 << " is LESS than n6=" << n6 << endl;
    }
    if( n6 >= n7) {
        cout << "n6=" << n6 << " is EQUAL to n7=" << n7 << endl;
    }
    if(n7 >= n8) {
        cout << "n7=" << n7 << " is GREATER than n8=" << n8 << endl;
    }

    // Testing = and !=
    cout << endl << "Testing = and !=" << endl;
    if( n6 == n7) {
        cout << "n6=" << n6 << " is EQUAL to n7=" << n7 << endl;
    }
    if( n6 != n8) {
        cout << "n6=" << n6 << " is NOT EQUAL to n8=" << n8 << endl;
    }

    // Testing + and -
    cout << endl << "Testing + and -" << endl;
    InfiniteInt sum = n6 + n7;
    if (sum == (34+34)) {
        cout << "n6=" << n6 << " + n7=" << n7 << " = " << sum << endl;
    }

    InfiniteInt sumV1 = n6 + n9;
    if (sumV1 == (34+12834124)) {
        cout << "n6=" << n6 << " + n9=" << n9 << " = " << sumV1 << endl;
    }

    InfiniteInt difference = n6 - n8;
    if (difference == (34-25)) {
        cout << "n6=" << n6 << " - n8=" << n8 << " = " << difference << endl;
    }

    n6 = 234;
    n7 = 233;

    InfiniteInt diffOfn6Andn7 = n6-n7;
    cout << "n6=" << n6 << " -" << diffOfn6Andn7 << endl;

    InfiniteInt n12(1000000000);
    InfiniteInt n13(1);
    InfiniteInt differenceV3 = n12 - n13;
    if(differenceV3 == (1000000000-1)) {
        cout << "n12=" << n12 << " - n13=" << n13 << " = " << differenceV3 << endl;
    }

    InfiniteInt bigNum(7812837488127);
    InfiniteInt smallerNum(6923948599238);
    InfiniteInt smallDiff = bigNum - smallerNum;
    if(smallDiff == (7812837488127-6923948599238)) {
        cout << "bigNum=" << bigNum << " - " << "smallerNum=" << smallerNum << " = " << smallDiff << endl;
    }

    // Testing += and -=
    cout << endl << "Testing += and -=" << endl;
    n12 = 15;
    n12 += 6;
    if ( n12 == 21) {
        cout << "n12 was 15 and now is = "  << n12 << endl; 
    }

    n13 = 57;
    n13 -= 3;
    if ( n13 == 54) {
        cout << "n13 was 57 and now is = "  << n13 << endl; 
    }

    return 0;
}