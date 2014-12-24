/* Takes input in either Celsius or Kelvin and converts to the other unit. 
 * Throws a runtime error if the input is below absolute zero (-273.15 C or 0 K)*/
#include "../std_lib_facilities.h"


double ctok(double c)
{
    if (c < -273.15)
        error("Input is below absolute zero.");
    double k = c + 273.15;
    return k;
}

double ktoc(double k)
{
    if (k < 0)
        error("Input is below absolute zero.");
    double c = k - 273.15;   
    return c;
}

int main()
{
    cout << "Enter a value followed by a space and the unit ('c' or 'k'):\n";
    double input = 0;
    char unit = '\0';
    cin >> input >> unit;
    if (unit == 'c' || unit == 'C') {
        double k = ctok(input);
        cout << input << "C in Kelvins is " << k << "\n";
    }
    else if (unit == 'k' || unit == 'K') {
        double c = ktoc(input);
        cout << input << "K in degrees Celsius is " << c << "\n";
    }
    else
        error("Invalid unit");

    return 0;
}
