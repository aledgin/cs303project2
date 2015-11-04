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
    cout << converterA.obtainInt() << endl;
    StringToInt converterB;
    cout << converterB.obtainInt() << endl;
    converterB.input("54321");
    cout << converterB.obtainInt() << endl;
    cout << (converterB.obtainInt() + 1) << endl;
    cout << (converterB.obtainInt() * 10) << endl;
    cout << -(converterB.obtainInt()) << endl;
    try
    {converterB.input("1a2");}
    catch(exception)
    {cout << "Converting '1a2' raises exception as expected." << endl;}
    try
    {converterB.input("-12");}
    catch(exception)
    {cout << "Converting '-12' raises exception as expected." << endl;}
    StringToInt converterC;
    cout << converterC.obtainInt("789") << endl;
    cout << (converterC.obtainInt("456") + 1) << endl;
    cout << (converterC.obtainInt("456") * 10) << endl;
    system("pause");
    return 0;
}