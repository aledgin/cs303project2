// Alfred Ledgin, Luke Simmons, and Megan Sword
// 11/3/2015
// CS 303
// Project 2

#include <iostream>
#include <string>
#include "Operator.h"
using namespace std;


Operator::Operator()
{
    type = "(";
    precedence = 0;
    category = 'p';
}


Operator::Operator(string input)
{

    type = input;

    // Set precedence based on input.
    if ((input == "(") || (input == ")"))
        precedence = 0; // Special precedence for parentheses.
    else if ((input == "!") || (input == "++")
        || (input == "--") || (input == "-#"))
        precedence = 8;
    else if (input == "^")
        precedence = 7;
    else if ((input == "*") || (input == "/") || (input == "%"))
        precedence = 6;
    else if ((input == "+") || (input == "-"))
        precedence = 5;
    else if ((input == "<") || (input == "<=")
        || (input == ">=") || (input == ">"))
        precedence = 4;
    else if ((input == "==") || (input == "!="))
        precedence = 3;
    else if (input == "&&")
        precedence = 2;
    else if (input == "||")
        precedence = 1;
    else
        throw std::exception("Invalid operator input");

    if (precedence == 0)
        category = 'p'; // Parentheses have precedence == 0.
    else if (precedence == 8)
        category = 'u'; // Unary operators have precedence == 8.
    else
        category = 'b'; // Binary operators have precedence in [1, 7].

}


const double Operator::execute(double rhs) const
{

    if (category == 'u')
    {

        // The type is hard-coded upon operator construction.
        if (type == "!")
        {
            if (rhs == 0)
                return 1;
            else
                return 0;
        }
        else if (type == "++")
            return rhs + 1.0;
        else if (type == "--")
            return rhs - 1.0;
        else // if (type == "-#")
            return -rhs;

    }

    else // Cannot use this function with binary operator or parentheses.
        throw
            std::exception("lhs operand required. Cannot execute parentheses");

}


const double Operator::execute(double lhs, double rhs) const
{

    if (category == 'b')
    {

        // The type is hard-coded upon operator construction.
        if (type == "^")
            return pow(lhs, rhs);
        else if (type == "*")
            return lhs * rhs;
        else if (type == "/")
        {
            if (rhs != 0)
                return lhs / rhs;
            else
                throw std::exception("Cannot divide by zero.");
        }
        else if (type == "%")
            return int(lhs) % int(rhs);
        else if (type == "+")
            return lhs + rhs;
        else if (type == "-")
            return lhs - rhs;
        else if (type == "<")
            return lhs < rhs;
        else if (type == "<=")
            return lhs <= rhs;
        else if (type == ">=")
            return lhs >= rhs;
        else if (type == ">")
            return lhs > rhs;
        else if (type == "==")
            return lhs == rhs;
        else if (type == "!=")
            return lhs != rhs;
        else if (type == "&&")
            return lhs && rhs;
        else // if (type == "||")
            return lhs || rhs;

    }

    else // Cannot use this function with unary operator or parentheses.
        throw std::exception("Cannot have lhs operand.");

}