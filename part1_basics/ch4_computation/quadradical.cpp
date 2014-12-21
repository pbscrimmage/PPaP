/*Produces the roots of a quadratic equation given inputs for a, b, and c*/
#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter values for a, b, and c separated by spaces:\n";
    double a, b, c;
    cin >> a >> b >> c;

    double discriminant = (b*b) - (4*a*c);
    double x1 = 0;
    double x2 = 0;
    x1 = (-b + sqrt(discriminant)) / (2*a);
    x2 = (-b - sqrt(discriminant)) / (2*a);

    cout << "x1: " << x1 << "\t" << "x2: " << x2 << "\n";

    return 0;
}
