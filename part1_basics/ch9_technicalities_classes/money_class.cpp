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
        void setAmt(long int newAmt)
            {amt = newAmt; }

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
double operator*(Money m1, double num)
{
    double result = m1.getAmt() * num;

    return result;
}

/* DIVISION */
double operator/(Money m1, double num)
{
    double result = m1.getAmt() / num;

    return result;
}

/* EQUALITY */
bool operator==(Money m1, Money m2)
{
    return m1.getAmt() == m2.getAmt();
}

/* OUTPUT */
ostream& operator<<(ostream& os, Money m)
{
    return os << m.getAmt() / 100 << "." << m.getAmt() % 100;
}

/* INPUT */
istream& operator>>(istream& is, Money& m)
{
    double dollars;
    is >> dollars;

    long int cents = narrow_cast<long int>(dollars * 100);
    m.setAmt(cents);
}

int main()
{
    Money fiDolla{5000};
    Money tuDolla{2000};
    double d = 2.3;

    Money addDolla = fiDolla + tuDolla;
    Money subDolla = fiDolla - tuDolla;
    double multDolla = fiDolla * d;
    double divDolla = fiDolla / d;

    cout << "Addition: " << addDolla << "\n";
    cout << "Subtraction: " << subDolla << "\n";
    cout << "Multiplication: " << multDolla << "\n";
    cout << "Division: " << divDolla << "\n";

    Money mIn;
    cout << "Input an amout in USD: " << "\n";
    cin >> mIn;
    cout << "Amout in Money object: " << mIn << "\n";

    return 0;
}
