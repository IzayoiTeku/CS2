//  Stack class test program
//
//  Tests: Copy constructor
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
        stack<T> s = "1234";

        // VERIFY
        assert(s == "1234");
        assert(s == s);
    }

    {
        //-----------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<T> s = "";
        

        // VERIFY
        assert(s == "");
        assert(s == 0);
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing the copy constructor." << std::endl;
    return 0;
}
