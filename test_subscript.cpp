// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 800);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 250);
    }
    
    //Add test cases!!
    assert(bi == 900000000000000009);
    assert(digit == 1000000000000999);
    assert(digit == 39480394318093399);
    assert(bi == 999999999999999999);

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

