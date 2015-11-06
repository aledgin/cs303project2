// Alfred Ledgin
// 11/5/2015
// CS 303
// Project 2

#include <iostream>
#include <string>
#include "Evaluator.h"
using namespace std;


class EvalOutput
// This class is a partial user interface with the Evaluator class,
    // for the purpose of displaying the output resulting from a given
    // input expression.
{

    public:


        EvalOutput() {expression = "";}
        // Preconditions: An EvalOutput object needs to be created without an
            // input string.
        // Postconditions: This default constructor creates an EvalOutput
            // object and sets the expression to an empty string.


        EvalOutput(string input) {expression = input;}
        // Preconditions: An EvalOutput object needs to be created with the
            // given string.
        // Postconditions: This constructor creates an EvalOutput object and
            // sets the expression to the given string.


        void report() {report(expression);}
        // Preconditions: A stored expression needs to be evaluated,
            // with the result output appropriately.
        // Postconditions: This function passes the expression to the
            // next function, so the result of the evaluated expression
            // is output appropriately.


        void report(string input)
        // Preconditions: A given expression needs to be evaluated,
            // with the result output appropriately.
        // Postconditions: This function attempts to evaluate the given
            // expression.  If it is successful, it displays the output.
            // If it is unsuccessful, it displays the error message.
        {
            try
            {
                int result = current.evaluate(input);
                cout << "Result: " << result << endl;
            }
            catch (invalid_argument& error)
            {
                cout << "Error: " << error.what() << endl;
                // Reference:
                    // "std::invalid_argument." _cplusplus.com_.
                        // cplusplus.com, 2015. Web. 5 Nov. 2015.
                        // <http://www.cplusplus.com/reference/stdexcept/invalid_argument/>.
            }
        }


    private:

        Evaluator current;
        string expression;

};