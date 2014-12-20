/* Uses the classical 'Sieve of Eratosthenes' method to find all primes up  
 * to a user-given limit.*/
#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter an upper bound for the sieve (integer > 1):\n";
    int MAX;
    cin >> MAX;

    if (MAX <= 1)
        simple_error("Invalid input");

    /*Create an array of bools set to 'true' up to MAX*/
    bool nums[MAX];
    for (int i = 2; i <= MAX; i++) 
        nums[i] = true;

    /*The Sieve*/
    int loop_max = sqrt(MAX);
    for (int i = 2; i <= loop_max; i++) {
        if (nums[i] == true) {
            int multiplier = 2;
            for (int j = i*i; j <= MAX; j = i + multiplier * i, multiplier++) {
                nums[j] = false; //Filter out multiples of primes  
            } //End for
        } //End if
    }

    /*Output*/
    for (int i = 2, count = 0; i <= MAX; i++) {
        if (count == 10) { //Print 10 columns
            cout << "\n";
            count = 0;
        }
        if (nums[i] == true) {
            cout << i << "\t";
            count++;
        }
    }
    cout << "\n";

    return 0;
}
