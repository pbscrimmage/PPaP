/*Gets two ints from user and prints out some facts about them*/
#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter an integer:\n";
    int val1;
    cin >> val1;
    cout << "Enter another integer:\n";
    int val2;
    cin >> val2;

    if (val1 == val2)
        cout << "The two values are equal\n";
    else {
        int smaller = val1;
        int larger = val2;
        if (val2 < val1) {
            smaller = val2;
            larger = val1;
        }
        cout << "The smaller value is: " << to_string(smaller) << "\n";
        cout << "The larger value is: " << to_string(larger) << "\n";
    }

    int sum = val1 + val2;
    cout << "The sum of " << to_string(val1) << " and " << to_string(val2) 
        << " is: " << to_string(sum) << "\n";

    int difference = abs(val1 - val2);
    cout << "The difference of " << to_string(val1) << " and " << to_string(val2)
        << " is " << to_string(difference) << "\n";

    int product = val1 * val2;
    cout << "The product of " << to_string(val1) << " and " << to_string(val2)
       << " is " << to_string(product) << "\n";

    double ratio = val1 / (double)val2; 
    cout << "The ratio of " << to_string(val1) << " to " << to_string(val2)
        << " is " << to_string(ratio) << "\n";

    return 0;
}
