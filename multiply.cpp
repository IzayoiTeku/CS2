/*
multiply file
Peter Nguyen
CS23001
*/

#include "bigint.hpp"


int main() {
        std::ifstream inFile;            // Define input stream
    inFile.open("data1-2.txt");      // Open a file
    if(!inFile) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-2.txt" << std::endl;
        exit(1);
    }
    //Until end of file
    bigint beginning, end;//Read two bigints
    while (inFile >> beginning && inFile >> end) { 
        std::cout << "beginning: " << beginning << std::endl; //Print them out
        std::cout << "end: " << end << std::endl;

        bigint result = beginning * end; //Add them together
        
        std::cout << "result: " << result << std::endl;


    }
   
       
 
    inFile.close();
    return 0;
}
