// Originally written by Luke Simmons and Megan Sword
// Edited by Alfred Ledgin
// 11/4/2015
// CS 303
// Project 2

// Alfred note: So far, so good.  NOW LET'S CLEAN THIS UP!

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

double Evaluator::evaluate() {
	int index = 0;
    //int parenIdx = 0; // Alfred note: need this variable for recursive calls to substrings.
	while (index < equation.size()) {
		if (equation[index] == ' ') {
			index++;
		}
		else if (equation[index] == '(') {//If the item is an '(' simply add it to the stack
            //parenIdx = index; // Alfred note: save this index for recursive call to substring.
            int subIdx = index;
            int parens = 1;
            while (parens > 0) // Alfred note: right idea, but only works with one set of parentheses.  Need to fix!  FIXED!!
            {
                subIdx++; // Alfred note: Need error protection here!
                if (equation[subIdx] == '(')
                    parens++;
                if (equation[subIdx] == ')')
                    parens--;
            }
            string substring = equation.substr(index + 1, subIdx - (index + 1));
            // Reference:
                // "std::string::substr." _cplusplus.com_. cplusplus.com, 2015.
                    // Web. 4 Nov. 2015.
                    // <http://www.cplusplus.com/reference/string/string/substr/>.
            Evaluator recursive(substring);
            numbers.push(recursive.getTotal());
            //number += " ";
            index = subIdx;
			//string temp;
			//temp += equation[index];
			//Operator tempO = Operator(temp);
			//opStack.push(tempO);
			//numOfOpenPar++;
			index++;
		}
		else if (isdigit(equation[index])) { //If the item is a digit build the number until the item is no longer a digit
			double newOperand = 0; // Alfred note: Let's try it this way.
            string newOperandString; // Alfred note: Saving both....
            while (isdigit(equation[index])) {
				newOperandString += equation[index];
				index++;
			}
			//number += " ";
            numbers.push(stoi(newOperandString));
		}

		//else if (equation[index] == ')') {//If the item is a ')' evaluate until we reach an '(' 
  //          // Alfred Note: Let's try to do this recursively.  It will be simpler.
  //          string substring = // SEE ABOVE!
  //          Evaluator recursiveEval(substring);
  //          number.append(recursiveEval.evaluate());
  //          number += " ";
  //          index++;
  //          numOfOpenPar--;
		//	//string temp;
		//	//numOfClosePar++;
		//	//temp += equation[index];
		//	//Operator tempO = Operator(temp);
		//	//index++;
		//	//while(numOfClosePar > 0){
		//	//	if (!opStack.empty() || tempO < opStack.top()) {
		//	//		if (opStack.top().hasCategory() == 'u') {
		//	//			double total;
		//	//			string stringNum;
		//	//			string tempNum1 = getValue();
		//	//			total = opStack.top().execute(stoi(tempNum1));
		//	//			stringNum = to_string(total);
		//	//			number.append(stringNum);
		//	//			number += " ";
		//	//			opStack.pop();
		//	//		}
		//	//		else if (opStack.top().hasCategory() == 'b') {
		//	//			double total;
		//	//			string stringNum;
		//	//			string tempNum1 = getValue();
		//	//			string tempNum2 = getValue();
		//	//			total = opStack.top().execute(stoi(tempNum2), stoi(tempNum1));
		//	//			stringNum = to_string(total);
		//	//			number.append(stringNum);
		//	//			number += " ";
		//	//			opStack.pop();
		//	//		}
		//	//		else {
		//	//			opStack.pop();
		//	//			numOfOpenPar--;
		//	//			numOfClosePar--;
		//	//		}
		//	//	}
		//	//}
		//}
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
						//string stringNum;
						//string tempNum1 = getValue();
                        double tempNum1 = numbers.top(); // Alfred added...
                        numbers.pop(); // Alfred added...
						total = opStack.top().execute(tempNum1); // Alfred modified...
						//stringNum = to_string(total);
						//number.append(stringNum);
						//number += " ";
                        numbers.push(total); // Alfred added...
						opStack.pop();
					}
					else if (opStack.top().hasCategory() == 'b') {
						double total;
						//string stringNum;
						//string tempNum1 = getValue();
						//string tempNum2 = getValue();
                        double tempNum1 = numbers.top(); // Alfred added...
                        numbers.pop(); // Alfred added...
                        double tempNum2 = numbers.top(); // Alfred added...
                        numbers.pop(); // Alfred added...
						total = opStack.top().execute(tempNum2, tempNum1); // Alfred modified...
						//stringNum = to_string(total);
						//number.append(stringNum);
						//number += " ";
                        numbers.push(total); // Alfred added...
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
            double tempNum1 = numbers.top(); // Alfred added...
            numbers.pop(); // Alfred added...
			//string stringNum;
			//string tempNum1 = getValue();
			total = opStack.top().execute(tempNum1); // Alfred modified...
			//stringNum = to_string(total);
			//number.append(stringNum);
			//number += " ";
            numbers.push(total); // Alfred added...
			opStack.pop();
		}
        if (opStack.empty())
            break; // Alfred note: Needed to break when opStack was empty.
		if (opStack.top().hasCategory() == 'b') {
			double total;
            double tempNum1  = numbers.top(); // Alfred added...
            numbers.pop(); // Alfred added...
            double tempNum2 = numbers.top(); // Alfred added...
            numbers.pop(); // Alfred added...
			//string stringNum;
			//string tempNum1 = getValue();
			//string tempNum2 = getValue();
			total = opStack.top().execute(tempNum2, tempNum1); // Alfred modified...
			//stringNum = to_string(total);
			//number.append(stringNum);
			//number += " ";
            numbers.push(total); // Alfred added...
			opStack.pop();
		}
	}
	return numbers.top();
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
