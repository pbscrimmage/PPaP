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
            {return numerator / denominator; }

    private:
        int numerator;
        int denominator;
};

/* Assignment operator 
void operator=(Rational r1, Rational r2) {
    r1.setn(r2.getn());
    r1.setd(r2.getd());
}
*/

/* Addition operator */
Rational operator+(Rational r1, Rational r2) {
    // Common Denominator-ize
    Rational newR1{r1.getn() * r2.getd(), r1.getd() * r2.getd()};
    Rational newR2{r2.getn() * r1.getd(), r2.getd() * r1.getd()};

    // Add
    Rational result{newR1.getn() + newR2.getn(), newR2.getd()};
    return result; 
}

/* Subtraction operator */
Rational operator-(Rational r1, Rational r2) {
    // Common Denominator-ize
    Rational newR1{r1.getn() * r2.getd(), r1.getd() * r2.getd()};
    Rational newR2{r2.getn() * r1.getd(), r2.getd() * r1.getd()};

    // Subtract
    Rational result{newR1.getn() - newR2.getn(), newR2.getd()};
    return result;
}

/* Multiplication operator */
Rational operator*(Rational r1, Rational r2) {
    int num = r1.getn() * r2.getn();
    int denom = r1.getd() * r2.getd();

    Rational result{num, denom};
    return result;
}

/* Division operator */
Rational operator/(Rational r1, Rational r2) {
    Rational flipped{r2.getd(), r2.getn()};
    return r1 * flipped;
}

/* Equality operator */
bool operator==(Rational r1, Rational r2) {
    double real1 = r1.getn() / r1.getd();
    double real2 = r2.getn() / r2.getd();

    return real1 == real2;
}

int main() {
    Rational r1{2,5};
    Rational r2{3,4};

    Rational add = r1 + r2;
    Rational sub = r1 - r2;
    Rational mult = r1 * r2;
    Rational div = r1 / r2;

    cout << "Result for 2/5 + 3/4: " << add.getn() << "/" << add.getd() << "\n";
    cout << "Result for 2/5 - 3/4: " << sub.getn() << "/" << sub.getd() << "\n";
    cout << "Result for 2/5 * 3/4: " << mult.getn() << "/" << mult.getd() << "\n";
    cout << "Result for 2/5 / 3/4: " << div.getn() << "/" << div.getd() << "\n";

    return 0;
}
