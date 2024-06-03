/*

Peter Nguyen
reads infix
Mr. Maletic
CS 23001

*/


#include "utilities.hpp"
#include "stack.hpp"
#include "../string/string.hpp"
#include <fstream>

// Reads a set of infix expressions from a file and writes the infix and postfix expressions to another file.

void assistance(void);

int main(int argc, char const* argv[]) {
    Stack<std::string> s;
    std::string lhs,
                    rhs,
                    op,
                    currentToken;
        char token[300];
    while(!in.eof) {
            in >> token;
    currentToken = std::string(token);

    if(in.eof()) {
        break;
    }
    if(currentToken ==";") {
        out << s;
        out << ";";
        out << std::endl;
        s = Stack<std::string:();
    }
    else if(currentToken == ")") {
        rhs = s.pop();
        op = s.pop();
        lhs = s.pop();
        s.push(lhs + rhs + op);
    }
    else {
        if(currentToken != "(") {
            s.push(currentToken + ' ');
        }
    }
        
    }
}
void assistance() {
    std::cerr << "Usage: ./postfix.out input_file [output file]" << std::endl;

}
