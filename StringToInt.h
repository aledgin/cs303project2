// Alfred Ledgin
// 10/31/2015
// CS 303
// Project 2

#pragma once
#include <iostream>
#include <string>
using namespace std;


class StringToInt
// The purpose of this class is to convert a string of characters representing
    // a positive integer to the integer value represented.  This will only
    // convert strings consisting of the characters '0' through '9'.
{

    public:

        StringToInt() {numString = "";}
        // Preconditions: A converter needs to be declared.
        // Postconditions: This is the default constructor.  It allows
            // declaration of an empty converter, with an empty string.


        StringToInt(const string& input) {numString = input;}
        // Preconditions: A converter needs to be created with a given string.
        // Postconditions: This constructor creates a converter with the given
            // string.


        void input(const string& input) {numString = input;}
        // Preconditions: A converter's string needs to be changed.
        // Postconditions: This changes a converter's string to the given
            // string.


        const int convert() const
        {

            int result = 0;

            for (int counter = numString.length() - 1; counter >= 0; counter--)
                // Iterate from the last char through the first.
            {
                if (isdigit(numString[counter]))
                    result += ((numString[counter] - 48)
                        // First convert ASCII char to corresponding int value.
                        * pow(10, (numString.length() - 1) - counter));
                        // Then make that value the appropriate digit by
                            // multiplying it by the appropriate power of 10.
                else
                    throw std::exception("String must only contain digits.");
            }

            return result;

        }
        // Preconditions: The converted result of a converter's string is
            // needed.
        // Postconditions: This function converts the stored string to the
            // integer value represented by the string.
        // Reference (Inspiration for Algorithm):
            // Doutt, Gerald. "Lectures on Subroutines,
                // ASCII-Binary Conversion."
                // University of Missouri-Kansas City.
                // Royall Hall, Kansas City, MO.
                // Spring 2015. CS 282 Course Lectures.


    private:

        string numString;

};