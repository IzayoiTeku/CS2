//  Stack class test program
//
//  Tests: Default constructor
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

        // TEST
        stack<T> node;

        // VERIFY
        assert(node == "0");
        assert(node == "");
        assert(node == "\0");
    }

    {
        //-------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<T> node = "1234";

        // VERIFY
        assert(node == "\0");
        assert(node == "");
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing XXX." << std::endl;
    return 0;
}
