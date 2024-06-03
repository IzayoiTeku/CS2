//  Stack class test program
//
//  Tests: Empty function
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<T>  s;

        // TEST
        s.empty();

        // VERIFY
        assert(s == 0);
        assert(s != 0);
        assert(s == nullptr);
        assert(s != nullptr);
     }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing the empty function." << std::endl;
    return 0;
}
