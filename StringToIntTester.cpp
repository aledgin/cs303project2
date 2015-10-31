// FOR TESTING ONLY--DO NOT TURN IN
// Alfred Ledgin
// 10/31/2015
// CS 303
// Project 4

#include <iostream>
#include <string>
#include "StringToInt.h"
using namespace std;


int main()
{
    StringToInt converterA("123");
    cout << converterA.convert() << endl;
    StringToInt converterB;
    cout << converterB.convert() << endl;
    converterB.input("54321");
    cout << converterB.convert() << endl;
    cout << (converterB.convert() + 1) << endl;
    cout << (converterB.convert() * 10) << endl;
    cout << -(converterB.convert()) << endl;
    converterB.input("1a2");
    try
    {cout << converterB.convert() << endl;}
    catch(exception)
    {cout << "Converting '1a2' raises exception as expected." << endl;}
    converterB.input("-12");
    try
    {
        cout << converterB.convert() << endl;
    }
    catch (exception)
    {
        cout << "Converting '-12' raises exception as expected." << endl;
    }
    system("pause");
    return 0;
}