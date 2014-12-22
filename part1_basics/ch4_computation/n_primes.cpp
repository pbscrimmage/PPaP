/*Finds the first n prime numbers, where n is given by the user*/
#include "../std_lib_facilities.h"

int main()
{
    cout << "Find how many primes?:\n";
    int n;
    cin >> n;

    vector<int>primes;
    primes.push_back(2); //First prime

    /*calculate primes*/
    int count = 1;
    int num = 3;
    while (count < n) {
        bool is_prime = true;
        for (int x : primes) {
            if (num % x == 0) {//num is divisible by a prime
                is_prime = false;
                num++;
                break; //Check next num
            }//End if
        }//End for
        if (is_prime) {   
            primes.push_back(num);
            num++;
            count++;
        }
    }//End while

    /*output*/
    int cols = 0;
    for (int y : primes) {
        cout << y << "\t";
        cols++;
        if (cols == 10) {//print 10 nums per row
            cout << "\n";
            cols = 0;
        }
    }
    cout << "\n";

    return 0;
}
