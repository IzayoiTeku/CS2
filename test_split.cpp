#include "string.hpp"
#include <cassert>

//===========================================================================
int main ()
{
    
	{
        
		// Setup
		String str = "Astral express is fast.";
        std::vector<String> result;
		
		// Test
		result = str.split(' ');
		
		// Verify
		assert(str == "Astral express is fast.");
		assert(result[0] == "Astral");
		assert(result[1] == "express");
		assert(result[2] == "is");
		assert(result[3] == "fast.");

	}
	
	{
		// Setup
		String str = "String";
        std::vector<String> result;
		
		// Test
		result = str.split();
		
		// Verify
		assert(str == "String");
		assert(result[0] == "S");
		assert(result[1] == "t");
		assert(result[2] == "r");
		assert(result[3] == "i");
		assert(result[4] == "n");
		assert(result[5] == "g");
	}
         
}
