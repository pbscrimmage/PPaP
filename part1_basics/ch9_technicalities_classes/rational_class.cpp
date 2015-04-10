/**
 * rational_class.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Design and implement a rational number class, Rational.
 *      Provide assignment, addition, subtraction, multiplication,
 *      division, and equality operators. Also provide a conversion
 *      to Double.
 */
#include "../std_lib_facilities.h"

class Rational {
    public:
        Rational(int n, int d)
            :numerator{n}, denominator{d} {}
        int getn()
            {return numerator; }
        int getd()
            {return denominator; }
        void setn(int n)        // set numerator
            {numerator = n; }
        void setd(int d)        // set denominator
            {denominator = d; }
        double toReal()           // conversion to double
            {return (double)numerator / denominator; }
        /** OPERATORS **/
        void operator=(Rational r2)     //Assignment
            {numerator = r2.getn(); denominator = r2.getd();}
        Rational operator+(Rational r2); //Addition
        Rational operator-(Rational r2); //Subtraction
        Rational operator*(Rational r2); //Multiplication
        Rational operator/(Rational r2); //Division
        bool operator==(Rational r2); //Equality

    private:
        int numerator;
        int denominator;
};


/* Addition operator */
Rational Rational::operator+(Rational r2) {
    // Common Denominator-ize
    Rational newR1{this->getn() * r2.getd(), this->getd() * r2.getd()};
    Rational newR2{r2.getn() * this->getd(), r2.getd() * this->getd()};

    // Add
    Rational result{newR1.getn() + newR2.getn(), newR2.getd()};
    return result; 
}

/* Subtraction operator */
Rational Rational::operator-(Rational r2) {
    // Common Denominator-ize
    Rational newR1{this->getn() * r2.getd(), this->getd() * r2.getd()};
    Rational newR2{r2.getn() * this->getd(), r2.getd() * this->getd()};

    // Subtract
    Rational result{newR1.getn() - newR2.getn(), newR2.getd()};
    return result;
}

/* Multiplication operator */
Rational Rational::operator*(Rational r2) {
    int num = this->getn() * r2.getn();
    int denom = this->getd() * r2.getd();

    Rational result{num, denom};
    return result;
}

/* Division operator */
Rational Rational::operator/(Rational r2) {
    Rational left{this->getn(), this->getd()};
    Rational flipped{r2.getd(), r2.getn()};
    return  left * flipped;
}

/* Equality operator */
bool Rational::operator==(Rational r2) {
    double real1 = this->getn() / this->getd();
    double real2 = r2.getn() / r2.getd();

    return real1 == real2;
}

ostream& operator<<(ostream& os, Rational r) 
{
    return os << r.getn() << "/" << r.getd();
}

int main() {
    Rational r1{2,5};
    Rational r2{3,4};

    Rational add = r1 + r2;
    Rational sub = r1 - r2;
    Rational mult = r1 * r2;
    Rational div = r1 / r2;
    bool equalityTest = Rational{5,8} == Rational{10,16};

    cout << "Result for 2/5 + 3/4: " << add << "\n";
    cout << "Result for 2/5 - 3/4: " << sub << "\n";
    cout << "Result for 2/5 * 3/4: " << mult << "\n";
    cout << "Result for 2/5 / 3/4: " << div << "\n";
    cout << "Equality Test: ";
    if (equalityTest) {
        cout << "True" << "\n";
    } else {
        cout << "False" << "\n";
    }
    cout << r2 << " in decimal form: " << r2.toReal() << "\n";

    return 0;
}
