// File: main.cpp
//
// CS 23001 Project 1 bigint 
//
// Basics for openning a file for milestone 2
//

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream inFile;            // Define input stream
    inFile.open("data1-1.txt");      // Open a file
    if(!inFile) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }
    //Until end of file
    bigint beginning, end;//Read two bigints
    while (inFile >> beginning && inFile >> end) { 
        std::cout << "beginning: " << beginning << std::endl; //Print them out
        std::cout << "end: " << end << std::endl;

        bigint result = beginning + end; //Add them together
        
        std::cout << "result: " << result << std::endl;


    }
   
       
 
    inFile.close();
    return 0;
}
