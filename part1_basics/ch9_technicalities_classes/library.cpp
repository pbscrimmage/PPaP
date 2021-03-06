/**
 * library.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Part 1:
 *          Implement a Book class that could be imagined as part
 *          of software for a library. The class should have members
 *          for the ISBN, title, author, and copyright date. Also 
 *          store data on whether or not the book is checked out.
 *          Create functions for checking a book in and out and 
 *          do simple validation of data entered into a Book.
 *      Part 2:
 *          Add operators for the Book class. Have the == 
 *          and != operators check the equality of the ISBN 
 *          numbers for two books. Have the << operator print
 *          out the book data on seperate lines.
 *      Part 3:
 *          Create an enumerated type for the Book class called
 *          Genre. Have the types be fiction, nonfiction, periodical,
 *          biography, and children. Give each book a Genre and make
 *          appropriate changes to the Book constructor and member
 *          functions.
 *      Part 4:
 *          Create a Patron class for the library. The class will
 *          have a user's name, library card number, and library
 *          fees(if owed). Have functions that access this data,
 *          as well as a function to set the fee of the user. Make
 *          a helper function that returns a bool depending on 
 *          whether or not the user owes a fee.
 */ 
#include "../std_lib_facilities.h"

enum Genre {
    fiction=0, nonfiction, periodical, biography, children
};

class Book {
public:
    Book(string I, string t, string a, int cr, Genre newG);

    //Nonmodifying operations
    string getISBN() {
        return ISBN;
    }
    string getTitle() {
        return title;
    }
    string getAuthor() {
       return author;
    } 
    int getCrDate() {
        return crDate;
    }
    string getGenre() {
        return genres[g];
    }

    //Modifying operations
    void setISBN(string I);
    void setTitle(string t);
    void setAuthor(string author);
    void setCrDate(int cr);
    void setGenre(Genre newG);
    void checkIn() {
        checkedOut = false;
    }
    void checkOut() {
        checkedOut = true;
    }
private:
    string ISBN;
    string title;
    string author;
    int crDate;
    Genre g;
    vector<string> genres{"fiction","nonfiction","periodical",
                            "biography","children"};
    bool checkedOut;
    bool isValidISBN(string ISBN);
};

Book::Book(string I, string t, string a, int cr, Genre newG)
{   
    setISBN(I);
    setTitle(t);
    setAuthor(a);
    setCrDate(cr);
    setGenre(newG);
    checkIn();
}

void Book::setISBN(string I)
{
    if (!isValidISBN(I))
        error("invalid ISBN");
    else
        ISBN = I;
}

bool Book::isValidISBN(string I)
{
    //is an integer and x is a letter or digit.
    for (int i = 1; i <= 3; ++i) {
        int seperator = I.find_first_of('-');
        if (seperator == -1)
            return false;
        for (int j = 0; j < seperator; ++j) {
            if (!isdigit(I[j]))
                return false;
        }
        I = I.substr(seperator+1);
    }        
    if (I.size() != 1 || !isalnum(I[0]))
        return false;
    return true;
}

void Book::setTitle(string t)
{
    if (t.size() > 0)
        title = t;
    else
        error("invalid title");
}

void Book::setAuthor(string a)
{
    if (a.size() > 0)
        author = a;
    else
        error("invalid author");
}

void Book::setCrDate(int cr)
{
    if (cr > 0)
        crDate = cr;
    else
        error("invalid copyright date");
}

void Book::setGenre(Genre newG)
{
    g = newG;
}

ostream& operator<<(ostream& os, Book b)
{
    return os << "ISBN: " << b.getISBN() << '\n'
        << "Title: " << b.getTitle() << '\n'
        << "Author: " << b.getAuthor() << '\n'
        << "Copyright: " << b.getCrDate() << '\n'
        << "Genre: " << b.getGenre() << '\n';
}

bool operator==(Book b1, Book b2)
{
    if (b1.getISBN() == b2.getISBN())
        return true;
    else
        return false;
}

bool operator!=(Book b1, Book b2)
{
    if (b1.getISBN() != b2.getISBN())
        return true;
    else
        return false;
}

class Patron {
public:
    Patron(string s, int n, int f);
    //Modifying operations
    string getName()
        { return name; }
    int getCardNum()
        { return cardNum; }
    int getFees()
        { return fees; }
    bool owesFee();

    //Modifying operations
    void setName(string s);
    void setCardNum(int n);
    void setFees(int f);
private:
    string name;
    int cardNum;
    int fees;
};

Patron::Patron(string s, int n, int f)
{
    setName(s);
    setCardNum(n);
    setFees(f);
}

void Patron::setName(string s)
{
    if (s.size() > 0)
        name = s;
    else
        error("invalid name");
}

void Patron::setCardNum(int n)
{
    if (n > 0)
        cardNum = n;
    else
        error("invalid card number");
}

void Patron::setFees(int f)
{
    if (f >= 0)
        fees = f;
    else
        error("invalid fee");
}

bool Patron::owesFee()
{
    if (fees > 0)
        return true;
    else
        return false;
}

int main()
{
    try
    {
        Book goodBook{"1234-865-4839-a",
            "My System",
            "Nimzowitsch",
            1925, 
            nonfiction};

        Book badBook{"0-0-0-z",
            "My Life",
            "Patrick Rummage",
            2016, 
            biography};

        cout << goodBook;
        bool compare = goodBook==badBook; 
        cout << compare << '\n';
        
        Patron me{"Patrick",1,999};
        if (me.owesFee())
            cout << me.getName() << " owes: " << me.getFees() << '\n';
    }
    catch (exception& e) {
        cerr << "ERROR: " << e.what() << '\n'; 
        return 1;
    }
    catch (...) {
        cerr << "ERROR: unknown exception" << '\n';
        return 2;
    }
    return 0;
}
