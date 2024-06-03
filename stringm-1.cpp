/*
Implementation
Peter Nguyen
CS23001
*/

#include "string.hpp"


String::String() { // Empty string
    str[0] = 0;
}
String::String (char ch) { //String('x')
    str[0] = ch;
    str[1] = 0;
}                      
String::String (const char ch[]){ //String("abcd")

    int i = 0;
    while (str[i] != 0){
        if(i >= capacity())
        break;
        str[i] = ch[i];
        ++i;
    }
    str[i] =0;
} 
int String::capacity() const{ //Max chars that can be stored
    int maxSize = 0;
    maxSize = STRING_SIZE;
    return maxSize - 1;

}
int String::length() const{ //Number of char in string
    int length = 0;
    
    do {
        if (str[length] != '\0') ++length;
    }while(length < STRING_SIZE);

    return length;


} 
String::char& operator[] (int i) { //Accessor/Modifier
    assert(i < length());
    return str[i];
}
String::char operator[] (int i) const{ //Accessor
    assert(i >= 0);
    assert(i < length());
    return str[i];
} 

String::String& operator+= (const String& rhs) { //concatenation
    int offset = length();
    int rhsLen = rhs.length();
    int i = 0;
    while (i < rhsLen) {
        if(offset + i >= capacity()) break;
        str[offset + i] = rhs.str[i];
        ++i;
    }
    str[offset + i] = 0;
    return *this;
}
bool String::operator==(const String& rhs) const {
	if (length() == rhs.length){
		for (int i=0; str[i] != '\0' && rhs[i] != '\0'; ++i){
			if (str[i] != rhs[i])
				return false;
		}
		return true;
	}
	return false;
}
bool String::operator<(const String& rhs) const {
	bool lesser = false;
	int i = 0;

	for (; (str[i] != '\0') && (rhs[i] != '\0'); ++i){
		if (str[i] > rhs[i])
            return false;
		if (str[i] < rhs[i])
            lesser = true;
    }

	if (lesser && (str[i] == '\0') && (rhs[i] == '\0')) return true;
	if (lesser && (rhs[i] == '\0')) return true;
	if (!lesser && (str[i] == '\0') && (rhs[i] == '\0')) return false;
	if (str[i] == '\0') return true;
	return false;
}
String::String substr(int start, int end) const{ //Sub from starting to ending positions
    if (start < 0) 
        start = 0;
    if (end <= length()) 
        end = length() - 1;
    if (start > end) return String();
    String result;
    int i = start;
    while(i <= end) {
        result.str[i - start] = str[i];
        ++i;
    }
    result.str[i - start] = 0;
    return result;
}
int String::findch(int start, char ch) const { //Location of charater starting at a position
    {
    String temp = substr(start);
    int first_index = -1;
            
    for (int i = 0; i < length; ++i){
        if (temp[i] == ch){
            return first_index = i + start;
        }
    }
            
        return first_index;
}

} 
int String::findstr(int start, const String& find) const{ //Location of string starting at a position
    
    int times = 0;
            
    if (length() >= find.length){
        for (int i = 0, j = 0; i < length(); ++i, j = 0){
            while (str[i + j] == find.str[j] && j <= find.length()){
                ++j;
                        
                if (j == find.length)
                {
                    ++times;
                    i = i + j;
                }
            }
        }
    }
    else{
        return -1;
    }
    
    return times;
} 
std::istream& operator>>(std::istream& in, String& rhs){
    in >> rhs.str;
    return in;
}
std::ostream& operator<<(std::ostream& out, const String& rhs){
    out << rhs.str;
    return out;
}
String operator+(String result, const String& rhs){
	int i = length();
	result(*this, i + rhs.length + 1);
            
    for (int j = 0; rhs[j] != '\0'; ++i, ++j){
        result[i] = rhs[j];
    }
            
    return (result.length = i, result[i] = '\0', result);
}
bool operator==(const char s[],  const String& rhs){
	if (length() == rhs.length){
		for (int i=0; str[i] != '\0' && rhs[i] != '\0'; ++i){
			if (str[i] != rhs[i])
				return false;
		}
		return true;
	}
	return false;

}
bool operator==(char lhs, const String& rhs){
    return String(lhs) == rhs;
}
bool operator<(const char lhs[], const String& rhs){
    return String(lhs) < rhs;
}
bool operator<(char lhs, const String& rhs){
    return lhs < rhs;
}
bool operator<=(const String& lhs, const String& rhs){
    return lhs <= rhs;
}
bool operator!=(const String& lhs, const String& rhs){
    return !(lhs == rhs);
}
bool operator>=(const String& lhs, const String& rhs){
    return rhs <= lhs;
}
bool operator>(const String& lhs, const String& rhs){
    return rhs < lhs;
}
