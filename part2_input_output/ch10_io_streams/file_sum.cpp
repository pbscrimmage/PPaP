/**
 * file_sum.cpp
 *
 * Author: Patrick Rummage
 *          [patrickbrummage@gmail.com]
 *
 * Objective:
 *      Create a program that reads a file of whitespace
 *      separated integers and computes the sum.
 */
#include "../std_lib_facilities.h"

int add_from_file(const string& filename)
{
    ifstream ist {filename};
    if (!ist)
        error("Can't open file for reading: ", filename);

    int total = 0;
    int n;
    while (ist >> n)
        total += n;
    
    return total;
}

int main()
{
    string filename;
    cout << "Enter the name of the file: \n";
    cin >> filename;

    int filesum = add_from_file(filename);

    cout << "Sum: " << filesum << '\n';

    return 0;
}
