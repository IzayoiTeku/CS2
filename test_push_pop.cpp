//  Stack class test program
//
//  Tests: Push & Pop functions
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
        Node<T> *tos;
        stack<T> node = "1234";


        // TEST
        node.push(tos);

        // VERIFY
        assert(node == "1234");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        Node<T> *tos;
        stack<T> node = "2341";


        // TEST
        node.pop();

        // VERIFY
        assert(node == "234");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        Node<T> *tos;
        stack<T> node = "2834";


        // TEST
        node.push("2");

        // VERIFY
        assert(node == "28342");
        
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        Node<T> *tos;
        stack<T> node = "78123";


        // TEST
        node.pop();

        // VERIFY
        assert(node == "7812");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        Node<T> *tos;
        stack<T> node = "2834";


        // TEST
        node.push("0");

        // VERIFY
        assert(node == "283420");
        
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        Node<T> *tos;
        stack<T> node = "";


        // TEST
        node.pop();

        // VERIFY
        assert(node == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        Node<T> *tos;
        stack<T> node = "2834";


        // TEST
        node.push("");

        // VERIFY
        assert(node == "2834");
        
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing the push and pop functions." << std::endl;
    return 0;
}
