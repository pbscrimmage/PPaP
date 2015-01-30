/**
 * expr_calculator.cpp
 *
 * A simple calculator
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
 *      -allow underscores in variable names
 *      -create Symbol_table class to store variables
 *      -support for sqrt() function
 *      -support for pow() function
 */

#include "../std_lib_facilities.h"

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;      // for variables
    Token(char ch)    // make a Token from a char
        :kind(ch) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n)       // make a Token from a char and var name
        :kind(ch), name(n) { } 
};

class Token_stream {
public: 
    Token_stream()    // make a Token_stream that reads from cin
        :full(false), buffer(0) { } //initialize with empty buffer
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);     //discard characters up to and including a c
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

const char quit = 'q';   //t.kind==quit means t is a quit token
const char print = ';';  //t.kind==print means t is a print token
const char number = '8'; //t.kind==number means t is a number token
const char name = 'a';  //name Token
const char let = 'L';   //Declaration Token
const char root = 'S';  //Sqrt Token
const char exponent = 'E';
const string declkey = "let";   //Declaration keyword
const string sqrtkey = "sqrt";  //Sqrt() keyword
const string expkey = "pow";    //pow() keyword

Token Token_stream::get()
    //Read chars from cin and compose a Token
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
    case ',':
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
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
                s += ch;
            cin.putback(ch);
            if (s == declkey) {  //Declaration keyword
                return Token(let);
            } else if (s == sqrtkey) { //Sqrt() keyword
                return Token(root);
            } else if (s == expkey) {  //pow() keyword
                return Token(exponent);
            }
            return Token(name, s);
        }
        error("Bad token ", ch); 
    }//End switch
}

void Token_stream::putback(Token t)
    // The putback() member function puts its argument back into the Token_stream's buffer:
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

struct Variable {
    string name;
    double value;
    Variable(string n, double val) //Make a variable from (name,val)
        :name{n}, value{val} {}
};

class Symbol_table {
    public:
        double declare(string var, double val);
        bool is_declared(string var);
        double get(string s);
        void set(string s, double d);
    private:
        vector<Variable> var_table; //Create vector to store variables
};

bool Symbol_table::is_declared(string var)
    //is var already in var_table?
{
    for (const Variable& v : var_table) {
        if (v.name == var) 
            return true;
    }
    return false;
}

double Symbol_table::declare(string var, double val)
    //add (var,val) to table
{
    if(is_declared(var))
        error(var, "declared twice");
    var_table.push_back(Variable(var,val));
    return val;
}

double Symbol_table::get(string s)
    // return the value of the variable named s
{
    for (const Variable& v : var_table) {
        if (v.name == s)
            return v.value;
    }
    error("get: undefined variable", s);
}

void Symbol_table::set(string s, double d) 
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

Token_stream ts;        // provides get() and putback() 
Symbol_table symtable;  // provides get() set() and declare()

double expression();    // declaration so that primary() can call expression()

double primary()
    // deal with numbers, square roots, exponents, parentheses, and brackets
{
    Token t = ts.get();
    switch (t.kind) {
    case root:
        {
            t = ts.get();
            if (t.kind != '(') 
                error("'(' expected");
            double d = expression();
            if (d < 0) 
                error ("negative argument for sqrt()");
            t = ts.get();
            if (t.kind != ')') 
                error ("')' expected");
            return sqrt(d);
        }
    case exponent:
        {
            t = ts.get();
            if (t.kind != '(')
                error("'(' expected");
            double d = expression();
            t = ts.get();
            if (t.kind != ',')
                error("expected two arguments for pow()");
            int exp = narrow_cast<int>(expression());
            t = ts.get();
            if (t.kind != ')')
                error("')'expected");
            if (exp == 0)   //Exponent is zero
                return 1;
            double result = d;
            if (exp > 0) {  //Positive exponent
                cout << "if\n";
                for (int i = 1; i <= exp; ++i) {
                    result *= d;
                }
            } else if (exp < 0) {  //Negative exponent
                for (int i = exp; i <= -1; ++i) {
                    result /= d;
                }
            }
            return result;
        }
    case '{':           // handle '{' expression '}'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != '}') 
                error("'}' expected");
            return d;
        }
    case '(':            // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') 
                error("')' expected");
            return d;
        }
    case number:            // we use '8' to represent a number
        return t.value;  // return the number's value
    case name:
        return symtable.get(t.name);
    case '-':
        return -primary();
    case '+':
        return primary();
    default:
        error("primary expected");
    }
}

double factorial()
    //find and calculate factorials
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

double term()
    // deal with *, /, and %
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
            if (d == 0) 
                error("divide by zero");
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

double expression()
    // deal with + and -
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
    //Handle 'name = expression'
    //Declare a variable called "name" with initial value "expresion"
{
    Token t = ts.get();
    if (t.kind != name)
        error("name expected in declaration");
    string var_name = t.name;
    Token t2 = ts.get();
    if (t2.kind != '=')
        error("= missing in declaration of ",var_name);

    double d = expression();
    symtable.declare(var_name, d);
    return d;
}

double statement()
    //Handle 'let' keyword
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

void clean_up_mess()
    //clear bad input from Token stream
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= "; //Indicates that what follows is a result

void calculate()
    /*Expression evaluation loop*/
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
            cerr << "ERROR: " << e.what() << '\n'; //Write error message
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
