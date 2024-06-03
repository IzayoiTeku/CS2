/*
Peter Nguyen
Project 2 String
Milestone 2
2/28/2024
*/

#include "string.hpp"

// run valgrind

String::String() { // Empty string
    int capacity = stringSize;
    str = new char[];
}
String::String (char ch) { //String('x')
    int capacity = stringSize;
    str = new char[capacity];
    str[0] = ch;
    str[1] = '\0';
    int len = 1;
}                      
String::String (const char ch[]){ //String("abcd")

    int capacity = stringSize;
    str = new char[capacity];
    do {
        int i = 0; 
        for (; ch[i] != '\0'; ++i){
            str[1] = ch[i];
        }
        int len = i;
        if (capacity < len){
            delete[] str;
            capacity = capacity * 2;
            str = new char[capacity];
            int len = capacity;
        }
    } while (capacity < len);
    str[len] = '\0';
} 
String::String(const String& actual) { // Copy ctor
    stringSize = actual.stringSize;
    str = new char[stringSize];
    for(int i = 0; i <stringSize; ++i){
        str[i] = actual.str[i];
    }
}
String::~String() { // destructor
    delete [] str;
}
void String::swap(String& rhs) { //Constant time swap
    char *temp = str;
    str = rhs.str;
    rhs.str = temp;
    int ctemp = stringSize;
    stringSize = rhs.stringSize;
    rhs.stringSize = ctemp;
} 
String& String::operator=(String rhs){ //Assignment Copy   
    swap(rhs);
    return *this;
}                                             
int String::capacity() const{ //Max chars that can be stored
    return stringSize -1;
}
int String::length() const{ //Number of char in string
    int result =0;
    while (str[result] != 0) ++result;
    return result;
} 
char& String::operator[] (int i) { //Accessor/Modifier
    assert(i < length());
    return str[i];
}
char String::operator[] (int i) const{ //Accessor
    assert(i >= 0);
    assert(i < length());
    return str[i];
} 

String& String::operator+= (const String& rhs) { //concatenation
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
	if (length() == rhs.length()){
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
String String::substr(int start, int end) const{ //Sub from starting to ending positions
    if (start < 0) 
        start = 0;
    if (end <= length()) 
        end = length() - 1;
    if (start > end) return String();
    String result;
    int i = start;
    while(i <= end) {
        result.str[i - start] = s[i];
        ++i;
    }
    result.str[i - start] = 0;
    return result;
}
int String::findch(int start, char ch) const { //Location of charater starting at a position
    
    String temp = substr(start);
    int first_index = -1;
            
    for (int i = 0; i < length; ++i){
        if (temp[i] == ch){
            return first_index = i + start;
        }
    }
            
    return first_index;

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
String operator+(String lhs, const String& rhs){
    return lhs += rhs;
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

std::vector<String> String::split(char ch) const {
    std::vector<String> result;
    String temp;
            
    for (int i = 0; str[i] != '\0'; ++i){
        str.findch(i, ch);
        if (str[i] != ch) {
        
        temp = temp + str[i];
        }
        else {
            result.push_back(temp);
            temp = str[++i];
        }
    }
            
    return (result.push_back(temp), result);
}
