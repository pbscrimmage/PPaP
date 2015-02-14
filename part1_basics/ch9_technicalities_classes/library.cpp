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
 */ 
#include "../std_lib_facilities.h"

class Book {
public:
    Book(string I, string t, string a, int cr);

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

    //Modifying operations
    void setISBN(string I);
    void setTitle(string t);
    void setAuthor(string author);
    void setCrDate(int cr);
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
    bool checkedOut;
    bool isValidISBN(string ISBN);
};

Book::Book(string I, string t, string a, int cr)
{   
    setISBN(I);
    setTitle(t);
    setAuthor(a);
    setCrDate(cr);

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
    //Validate ISBN is in format n-n-n-x where each n 
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

ostream& operator<<(ostream& os, Book b)
{
    return os << "ISBN: " << b.getISBN() << '\n'
        << "Title: " << b.getTitle() << '\n'
        << "Author: " << b.getAuthor() << '\n'
        << "Copyright: " << b.getCrDate() << '\n';
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

int main()
{
    try
    {
        Book goodBook{"1234-865-4839-a","My System","Nimzowitsch",1925};
        Book badBook{"0-0-0-z","My Life","Patrick Rummage",2016};

        cout << goodBook;
        bool compare = goodBook==badBook; 
        cout << compare << '\n';
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
