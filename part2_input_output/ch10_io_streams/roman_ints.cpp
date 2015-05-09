/**
 * roman_ints.cpp
 *
 * Author: Patrick Rummage
 *          [patrickbrummage@gmail.com]
 *
 * Objective:
 *      Create a class Roman_int to hold Roman numerals
 *      with overloaded input and output operators and a
 *      means to convert between string and integer 
 *      representations of the numeral.
 */
#include "../std_lib_facilities.h"
#include <map>

class Roman_int {
    public:
        Roman_int()
            :numeral{""}, val{0} {};
        int as_int()
            { return val; }
        string get_num()
            { return numeral; }
        void set_num(string newNum)
            { numeral = newNum; }
        void set_val(int newVal)
            { val = newVal; }
    private:
        int val;
        string numeral;
};

int convert_to_int(const string& numeral)
{
    map<char, int> table;

    table['I'] = 1;
    table['V'] = 5;
    table['X'] = 10;
    table['L'] = 50;
    table['C'] = 100;
    table['D'] = 500;
    table['M'] = 1000;

    int res = 0;
    char prev = numeral.size();
    for (int i = numeral.size()-1; i >= 0; --i) {
        if (table[numeral[i]] < table[prev]) {
            res -= table[numeral[i]];
        } else {
            res += table[numeral[i]];
        }       
        prev = numeral[i];
    }

    return res;
}

istream& operator>>(istream& ist, Roman_int& r)
{
    string newNum;
    ist >> newNum;
    r.set_num(newNum);
    r.set_val(convert_to_int(newNum));

    return ist;
}

ostream& operator<<(ostream& ost, Roman_int& r)
{
    return ost << r.get_num();
}

int main()
{
    Roman_int r;
    cout << "Enter a roman numeral: \n";
    cin >> r;

    cout << "Roman " << r << " equals " << r.as_int() << '\n';
    
    return 0;
}
