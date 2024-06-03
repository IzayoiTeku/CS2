#include "string.hpp"
#include <cassert>

//===========================================================================
int main ()
{
	{
		// Setup
		String str1,
			   str2,
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "\0");
		assert(str2 == "\0");
		assert(result == "\0");
	}

	{
		// Setup
		String str1,
			   str2('p'),
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "\0");
		assert(str2 == "p");
		assert(result == "p");
	}

	{
		// Setup
		String str1 = 'a',
			   str2 = 'p',
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "a");
		assert(str2 == "p");
		assert(result == "ap");
	}

	{
		// Setup
		String str1("a"),
			   str2("p"),
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "a");
		assert(str2 == "p");
		assert(result == "ap");
	}

	{
		// Setup
		String str1('a'),
			   str2("p"),
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "a");
		assert(str2 == "p");
		assert(result == "ap");
	}

	{
		// Setup
		String str1("a"),
			   str2('p'),
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "a");
		assert(str2 == "p");
		assert(result == "ap");
	}

	{
		// Setup
		String str1("This is a test. "),
			   str2("It needs to pass."),
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "This is a test. ");
		assert(str2 == "It needs to pass.");
		assert(result == "This is a test. It needs to pass.");
	}

	{
		// Setup
		String str1("This is a test. "),
			   result;

		// Test
		result = str1 + "It needs to pass.";

		// Verify
		assert(str1 == "This is a test. ");
		assert(result == "This is a test. It needs to pass.");
	}

	{
		// Setup
		String str1("Live life on the edge"),
			   result;

		// Test
		result = str1 + '!';

		// Verify
		assert(str1 == "Live life on the edge");
		assert(result == "Live life on the edge!");
	}

	{
		// Setup
		String str1("Live life on the edge! "),
			   str2("You have to take risks!");

		// Test
		str1 += str2;

		// Verify
		assert(str1 == "Live life on the edge! You have to take risks!");
	}

	{
		// Setup
		String str1("Live life on the edge! ");

		// Test
		str1 += "You have to take risks! ";

		// Verify
		assert(str1 == "Live life on the edge! You have to take risks!");
		assert(str1.buffCapacity() == default_size);
	}
}
