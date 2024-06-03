/*
Peter Nguyen
bigint
CS 23001
Jan 23, 2024
*/

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>

const int capacity = 200; 

class bigint {
    public: 
    bigint();
    bigint(int);
    bigint(const char[]);
    bigint operator+(bigint) const;
    bigint timesDigit(int);
    bigint times10(int);
    bigint operator*(bigint); 

    void debugPrint(std::ostream&,const char[]) const;

    bool operator== (std::ostream&, const bigint&) const;
    
   
    friend std::ostream operator<<(std::ostream&, bigint&);
    friend std::ostream operator>>(std::istream&, bigint&);

    int operator[](int) const;
    

    
    private:
    int hugeNum[capacity];
};





#endif
