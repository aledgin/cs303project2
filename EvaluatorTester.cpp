// Alfred Ledgin
// 11/4/2015
// CS 303
// Project 2

#include <iostream>
#include <string>
#include "Evaluator.h"
using namespace std;

int main()
{
    // (1/2) is being evaluated as 0 when using parentheses.  Need to figure out why.
    Evaluator evtest("2*(1/2)");
    cout << evtest.evaluate() << endl;
    Evaluator ev1a("3---2"); // Good!
    cout << ev1a.evaluate() << endl;
    Evaluator eva("!1");
    cout << eva.evaluate() << endl;
    Evaluator evb("++1");
    cout << evb.evaluate() << endl;
    Evaluator evc("--5");
    cout << evc.evaluate() << endl;
    Evaluator evd("-1");
    cout << evd.evaluate() << endl;
    Evaluator eve("-2+1");
    cout << eve.evaluate() << endl;
    cout << "Note: Using negation internally does not work. FIXED" << endl;
    Evaluator evf("++++2");
    cout << evf.evaluate() << endl;
    Evaluator evg("1+++2");
    cout << evg.evaluate() << endl;
    Evaluator evh("1--2"); // Good!
    cout << evh.evaluate() << endl;
    Evaluator evi("2+-1");
    cout << evi.evaluate() << endl;
    Evaluator ev1("1+1");
    cout << ev1.evaluate() << endl;
    cout << "Note that evaluating an expression results in two identical output strings." << endl;
    Evaluator ev2("1-1");
    cout << ev2.evaluate() << endl;
    Evaluator ev3("0-1");
    cout << ev3.evaluate() << endl;
    Evaluator ev4("1+2*3");
    cout << ev4.evaluate() << endl;
    Evaluator ev5("(1+2)*3");
    cout << ev5.evaluate() << endl;
    Evaluator ev6("5/2");
    cout << ev6.evaluate() << endl;
    cout << "Note that the result is a double converted to a string.  The final result should be an int (doubles should only be used internally)." << endl;
    Evaluator ev7("9^(1/2)");
    cout << ev7.evaluate() << endl;
    cout << "Note that \"9^(1/2)\" is incorrectly evaluated as 1." << endl;
    Evaluator ev8("3^4");
    cout << ev8.evaluate() << endl;
    Evaluator ev9("6%4");
    cout << ev9.evaluate() << endl;
    Evaluator ev10("2>1");
    cout << ev10.evaluate() << endl;
    Evaluator ev11("1>=2");
    cout << ev11.evaluate() << endl;
    Evaluator ev12("1<2");
    cout << ev12.evaluate() << endl;
    Evaluator ev13("2<=1");
    cout << ev13.evaluate() << endl;
    Evaluator ev14("1==2");
    cout << ev14.evaluate() << endl;
    Evaluator ev15("1!=2");
    cout << ev15.evaluate() << endl;
    Evaluator ev16("1<2 && 2>3");
    cout << ev16.evaluate() << endl;
    Evaluator ev17("1<2 || 2>3");
    cout << ev17.evaluate() << endl;
    cout << "***Moving on to unary operators...***" << endl;
    cout << "! operator does not work. FIXED" << endl;
    cout << "++ operator does not work. FIXED" << endl;
    cout << "-- operator does not work. FIXED" << endl;
    cout << "- operator does not work (range error). FIXED" << endl;
    cout << "\"Evaluator ev18(\"1 + 1\");\" does not work (memory error)." << endl;
    Evaluator ev18("100+250");
    cout << ev18.evaluate() << endl;
    system("pause");
    return 0;
}