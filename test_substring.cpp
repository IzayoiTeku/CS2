#include "string.hpp"
#include <cassert>

//===========================================================================
int main ()
{
	{
		// Setup
		String str1 = "abcdefghijk",
			   result1,
			   result2,
			   result3,
			   result4;

		// Test
		result1 = str1.substr(0);
		result2 = str1.substr(1);
		result3 = str1.substr(0, 3);
		result4 = str1.substr(1, 12);


		// Verify
		assert(str1 == "abcdefghijk");
		assert(result1 == "a");
		assert(result2 == "b");
		assert(result3 == "abc");
		assert(result4 == "bcdefghijk");
	}
	
	{
		// Setup
		String str = "Chris is the best!";

		// Test & Verify
		assert(str.substr(0, 5) == "Chris");
		assert(str.substr(6, 7) == "is");

	}
}
