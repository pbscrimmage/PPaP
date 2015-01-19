/**
 * expr_calculator.cpp
 *
 * A simple calculator
 *
 * Revised by Bjarne Stroustrup November 2013
 * Revised by Bjarne Stroustrup May 2007
 * Revised by Bjarne Stroustrup August 2006
 * Revised by Bjarne Stroustrup August 2004
 * Origininally written by Bjarne Stroustrup
 *      (bs@cs.tamu.edu) Spring 2004
 *
 * This program implements a basic expression calculator.
 * Input from cin. Output to cout.
 * The grammar for input is:
 *
 * Statement:
 *      Expression
 *      Print
 *      Quit
 * Print:
 *      ';'
 * Quit:
 *      'q'
 * Expression:
 *      Term
 *      Expresion + Term
 *      Expression - Term
 * Term:
 *      Primary
 *      Term * Primary
 *      Term / Primary
 *      Term % Primary
 * Primary:
 *      Number
 *      ( Expression )
 *      -Primary
 *      +Primary
 * Number:
 *      floating-point-literal
 *
 * Input comes form cin through the Token_stream called ts.
 *
 * Additional functionality added as exercises by Patrick Rummage
 *      -support for the factorial operator !
 *      -support for bracketed expressions { }
 */

#include "../std_lib_facilities.h"

const char number = '8'; //t.kind==number means t is a number token
const char quit = 'q';   //t.kind==quit means t is a quit token
const char print = ';';  //t.kind==print means t is a print token
const string prompt = ">";
const string result = "="; //Indicates that what follows is a result
const char name = 'a';  //name Token
const char let = 'L';   //Declaration Token
const string declkey = "let";   //Declaration keyword
//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;      // for variables
    Token(char ch)    // make a Token from a char
        :kind{ch} {}    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind{ch}, value{val} {}
    Token(char ch, string n)       // make a Token from a char and var name
        :kind{ch}, name{n} {} 
};

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);     //discard characters up to and including a c
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

struct Variable {
    string name;
    double value;
    Variable(string n, double val) //Make a variable from (name,val)
        :name{n}, value{val} {}
};

vector<Variable> var_table; //Create vector to store variables

bool is_declared(string var)
    //is var already in var_table?
{
    for (const Variable& v : var_table) {
        if (v.name == var) 
            return true;
    }
    return false;
}

double define_name(string var, double val)
    //add (var,val) to table
{
    if(is_declared(var))
        error(var, "declared twice");
    var_table.push_back(Variable(var,val));
    return val;
}

double get_value(string s)
    // return the value of the variable named s
{
    for (const Variable& v : var_table) {
        if (v.name == s)
            return v.value;
    }
    error("get: undefined variable", s);
}

void set_value(string s, double d) 
    //set the Variable named s to d
{
    for (Variable& v : var_table) {
        if(v.name == s) {
            v.value = d;
            return;
        }
    }
    error("set: undefined variable", s);
}
//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}


// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

void Token_stream::ignore(char c)
    //c represents the kind of Token
{
    //first look in the buffer
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // now search input
    char ch;
    while (cin >> ch) {
        if (ch == c)
            return;
    }
}
/*Read chars from cin and compose a Token*/
Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case print:
    case quit:
    case '{': 
    case '}': 
    case '(': 
    case ')': 
    case '+':
    case '-': 
    case '*': 
    case '/': 
    case '%': 
    case '!':
    case '=':
        return Token(ch);        // let each character represent itself
    case '.':               //floating-point literals can start with '.'
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token(number,val);
        }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                s += ch;
            cin.putback(ch);
            if (s == declkey)   //Declaration keyword
                return Token(let);
            return Token(name, s);
        }
        error("Bad token ", ch); 
    }//End switch
}

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

// deal with numbers, parentheses, and brackets
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '{':           // handle '{' expression '}'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != '}') error("'}' expected");
            return d;
        }
    case '(':            // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case number:            // we use '8' to represent a number
        return t.value;  // return the number's value
    case name:
        return get_value(t.name);
    case '-':
        return -primary();
    case '+':
        return primary();
    default:
        error("primary expected");
    }
}

double factorial()
{
    double left = primary();
    Token t = ts.get();

    while(true) {
        switch(t.kind) {
        case '!':
        {  
            if (left == 0)
                left = 1; //By def. of factorial
            else {
                int n = (int)left;
                int ans = n;
                for(int i = 1; i < n; i++)
                    ans = ans * (n - i);
                left = ans;
                t = ts.get();
            }
            break;
        }
        default:
            ts.putback(t);
            return left; //no more '!'
        }//end switch
    }//end while
}

// deal with *, /, and %
double term()
{
    double left = factorial();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= factorial();
            t = ts.get();
            break;
        case '/':
        {    
            double d = factorial();
            if (d == 0) error("divide by zero");
            left /= d; 
            t = ts.get();
            break;
        }
        case '%':
        {
            int i1 = narrow_cast<int>(left);
            int i2 = narrow_cast<int>(primary());
            if (i2 == 0)
                error("%: Divide by zero");
            left = i1 % i2;
            t = ts.get();
            break;
        }
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

double declaration()
    //Handle name = expression
    //Declare a variable called "name" with initial value "expresion"
{
    Token t = ts.get();
    if (t.kind != name)
        error("name expected in declaration");
    string var_name = t.name;
    if (is_declared(var_name))
        error(var_name, " declared twice");
    Token t2 = ts.get();
    if (t2.kind != '=')
        error("= missing in declaration of ",var_name);

    double d = expression();
    var_table.push_back(Variable(var_name, d));
    return d;
}

double statement()
{
    Token t = ts.get();
    switch(t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}
//------------------------------------------------------------------------------
void clean_up_mess()
    //clear bad input from Token stream
{
    ts.ignore(print);
}

/*Expression evaluation loop*/
void calculate()
{   
    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();

            while (t.kind == print)
                t = ts.get();
            if (t.kind == quit)
                return;

            ts.putback(t);
            cout << result << statement() << "\n";
        }
        catch(runtime_error& e) {
            cerr << e.what() << '\n';   //Write error message
            clean_up_mess();
        }
    }//End while
}

int main()
{
    try
    {
        calculate();
        return 0; 
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n'; 
        char c;
        while (cin >> c && c != ';') ;
        return 1;
    }
    catch (...) {
        cerr << "unknown exception!\n"; 
        char c;
        while (cin >> c && c != ';') ;
        return 2;
    }
}