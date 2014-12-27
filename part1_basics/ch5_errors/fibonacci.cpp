/* Prints out the first n values in the fibonacci series, where n is given
 * by the user. If the next value in the series is too large for an int, 
 * the program stops and prints the largest fibonacci number smaller than
 * an int*/
#include "../std_lib_facilities.h"

int main()
{
    cout << "Number of values to print: ";
    int n;
    cin >> n;

    int minus2 = 0;
    int minus1 = 1;
    cout << minus1 << "\t\t"; //First num in series
    for (int count = 2, num = 1; count <= n; count++) {
        num = minus1 + minus2;
        if (num < 0) { //num is larger than int
            int largest = minus1;
            cout << "\nERROR: Largest fibonacci number to fit in an int is: "
                << largest << ",\n" << "which is number " << count - 1
                << " in the series.\n";
            break;
        }
        minus2 = minus1;
        minus1 = num; 
        cout << num << "\t\t";
        if (count % 2 == 0)
            cout << "\n"; //Print 2 columns
    }
    cout << "\n";

    return 0;
}
