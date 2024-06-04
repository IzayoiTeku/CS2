#include "string.hpp"
#include <cassert>

//===========================================================================
int main ()
{
	{
		// Setup
		String str1 = "I love dancing",
			   str2 = "I hate dancing";

		// Test
		str1.swap(str2);

		// Verify
		assert(str1 == "I hate dancing");
		assert(str2 == "I love dancing");
	}
}
