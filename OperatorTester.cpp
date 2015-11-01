// FOR TESTING ONLY--DO NOT TURN IN
// Alfred Ledgin
// 10/31/2015
// CS 303
// Project 2

#include <iostream>
#include <string>
#include "Operator.h"
using namespace std;


int main()
{
    try
    {Operator fake("abc");}
    catch(exception)
    {cout << "Operator 'abc' throws exception as expected." << endl;}
    Operator not("!");
    cout << not.execute(0) << endl;
    cout << not.execute(1) << endl;
    Operator increment("++");
    cout << increment.execute(-0.5) << endl;
    Operator decrement("--");
    cout << decrement.execute(0.5) << endl;
    Operator negative("-#");
    cout << negative.execute(5) << endl;
    cout << negative.execute(-5) << endl;
    try
    {cout << negative.execute(1, 2) << endl;}
    catch(exception)
    {cout << "'negative.execute(1, 2)' throws exception as expected." << endl;}
    Operator exponent("^");
    cout << exponent.execute(2, 3) << endl;
    cout << exponent.execute(4, 0.5) << endl;
    Operator times("*");
    cout << times.execute(5, 2) << endl;
    cout << times.execute(10, 0.5) << endl;
    Operator dividedBy("/");
    cout << dividedBy.execute(3, 2) << endl;
    cout << dividedBy.execute(0, 1) << endl;
    try
    {cout << dividedBy.execute(1, 0) << endl;}
    catch(exception)
    {cout << "'dividedBy.execute(1, 0)' throws exception as expected." << endl;}
    Operator modulus("%");
    cout << modulus.execute(5, 2) << endl;
    cout << modulus.execute(5.1, 2.1) << endl;
    Operator plus("+");
    cout << plus.execute(-0.5, 1.5) << endl;
    cout << plus.execute(1, -2.5) << endl;
    Operator minus("-");
    cout << minus.execute(1, -2.5) << endl;
    cout << minus.execute(1.5, 2.5) << endl;
    Operator greaterThan(">");
    cout << greaterThan.execute(2.1, 2) << endl;
    cout << greaterThan.execute(2, 2.1) << endl;
    Operator greaterThanOrEqualTo(">=");
    cout << greaterThanOrEqualTo.execute(1, 1) << endl;
    cout << greaterThanOrEqualTo.execute(1.1, 1) << endl;
    cout << greaterThanOrEqualTo.execute(0.5, 0.9) << endl;
    Operator lessThan("<");
    cout << lessThan.execute(2, 2.1) << endl;
    cout << lessThan.execute(2.1, 2) << endl;
    Operator lessThanOrEqualTo("<=");
    cout << lessThanOrEqualTo.execute(1, 1) << endl;
    cout << lessThanOrEqualTo.execute(1.1, 1) << endl;
    cout << lessThanOrEqualTo.execute(0.5, 0.9) << endl;
    Operator equals("==");
    cout << equals.execute(2.1, 2) << endl;
    cout << equals.execute(2.1, 2.1) << endl;
    Operator notEqualTo("!=");
    cout << notEqualTo.execute(2.1, 2) << endl;
    cout << notEqualTo.execute(2.1, 2.1) << endl;
    Operator and("&&");
    cout << and.execute(1, 0.5) << endl;
    cout << and.execute(0.5, 0) << endl;
    cout << and.execute(0, 0.5) << endl;
    Operator or("||");
    cout << or.execute(0.5, 0) << endl;
    cout << or.execute(0, 0.5) << endl;
    cout << or.execute(0, 0.0) << endl;
    cout << "***" << endl;
    cout << (not < plus) << endl;
    cout << (not <= plus) << endl;
    cout << (not == increment) << endl;
    cout << (not != plus) << endl;
    cout << (not >= plus) << endl;
    cout << (not > plus) << endl;
    cout << not.hasPrecedence() << endl;
    cout << not.hasType() << endl;
    cout << not.hasCategory() << endl;
    cout << (not <= increment) << endl;
    cout << (not >= increment) << endl;
    cout << "***" << endl;
    Operator left("(");
    Operator right(")");
    cout << (left == right) << endl;
    cout << (left > not) << endl;
    cout << (right < not) << endl;
    try
    {left.execute(1);}
    catch(exception)
    {cout << "'left.execute(1)' throws exception as expected." << endl;}
    try
    {right.execute(1, 2);}
    catch(exception)
    {cout << "'right.execute(1, 2)' throws exception as expected." << endl;}
    system("pause");
    return 0;
}