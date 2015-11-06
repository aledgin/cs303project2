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


const double Evaluator::evaluate(string equation) {

    if (equation.length() == 0)
        throw invalid_argument("expression cannot be empty");

	bool hitNumber = false;
	bool hitOperator = false;
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
				subIdx++;
                if (subIdx > equation.length() - 1)
                {
                    string error = "parenthesis error @ char " + to_string(equation.length() - 1);
                    throw invalid_argument(error);
                }
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
			if (hitOperator == false && !numbers.empty()) {
				string error = "expression cannot have two operands in a row @ char " + to_string(index);
				throw std::invalid_argument(error);
			}
			hitNumber = true;
			double newOperand = 0;
			string newOperandString;
			while (isdigit(equation[index])) {
				newOperandString += equation[index];
				index++;
			}
			hitOperator = false;
			numbers.push(stoi(newOperandString));
		}

		else { // The item must be an operator.
			hitOperator = true;
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
				if (equation[index - 1] == equation[index] || equation[index - 1] == '!'
					|| equation[index - 1] == '<' || equation[index - 1] == '>') // Check for valid two-char operator.
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
            Operator tempO; // Create new operator and test it for errors.
            try
            {
			    tempO = Operator(temp);
            }
            catch(exception)
            {
                string error = "operator error @ char " + to_string(index - 1);
                throw invalid_argument(error);
            }
            if (tempO.hasType() == ")") // Misplaced closing parenthesis.
            {
                string error = "parenthesis error @ char " + to_string(index - 1);
                throw invalid_argument(error);
            }
			if (opStack.empty()) {
				if (hitNumber == false && tempO.hasCategory() == 'b' && numbers.empty()) {
					string message = "cannot start expression with binary operator @ char " + to_string(index - 1);
					throw invalid_argument(message);
				}
				else if (hitNumber == false && temp == ")" && numbers.empty()) {
					string message = "cannot start expression with closing parenthesis @ char " + to_string(index - 1);
					throw invalid_argument(message);
				}
				opStack.push(tempO);
				hitNumber = false;
			}
			else if (tempO < opStack.top()) {
				while (!opStack.empty() && tempO < opStack.top()) {
					if (opStack.top().hasCategory() == 'u') {
						double tempNum1 = numbers.top();
						numbers.pop();
						try
						{
						    numbers.push(opStack.top().execute(tempNum1));
						}
                        catch(exception)
                        {
                            string message = "division by zero @ char " + to_string(index);
                            throw invalid_argument(message);
                        }
						opStack.pop();
					}
					else if (opStack.top().hasCategory() == 'b') {
						double tempNum1 = numbers.top();
						numbers.pop();
						double tempNum2 = numbers.top();
						numbers.pop();
                        try
                        {
                            numbers.push(opStack.top().execute(tempNum2, tempNum1));
                        }
                        catch (exception)
                        {
                            string message = "division by zero @ char " + to_string(index);
                            throw invalid_argument(message);
                        }
						opStack.pop();
					}
				}
				opStack.push(tempO);
			}
			else {
				if (!opStack.empty()) {
					if (tempO.hasCategory() == 'b' && opStack.top().hasCategory() == 'b' && hitNumber == false) {
						string message = "cannot have two binary operators in a row @ char " + to_string(index);
						throw invalid_argument(message);
					}
					else if (tempO.hasCategory() == 'b' && opStack.top().hasCategory() == 'u' && hitNumber == false) {
						string message = "cannot have a unary operator followed by a binary operator @ char " + to_string(index);
						throw invalid_argument(message);
					}
					else if (temp == ")") {
						string message = "closing brace before opening @ char " + to_string(index);
						throw invalid_argument(message);
					}
				}
				opStack.push(tempO);
				hitNumber = false;
			}
		}

	}

	while (index = equation.size() && !opStack.empty()) { // After all of the numbers are read, we need to finish evaluating.
		if (opStack.top().hasCategory() == 'u') {
			double tempNum1 = numbers.top();
			numbers.pop();
            try
            {
                numbers.push(opStack.top().execute(tempNum1));
            }
            catch (exception)
            {
                string message = "division by zero @ char " + to_string(index);
                throw invalid_argument(message);
            }
			opStack.pop();
		}
		if (opStack.empty())
			break;
		if (opStack.top().hasCategory() == 'b') {
			double tempNum1 = numbers.top();
			numbers.pop();
			double tempNum2 = numbers.top();
			numbers.pop();
            try
            {
                numbers.push(opStack.top().execute(tempNum2, tempNum1));
            }
            catch (exception)
            {
                string message = "division by zero @ char " + to_string(index);
                throw invalid_argument(message);
            }
			opStack.pop();
		}
	}

	return numbers.top();

}
