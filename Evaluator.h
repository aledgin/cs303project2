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




private:


	//bool test(string line); // We need to write this.


	string eqString;

};