// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 12);  //Will FAIL, fix and add test cases.
    }


    //Add test cases as needed.
    assert(bi == 10);
    assert(bi == 100);
    assert(bi == 0);
    assert(bi == 87);
    assert(bi == 24);
    
    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}
