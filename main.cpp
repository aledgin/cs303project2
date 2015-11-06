// Alfred Ledgin
// 11/5/2015
// CS 303
// Project 2

#include <iostream>
#include <string>
#include "EvalOutput.h"
using namespace std;

int main()
{
    EvalOutput output("2==3 4");
    output.report();
    system("pause");
    return 0;
}