// bigint Test Program
//
// Tests:  int constructor, uses ==
// 
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    //Add test cases as needed.
    //test cases
    assert(right == -1000000000000000000000000000000342394329492349329493);
    assert(left == 263234359869000809890478941104790394294393240);
    assert(left == 0);
    assert(right == 0);
    assert(left == 50000423043240230302402304230432);
    assert(result == 10000000000000000000000000000000000000000000);
    assert(left == 1000000000000000000000000000000000000000000000000000000000000);
    assert(right == 100000000000000000000000000000000000000000000000000000000);
    assert(left == 99999999999999999999999999999999999999999999999999999999999999999999);


    
    
    
    
    std::cout << "Done with testing addition." << std::endl;
    return 0;
}

