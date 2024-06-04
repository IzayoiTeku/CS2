#include "string.hpp"
#include <cassert>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str('a');

        // VERIFY
        assert(str == "a");
		assert(str.buffCapacity() == default_size);
        //std::cerr << str.buffCapacity();
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("a");

        // VERIFY
        assert(str == "a");
        assert(str.buffCapacity() == default_size);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Curious");

        // VERIFY
        assert(str == "Curious");
		assert(str.buffCapacity() == default_size);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("I love dancing");

        // VERIFY
        assert(str == "I love dancing");
		assert(str.buffCapacity() == default_size);
    }
	
	{
		// Setup
		String str("I love dancing", 100);
		
		// Verify
		assert(str == "I love dancing");
		assert(str.buffCapacity() == 100);
	}
}
