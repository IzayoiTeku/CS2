//  Stack class test program
//
//  Tests: Assignment operator
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
        stack<T> s;
        // TEST
        assert(s == 0);
        assert(s == "0");
        assert(s == "50");       

        // VERIFY
        std::cout << "==";
        std::cout << s;
        std::cout << std::endl;


    }

    {
        //-----------------------------------------------------
        // SETUP FIXTURE
        stack<T> s = 1234;
        // TEST
        assert(s == s);

        // VERIFY
        std::cout << "==";
        std::cout << s;
        std::cout << std::endl;
        

    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing the assignment operator." << std::endl;
    return 0;
}

