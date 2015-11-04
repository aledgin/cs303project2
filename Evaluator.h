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
	double evaluate(); // Alfred modified...
	bool test();
	string getValue();
	double getTotal() {
		return numbers.top(); // Alfred modified...
	}
private:
	stack<Operator> opStack;
    stack<double> numbers; // Alfred added...
	string equation;
	string number;
	int numOfOpenPar;
	int numOfClosePar;
	string total;
};