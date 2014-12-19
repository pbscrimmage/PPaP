/*Gets 3 strings from the user and prints them in alphabetical order*/
#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter 1st string:\n";
    string s1;
    cin >> s1;

    string first = s1;
    string middle = s1;
    string last = s1;

    cout << "Enter 2nd string:\n";
    string s2;
    cin >> s2;
    if (s2 < first)
        middle = first;
        first = s2;
    if (s2 > last)
        last = s2;

    cout << "Enter 3rd string:\n";
    string s3;
    cin >> s3;
    if (s3 < first)
        middle = first;
        first = s3;
    if (s3 > last)
        last = s3;

    cout << first << ", " << middle << ", " << last << "\n";

    return 0;
}
