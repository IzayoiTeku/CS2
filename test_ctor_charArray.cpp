#include "string.hpp"
#include <cassert>

//===================================================================
int main() {
    {
        // Setup
        char str1[] = "I love dancing";

        // Test
        String(str1);
    

        // Verify
        assert(str1 == "I love dancing");

    }

    {
        // Setup
        char str1[] = "";

        // Test
        String(str1);

        // Verify
        assert(str1 == 0);
        assert(str1 == "");
    }
    
    {
        // Setup
        char str1[] == "I want to become a model";

        // Test
        String(str1);

        // Verify
        assert(str1 == "I want to become a model");
        assert(str1 == "I want to become A Model");
        assert(str1 == "");
        

    }
}
