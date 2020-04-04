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
    // cout << "Constructing n1 and n2..." << endl;
    // InfiniteInt n1(412);
    // InfiniteInt n11(412);
    // n1.getDigits();
    // InfiniteInt n2;
    // if((n1.getDigits()) != (n2.getDigits())) {
    //     cout << "They are not equal" << endl;
    // }

    // if((n1.getDigits()) != (n11.getDigits())) {
    //     cout << "They are equal" << endl;
    // }
    // cout << "n1 should be 412: " << n1 << endl;
    // cout << "n2 should be 0: " << n2 << endl;
    // cout << endl;

    // // // Testing copy Op=
    // std::cout << "Changing value of n2..." << std::endl;
    // n2 = 3;
    // std::cout << "n2 should be 3: " << n2 << std::endl;
    // std::cout << std::endl;

    // // Testing copy constructor
    // std::cout << "Constructing n3..." << std::endl;
    // InfiniteInt n3(n2);
    // std::cout << "n3 should be 3: " << n3 << std::endl;

    // // Add more code here to test InfiniteInt here!

    // // Testing < and > 
    // cout << endl << "Testing < and  > " << endl;
    // InfiniteInt n4(4087359802512345);
    // InfiniteInt n5(4087359802512346);

    // if( n4 < n5) {
    //     cout << "n4=" << n4 << " is LESS than "  << "n5=" << n5 << endl;
    // }
    // if(n5 > n4) {
    //     cout << "n5=" << n5 << " is GREATER than "  << "n4=" << n4 << endl;
    // }

    InfiniteInt n6(34);
    InfiniteInt n7(34);
    InfiniteInt n8(25);
    InfiniteInt n9(12834124);

    // // Testing <= and >=
    // cout << endl << "Testing <= and  >= " << endl;
    // if( n6 <= n7) {
    //     cout << "n6=" << n6 << " is EQUAL to "  << "n7=" << n7 << endl;
    // }
    // if(n8 <= n6) {
    //     cout << "n8=" << n8 << " is LESS than "  << "n6=" << n6 << endl;
    // }
    // if( n6 >= n7) {
    //     cout << "n6=" << n6 << " is EQUAL to "  << "n7=" << n7 << endl;
    // }
    // if(n7 >= n8) {
    //     cout << "n7=" << n7 << " is GREATER than "  << "n8=" << n8 << endl;
    // }

    // // Testing = and !=
    // cout << endl << "Testing = and !=" << endl;
    // if( n6 == n7) {
    //     cout << "n6=" << n6 << " is EQUAL to "  << "n7=" << n7 << endl;
    // }
    // if( n6 != n8) {
    //     cout << "n6=" << n6 << " is NOT EQUAL to "  << "n8=" << n8 << endl;
    // }

    // Testing + and -
    cout << endl << "Testing + and -" << endl;
    InfiniteInt sum = n6 + n7;
    if (sum == (34+34)) {
        cout << "n6=" << n6 << " + " << "n7=" << n7 << " = sum=" << sum << endl;
    }

    InfiniteInt sumV1 = n6 + n9;
    cout << "sumV1 = " << sumV1;
    if (sumV1 == (34+12834124)) {
        cout << "n6=" << n6 << " + " << "n9=" << n9 << " = sumV1=" << sumV1 << endl;
    }
    // InfiniteInt difference = n6 - n8;
    // if (difference == (34-25)) {
    //     cout << "n6=" << n6 << " - " << "n8=" << n8 << " = difference=" << difference << endl;
    // }
    // InfiniteInt n10(100);
    // InfiniteInt n11(19);

    // InfiniteInt differenceV2 = n10 - n11;
    // cout << "difference = " << differenceV2;

    // InfiniteInt n12(1000000000);
    // InfiniteInt n13(1);
    // InfiniteInt differenceV3 = n12 - n13;
    // cout << differenceV3 << " equals? " << (1000000000-1) << endl;
    // if(differenceV3 == (1000000000-1)) {
    //     cout << "n12=" << n12 << " - " << "n13=" << n13 << " = differenceV3=" << differenceV3 << endl;
    // }

    // InfiniteInt bigNum(7812837488127);
    // InfiniteInt smallerNum(6923948599238);
    // InfiniteInt smallDiff = bigNum - smallerNum;
    // cout << smallDiff << " equals? " << (7812837488127-6923948599238) << endl;
    // cout << endl << "Testing >> by changing n2" << endl;
    // cin >> n2;
    // cout << "the new digits for n2 are " << n2 << endl;

    return 0;
}