/*Converts miles to kilometers*/
#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter number of miles: ";
    double miles;
    cin >> miles;
    double kilometers = miles * 1.609;
    cout << to_string(miles) << " miles is " << to_string(kilometers)
        << " kilometers.\n";

    return 0;
}
