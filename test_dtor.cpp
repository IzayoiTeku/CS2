//  Stack class test program
//
//  Tests: Destructor
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
        stack<T>  node;

        // VERIFY
        assert(node != "0");
        assert(node != "\0");
        assert(node != 0);
        assert(node != nullptr);

    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing deconstructor." << std::endl;
    return 0;
}
