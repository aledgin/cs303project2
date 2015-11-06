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


	const double evaluate(string equation);


	const double evaluate() { return evaluate(eqString); }


private:

	string eqString;

};