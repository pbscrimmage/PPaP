/*Gets 3 ints from user and outputs them in order separated by commas*/
#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter number 1:\n";
    int num1;
    cin >> num1;

    int lowest = num1;
    int largest = num1;
    int middle = num1;

    cout << "Enter number 2:\n";
    int num2;
    cin >> num2;
    if (num2 < lowest)
        middle = lowest;
        lowest = num2;
    if (num2 > largest)
        largest = num2;

    cout << "Enter number 3:\n";
    int num3;
    cin >> num3;
    if (num3 < lowest)
        middle = lowest;
        lowest = num3;
    if (num3 > largest)
        largest = num3;

    cout << to_string(lowest) << ", " << to_string(middle) << ", " 
        << to_string(largest) << "\n";
    return 0;
}


