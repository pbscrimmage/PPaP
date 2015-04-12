/**
 * money_class.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Design and implement a Money class for calculations 
 *      involving dollars and cents where arithmetic has to
 *      be accurate to the last cent using the 4/5 rounding
 *      rule. (.5 of a cent rounds up; anything less than .5
 *      rounds down). Represent a monetary amount as a number
 *      of cents in a long int, but input and output as dollars
 *      and cents, e.g. $123.45.
 */
#include "../std_lib_facilities.h"

class Money {
    public:
        Money()     // Default constructor
            :amt{0} {};
        Money(long int newAmt)
            :amt{newAmt} {};
        long int getAmt()
            {return amt; }

        bool operator=(Money m2) // Assignment operator
            {amt = m2.getAmt(); }
    private:
        long int amt;
};

/* ADDITION */
Money operator+(Money m1, Money m2)
{
    Money result{m1.getAmt() + m2.getAmt()};

    return result;
}

/* SUBTRACTION */
Money operator-(Money m1, Money m2)
{
    Money result{m1.getAmt() - m2.getAmt()};

    return result;
}

/* MULTIPLICATION */
Money operator*(Money m1, Money m2)
{
    Money result{m1.getAmt() * m2.getAmt()};

    return result;
}

/* DIVISION */
Money operator/(Money m1, Money m2)
{
    Money result{m1.getAmt() / m2.getAmt()};

    return result;
}

/* EQUALITY */
bool operator==(Money m1, Money m2)
{
    return m1.getAmt() == Money m2.getAmt();
}

int main()
{
    Money fiDolla{500};
    Money tuDolla{200};

    Money addDolla = fiDolla + tuDolla;
    Money subDolla = fiDolla - tuDolla;
    Money multDolla = fiDolla * tuDolla;
    Money divDolla = fiDolla / tuDolla;

    cout << "Addition: " << addDolla.getAmt() << "\n";
    cout << "Subtraction: " << subDolla.getAmt() << "\n";
    cout << "Multiplication: " << multDolla.getAmt() << "\n";
    cout << "Division: " << divDolla.getAmt() << "\n";

    return 0;
}
