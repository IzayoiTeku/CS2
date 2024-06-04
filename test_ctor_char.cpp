#include <iostream>
#include "string.hpp"
#include <cassert>



//===================================================================
int main() {
    {
        // Setup
        String input = nullptr;

        // Test
        String str1(input);
    

        // Verify
        assert(input == nullptr);


    }

    {
        // Setup
        String input = "Hello";

        // Test
        String str1(input);

        // Verify
        assert(input == 0);
        assert(input == "Hello");


    }
}
