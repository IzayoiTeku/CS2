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
		assert(str1.findstr("This") == 0);
		assert(str1.findstr("\0") == 0);
	}

	{
		// Setup
		String str1 = "I love dancing";

		// Test & Verify
		assert(str1 == "I love dancing");
		//assert(str1.findstr("It's") == 1);
		//assert(str1.findstr("00") == 1);
	}
}
