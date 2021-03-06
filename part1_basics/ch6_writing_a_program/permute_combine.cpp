/**
 * permute_combine.cpp
 *
 * <Author> Patrick Rummage
 *
 * Objective:
 *      Write a program that asks the user for two numbers, asks whether 
 *      they want to calculate permutations or combinations, and prints out 
 *      the result.
 *      Permutations formula: P(a, b) = a! / (a - b)!
 *      Combinations formula: C(a, b) = P(a, b) / b!
 */
#include "../std_lib_facilities.h"
#include <limits.h>

int factorial(int val)
{
    int fact = 1;
    for (int i = val; i >= 1; --i) {
        if (fact > INT_MAX / i) //Next assignment would cause overflow
            error("int overflow in factorial function");
        fact *= i;
    }
    return fact;
}

/* The denominator in the formula cancels out factorial iterations after a-b times.
 * EX: P(9,4) = (9*8*7*6*5*4*3*2*1) / (5*4*3*2*1)
 *                      = (9*8*7*6)
 */
int permutations(int a, int b)
{
    int p = a;
    for (int i = 1; i < b; ++i) {
        a -= 1;
        if (p > INT_MAX / a) //Next assignment would cause overflow
            error("int overflow in permutations function");
        p *= a;
    }
    return p;
}

int main()
{
    cout << "Enter two integer values for the set and subset followed by either"
       << " a 'P or a 'C' to get the number of permutations or combinations:\n";
    int val1, val2;
    char mode;
    cin >> val1 >> val2 >> mode;
    
    if (val1 <= 0 || val2 <= 0) 
        error("Values must be positive and non-zero");

    switch(mode) {
        case 'p': case 'P':
        {
            int p = permutations(val1, val2);
            cout << p << " permutations\n";
            break;
        }
        case 'c': case 'C':
        {
            int c = permutations(val1, val2) / factorial(val2);
            cout << c << " combinations\n";
            break;
        }
        default:
            cout << "Invalid operation: " << mode << "\n";
    }
    return 0;
}
