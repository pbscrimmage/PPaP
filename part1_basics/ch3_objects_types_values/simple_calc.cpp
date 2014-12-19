/*Takes an operation followed by two operands and outputs the result
 * EX: "+ 100 3.14"  returns 103.14
 */
#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter an operator followed by two operands:\n";
    string operation;
    double val1;
    double val2;
    cin >> operation >> val1 >> val2;

    double result = 0;
    if (operation == "+" || operation == "plus") 
        result = val1 + val2;
    if (operation == "-" || operation == "minus") 
        result = val1 - val2;
    if (operation == "*" || operation == "mul") 
        result = val1 * val2;
    if (operation == "/" || operation == "div")
        result = val1 / val2;
    cout << to_string(result) << "\n";

    return 0;
}
