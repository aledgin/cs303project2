// Originally Written by Luke Simmons and Megan Sword
// Edited by Alfred Ledgin
// 11/4/2015
// CS 303
// Project 2

#pragma once
#include <string>
#include <stack>
#include "Operator.h"
using namespace std;


class Evaluator {

public:


	Evaluator(string line);


	Evaluator();


    double evaluate(string equation);


    double evaluate() { return evaluate(eqString); }

<<<<<<< HEAD

<<<<<<< HEAD

=======
>>>>>>> parent of 056ddd3... test function -written by megan

=======
>>>>>>> b4abc77b9f92b5c6501d1f756ba1436116a88c1c
private:


    bool test(string equation);


	string eqString;

};