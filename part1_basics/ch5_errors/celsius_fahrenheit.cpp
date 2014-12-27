/* Converts between Celsius and Fahrenheit */
#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter value followed by a space and a 'C' or 'F' to indicate unit: ";
    double val;
    char unit;
    cin >> val >> unit;

    if (unit == 'c' || unit == 'C') {
        double df = (9.0/5) * val + 32;
        cout << df << " F\n";
    }
    else if (unit == 'f' || unit == 'F') {
        double dc = (val - 32) * (5.0/9);
        cout << dc << " C\n";
    }
    else
        cout << "ERROR: Invalid unit.";

    return 0;
}
