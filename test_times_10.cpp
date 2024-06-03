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
        bi = bi.times10(0);

        // Verify
        assert(bi == 77);  //Wrong. Will FAIL, fix and add tests cases
    }
    
    //Add test cases as needed.
    assert(bi == 10000000*10);
    assert(bi == 99999999*10);
    assert(bi == 19999999*10);

    std::cout << "Done testing times_10" << std::endl;
    return 0;
}

