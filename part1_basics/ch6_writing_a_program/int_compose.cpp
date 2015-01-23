/**
 * int_compose.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Write a program that reads digits and composes them into
 *      integers. Example, given the input '123' the program should
 *      output '123 is 1 hundred and 2 tens and 3 ones.'
 */
#include "../std_lib_facilities.h"

void compose(int num); 

int main()
{
    int input;
    cout << "Enter an integer: ";
    cin >> input;

    compose(input);
    cout << "\n";
    return 0;
}

void compose(int input) 
{
    vector<int> digits;
    vector<string> powers = {"one", "ten", "hundred", "thousand",
        "ten thousand", "hundred thousand", "million", "ten million",
        "hundred million", "billion"};

    /*Chop up the num and store the digits in reverse order in vector*/
    int num = abs(input);
    while (num > 0) {
        int digit = num % 10;
        digits.push_back(digit);
        num /= 10;      
    }

    cout << input <<  " is ";
    if (input == 0) {
        cout << "zero";
        return;
    } else if (input < 0) {
        cout << "negative ";
    }
    for (int i = digits.size()-1; i >= 0; i--) {
        if (digits[i] == 1) {
            cout << digits[i] << " " << powers[i];
        } else if (digits[i] > 1) {    //Plural
            cout << digits[i] << " " << powers[i] << "s";
        }
        if (i == 0) {  //Last digit
            break;
        } else if (digits[i-1] == 0) {
           continue; 
        } else {
            cout << " and ";
        }
    }//End for
}

