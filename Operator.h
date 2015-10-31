// Alfred Ledgin
// 10/30/2015
// CS 303
// Project 2

#pragma once
#include <iostream>
#include <string>
using namespace std;


class Operator
// This is a class of arithmetic operators, for use in evaluating a string as
    // an arithmetic expression.
{

    public:

        Operator(string input);
        // Preconditions: An operator needs to be constructed from a given
            // string.
        // Postconditions: This constructor sets the operator to the type
            // represented by the given string and sets the category and
            // precedence accordingly. Note that a number sign ('#') must
            // be inserted after a minus sign ('-') in order to construct
            // the negation operator.


        int hasPrecedence() {return precedence;}
        // Preconditions: An operator's numerical precedence is needed.
        // Postconditions: This returns the operator's numerical precedence.


        string hasType() {return type;}
        // Preconditions: An operator's type is needed.
        // Postconditions: This returns the string representation of the
            // operator.


        char hasCategory() {return category;}
        // Preconditions: An operator's category is needed.
        // Postconditions: This returns the category (unary or binary).


        bool operator<(Operator rhs) {return precedence < rhs.precedence;}
        // Preconditions: Two operators need to be compared for precedence.
        // Postconditions: This returns true if the left-hand-side operator
            // has a lower precedence than the right-hand-side operator.


        bool operator<=(Operator rhs) {return precedence < rhs.precedence;}
        // Preconditions: Two operators need to be compared for precedence.
        // Postconditions: This returns true if the left-hand-side operator
            // has an equal or lower precedence than the right-hand-side
            // operator.


        bool operator==(Operator rhs) {return precedence == rhs.precedence;}
        // Preconditions: Two operators need to be compared for precedence.
        // Postconditions: This returns true if both operators have the same
            // precedence.


        bool operator!=(Operator rhs) {return precedence != rhs.precedence;}
        // Preconditions: Two operators need to be compared for precedence.
        // Postconditions: This returns true if the two operators have
            // different precedencies.


        bool operator>=(Operator rhs) {return precedence >= rhs.precedence;}
        // Preconditions: Two operators need to be compared for precedence.
        // Postconditions: This returns true if the left-hand-side operator
            // has an equal or higher precedence than the right-hand-side
            // operator.


        bool operator>(Operator rhs) {return precedence > rhs.precedence;}
        // Preconditions: Two operators need to be compared for precedence.
        // Postconditions: This returns true if the left-hand-side operator
            // has a higher precedence than the right-hand-side operator.


        double execute(double rhs);
        // Preconditions: An operation needs to be executed based on the
            // given unary operator.
        // Postconditions: This function performs the given arithmetic
            // operation on the given numerical value.


        double execute(double lhs, double rhs);
        // Preconditions: An operation needs to be executed based on the
            // given binary operator.
        // Postconditions: This function performs the given arithmetic
            // operation on the two given numerical values.


    private:

        int precedence;
        string type;
        char category;

};