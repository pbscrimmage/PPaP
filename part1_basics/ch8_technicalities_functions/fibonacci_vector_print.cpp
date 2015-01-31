/**
 * fibonacci_vector_print.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Write a function print() that prints a vector of ints to cout and
 *      takes a string to label the output. Create a function fibonacci()
 *      that takes two ints, x and y, an empty vector, and another int n.
 *      Have the function fill the vector with n fibonacci numbers. Then 
 *      use the print() function to print out the vector.
 */
#include "../std_lib_facilities.h"

void print(string label, const vector<int>& v)
{
    cout << label << '\n';
    for (int i : v)
        cout << i << '\n';
}

void fibonacci(int x, int y, vector<int>& v, int n)
{
    v.push_back(x);
    v.push_back(y);
    for (int i = 2; i < n; ++i)
        v.push_back(v[i-1] + v[i-2]);
}

int main()
{
    try
    {
        vector<int> fibs;
        int x = 0;
        int y = 1;
        int n = 50;

        fibonacci(x, y, fibs, n);

        string label = (to_string(n) + " fibonacci numbers starting with "
                + to_string(x) + " and " + to_string(y) + ": \n");

        print(label, fibs);

        return 0;
    }
    catch (exception& e) {
        cerr << "ERROR: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        cerr << "Unknown exception!\n";
        return 2;
    }
}
