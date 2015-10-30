// Alfred Ledgin
// 10/30/2015
// CS 303
// Project 2
// NEED TO WRITE PRECONDITIONS AND POSTCONDITIONS

#pragma once
#include <iostream>
#include <string>
using namespace std;


class Operator
{

    public:

        Operator(string input);

        int hasPrecedence() {return precedence;}

        string hasType() {return type;}

        char hasCategory() {return category;}

        bool operator<(Operator rhs) {return precedence < rhs.precedence;}

        bool operator<=(Operator rhs) {return precedence < rhs.precedence;}

        bool operator==(Operator rhs) {return precedence == rhs.precedence;}

        bool operator!=(Operator rhs) {return precedence != rhs.precedence;}

        bool operator>=(Operator rhs) {return precedence >= rhs.precedence;}

        bool operator>(Operator rhs) {return precedence > rhs.precedence;}

        double execute(double rhs);

        double execute(double lhs, double rhs);

    private:

        int precedence;
        string type;
        char category;

};