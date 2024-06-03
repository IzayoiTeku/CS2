/*
Peter Nguyen
infix -> postfix
Mr. Maletic
CS 23001
4/4/2023
*/

#include "utilities.hpp"
#include <iostream>

template <typename T>
String infix_to_postfix(String<T>& S){

    std::String lhs,
                rhs,
                op;
    while(S != ";"){ // not done with expression
        t = next
        if (t == ')'){ // t = token
            rhs = S.pop();
            op = S.pop();
            lhs = S.pop();
            S.push( rhs + lhs + op); //convert to postfix or prefix depending on which one
        }
        else if (t == '('){
            S.push(t);
        }
        return S.pop();  // final pre/postfix on ToS



        // k.push(lhs + rhs + op) // postfix
        // k.push(op + lhs + rhs) // prefix
    }
}
template <typename T>
String infix_to_prefix(String<T>& S){
    std::String lhs,
                rhs,
                op;
    while(S != ";"){ // not done with expression
        if (t == '('){ // t = token
            rhs = S.pop();
            op = S.pop();
            lhs = S.pop();
            S.push(op + rhs + lhs); //convert to postfix or prefix depending on which one
        }
        else if (t == '('){
            S.push(t);
        }
        return S.pop();  // final pre/postfix on ToS



        // k.push(lhs + rhs + op) // postfix
        // k.push(op + lhs + rhs) // prefix
    }
}

template <typename T>
String postfixToAl(const String& postfix) {
// AX B C* +
// Declare stack ---->s
// Declare counter ----> 1
// Declare String assembly
// split postfix --> vector
// iterate over vector;
// if not operator:
// s.push(token)
// else
// left = s.pop()
// right = s.pop()
// String result = eval(left, right, operation, counter)
// s.push(result)
// ++counter
// assembly += result

// if not operator;
// s.push(token);
    std::String lhs,
                rhs,
                op,
                currentToken;

    stack<T> s;
    int counter = 1;
    String assembly;
    std::vector<String> vect = postfix.split();
    std::vector 
    while(!s.isEmpty()) {
        if (!op) {
            s.push(token);
        }
        else {
            lhs = s.pop();
            rhs = s.pop();
        }
        String result = eval(lhs, rhs, op, counter);
        s.push(result);
        ++counter;
    }

    assembly += result;



}

