#include "string.hpp"
#include <cassert>

//===========================================================================
int main ()
{
    
	{
		// Setup
		String str1;

		// Test & Verify
		assert(str1 == "");
		assert(str1.findchar('a') == -1);
	}

	{
		// Setup
		String str1 = "I am testing a Test";

		// Test & Verify
		assert(str1 == "I am testing a Test");
		assert(str1.findchar('t') == 10);
		assert(str1.findchar('T') == 0);
		assert(str1.findchar('z') == -1);
	}

	{
		// Setup
		String str1 = "I love dancing";

		// Test & Verify
		assert(str1 == "I love dancing");
		assert(str1.findchar('v', 3) == 5);
		assert(str1.findchar('w', 3) == -1);
	}
 
}
