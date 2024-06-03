//  Stack class test program
//
//  Tests: swap functions 
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
        stack<T>  s1 = "(a*b)+c";
        stack<T>  s2 = "+*abc";

        // TEST
        s1.swap(s2);

        // VERIFY
        assert(s1 == "+*abc");
        assert(s2 == "(a*b)+c");
     }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing the swap function." << std::endl;
    return 0;
}
