#include "string.hpp"
#include <cassert>

//===========================================================================
int main ()
{

	{
		// Setup
		String str1;

		// Test
		str1 = 'a';

		// Verify
		assert(str1 == "a");
	}

	{
		// Setup
		String str1;

		// Test
		str1 = "This is a test.";

		// Verify
		assert(str1 == "This is a test.");
	}

	{
		// Setup & Test
		String str1 = 'a';
		
		// Verify
		assert(str1 == "a");
	}

	{
		// Setup & Test
		String str1 = "This is a test.";

		// Verify
		assert(str1 == "This is a test.");
	}

	{
		// Setup & Test
		String str1 = "This";
		String str2 = "This";
		
		// Verify
		assert(str1 == "This");
		assert(str2 == "This");
		assert(str1 == str2);
		assert(str1.buffCapacity() == str2.buffCapacity());
		assert(str1.getLength() == str2.getLength());
	}

}
