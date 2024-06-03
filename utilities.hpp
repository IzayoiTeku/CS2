#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include "stack.hpp"
#include <fstream>
#include "../string/M4/string.hpp"

template <typename T>
String infix_to_postfix(std::istream&, string<T>&);
String infix_to_prefix(std::istream&, string<T>&);
String postfixToAl(const String&);


#endif
