// Originally written by Luke Simmons and Megan Sword
// Edited by Alfred Ledgin
// 11/4/2015
// CS 303
// Project 2
//testing this out
#include "Evaluator.h"
using namespace std;


Evaluator::Evaluator() {
	eqString = "";
}


Evaluator::Evaluator(string line) {
	eqString = line;
}


double Evaluator::evaluate(string equation) {

    stack<Operator> opStack;
    stack<double> numbers;
	int index = 0;

	while (index < equation.size()) {

		if (equation[index] == ' ') {
			index++;
		}

		else if (equation[index] == '(') { //If the item is an '(', evaluate the substring.
            int subIdx = index;
            int parens = 1;
            while (parens > 0)
            {
                subIdx++; // Need error protection.
                if (equation[subIdx] == '(')
                    parens++;
                if (equation[subIdx] == ')')
                    parens--;
            }
            string substring = equation.substr(index + 1, subIdx - (index + 1));
            // Reference (for using substr function):
                // "std::string::substr." _cplusplus.com_. cplusplus.com, 2015.
                    // Web. 4 Nov. 2015.
                    // <http://www.cplusplus.com/reference/string/string/substr/>.
            numbers.push(evaluate(substring));
            index = subIdx;
			index++;
		}

		else if (isdigit(equation[index])) { // If the item is a digit, build the number until the item is no longer a digit.
			double newOperand = 0;
            string newOperandString;
            while (isdigit(equation[index])) {
				newOperandString += equation[index];
				index++;
			}
            numbers.push(stoi(newOperandString));
		}

		else { // The item must be an operator.
			string temp;
			temp += equation[index];
            if (index == 0 && temp == "-")
            {
                if (equation.length() > 1 && equation[1] != '-')
                    // If the first operator is a -, then it is the negation operator.
                    temp += "#";
            }
            else if (equation.length() > index + 1)
            {
                if (temp == "-" && !isdigit(equation[index - 1]) && equation[index + 1] != '-')
                // If the operator is a -, and the preceding character is not a digit,
                    // then the operator is the negation operator.
                temp += "#";
            }
			index++;
			if (!isdigit(equation[index]) && equation[index] != '('
                && equation[index] != ')' && equation[index] != '!') { // Check whether the operator contains 2 characters.
				while (equation[index] == ' ') {
					index++;
				}
                if (equation[index - 1] == equation[index] || equation[index - 1] == '!'
                    || equation[index - 1] == '<' || equation [index - 1] == '>') // Check for valid two-char operator.
                {
                    if (temp.length() == 1) // Cannot have operator with more than 2 characters.
                    {
                        if (equation[index - 1] != '-')
                        {
                            temp += equation[index];
				            index++;
                        }
                        else // -- is decrement operator only in special cases.
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
                        double tempNum1 = numbers.top();
                        numbers.pop();
                        numbers.push(opStack.top().execute(tempNum1));
						opStack.pop();
					}
					else if (opStack.top().hasCategory() == 'b') {
                        double tempNum1 = numbers.top();
                        numbers.pop();
                        double tempNum2 = numbers.top();
                        numbers.pop();
                        numbers.push(opStack.top().execute(tempNum2, tempNum1));
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

	while (index = equation.size() && !opStack.empty()) { // After all of the numbers are read, we need to finish evaluating.
		if (opStack.top().hasCategory() == 'u') {
            double tempNum1 = numbers.top();
            numbers.pop();
            numbers.push(opStack.top().execute(tempNum1));
			opStack.pop();
		}
        if (opStack.empty())
            break;
		if (opStack.top().hasCategory() == 'b') {
            double tempNum1  = numbers.top();
            numbers.pop();
            double tempNum2 = numbers.top();
            numbers.pop();
            numbers.push(opStack.top().execute(tempNum2, tempNum1));
			opStack.pop();
		}
	}

	return numbers.top();

}