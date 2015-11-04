// Originally written by Luke Simmons and Megan Sword
// Edited by Alfred Ledgin
// 11/4/2015
// CS 303
// Project 2

#include "Evaluator.h" // Alfred note: I removed "#include "StringToInt.h."
using namespace std;

Evaluator::Evaluator() {
	equation = "";
	numOfOpenPar = 0;
	numOfClosePar = 0;
}

Evaluator::Evaluator(string line) {
	equation = line;
	number = "";
	numOfOpenPar = 0;
	numOfClosePar = 0;
	total = evaluate();
}

string Evaluator::evaluate() {
	int index = 0;
	while (index < equation.size()) {
		if (equation[index] == ' ') {
			index++;
		}
		else if (equation[index] == '(') {//If the item is an '(' simply add it to the stack
			string temp;
			temp += equation[index];
			Operator tempO = Operator(temp);
			opStack.push(tempO);
			numOfOpenPar++;
			index++;
		}
		else if (isdigit(equation[index])) { //If the item is a digit build the number until the item is no longer a digit
			while (isdigit(equation[index])) {
				number += equation[index];
				index++;
			}
			number += " ";
		}

		else if (equation[index] == ')') {//If the item is a ')' evaluate until we reach an '(' 
			string temp;
			numOfClosePar++;
			temp += equation[index];
			Operator tempO = Operator(temp);
			index++;
			while(numOfClosePar > 0){
				if (!opStack.empty() || tempO < opStack.top()) {
					if (opStack.top().hasCategory() == 'u') {
						double total;
						string stringNum;
						string tempNum1 = getValue();
						total = opStack.top().execute(stoi(tempNum1));
						stringNum = to_string(total);
						number.append(stringNum);
						number += " ";
						opStack.pop();
					}
					else if (opStack.top().hasCategory() == 'b') {
						double total;
						string stringNum;
						string tempNum1 = getValue();
						string tempNum2 = getValue();
						total = opStack.top().execute(stoi(tempNum2), stoi(tempNum1));
						stringNum = to_string(total);
						number.append(stringNum);
						number += " ";
						opStack.pop();
					}
					else {
						opStack.pop();
						numOfOpenPar--;
						numOfClosePar--;
					}
				}
			}
		}
		else {// the item must be an operator
			string temp;
			temp += equation[index];
            if (index == 0 && temp == "-")
            {
                if (equation.length() > 1 && equation[1] != '-')
                    // Alfred note: If the first operator is a -, then it is the negation operator.
                    temp += "#";
            }
            else if (equation.length() > index + 1)
            {
                if (temp == "-" && !isdigit(equation[index - 1]) && equation[index + 1] != '-')
                // Alfred note: If the operator is a -, and the preceding character is not a digit,
                    // then the operator is the negation operator.
                temp += "#";
            }
			index++;
			if (!isdigit(equation[index]) && equation[index] != '(' && equation[index] != ')' && equation[index] != '!') { // check to see if the operator contains 2 characters
				while (equation[index] == ' ') {
					index++;
				}
                if (equation[index - 1] == equation[index] || equation[index - 1] == '!'
                    || equation[index - 1] == '<' || equation [index - 1] == '>') // Alfred note: check for valid two-char operator.
                {
                    if (temp.length() == 1) // Alfred note: cannot have operator with more than 2 characters.
                    {
                        if (equation[index - 1] != '-')
                        {
                            temp += equation[index];
				            index++;
                        }
                        else // Alfred note: -- is decrement operator only in special cases.
                        {
                            if (index >= 2)
                            {
                                if (!isdigit(equation[index - 2]))
                                {

                                    {
                                        temp += equation[index];
                                        index++;
                                    }
                                }
                            }
                            else
                            {
                                temp += equation[index];
                                index++;
                            }
                        }
                    }
                }
			}
			Operator tempO = Operator(temp);
			if (opStack.empty()) {
				opStack.push(tempO);
			}
			else if (tempO < opStack.top()) {
				while (!opStack.empty() && tempO < opStack.top()) {
					if (opStack.top().hasCategory() == 'u') {
						double total;
						string stringNum;
						string tempNum1 = getValue();
						total = opStack.top().execute(stoi(tempNum1));
						stringNum = to_string(total);
						number.append(stringNum);
						number += " ";
						opStack.pop();
					}
					else if (opStack.top().hasCategory() == 'b') {
						double total;
						string stringNum;
						string tempNum1 = getValue();
						string tempNum2 = getValue();
						total = opStack.top().execute(stoi(tempNum2), stoi(tempNum1));
						stringNum = to_string(total);
						number.append(stringNum);
						number += " ";
						opStack.pop();

					}

				}
					opStack.push(tempO);
			}
			else {
				opStack.push(tempO);
			}
		}
	}
	while (index = equation.size() && !opStack.empty()) {//After all of the numbers are read we need to finish evaluating
		if (opStack.top().hasCategory() == 'u') {
			double total;
			string stringNum;
			string tempNum1 = getValue();
			total = opStack.top().execute(stoi(tempNum1));
			stringNum = to_string(total);
			number.append(stringNum);
			number += " ";
			opStack.pop();
		}
        if (opStack.empty())
            break; // Alfred note: Needed to break when opStack was empty.
		if (opStack.top().hasCategory() == 'b') {
			double total;
			string stringNum;
			string tempNum1 = getValue();
			string tempNum2 = getValue();
			total = opStack.top().execute(stoi(tempNum2), stoi(tempNum1));
			stringNum = to_string(total);
			number.append(stringNum);
			number += " ";
			opStack.pop();
		}
	}
	return number;
}
string Evaluator::getValue() { // this function will get the back number off of the number line and return it, it will also delete the number off of the line
	stack<char> numStack;
	number.pop_back();
	int index = number.size() - 1;
	string temp = "";
	numStack.push(number[index]);
	number.pop_back();
	index--;
	while (number.size() > 0 && number[index] != ' ') {
		numStack.push(number[index]);
		number.pop_back();
		index--;
	}
	while (!numStack.empty()) {
		temp += numStack.top();
		numStack.pop();
	}
	return temp;
}
