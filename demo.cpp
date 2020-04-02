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
    InfiniteInt n2;
    cout << "n1 should be 412: " << n1 << endl;
    cout << "n2 should be 0: " << n2 << endl;
    cout << endl;

    // // Testing copy Op=
    // std::cout << "Changing value of n2..." << std::endl;
    // n2 = 3;
    // std::cout << "n2 should be 3: " << n2 << std::endl;
    // std::cout << std::endl;

    // // Testing copy constructor
    // std::cout << "Constructing n3..." << std::endl;
    // InfiniteInt n3(n2);
    // std::cout << "n3 should be 3: " << n3 << std::endl;

    // // Add more code here to test InfiniteInt here!

    return 0;
}