/**
 * name_val_class.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Create a class that stores a name and a score and a vector
 *      of Name_value objects. Allow the user to input a series of
 *      name-score pairs terminated by 'NoName 0.' Check that each 
 *      entered name is unique and terminate with an error if a name 
 *      is entered twice. Then print out all the name-score pairs,
 *      one per line.
 *      Program then prompts the user to search the vector based on
 *      either a name or a score.
 */

#include "../std_lib_facilities.h"

class Name_value {
    public:
        Name_value(string newName, int newValue)
            :name(newName), score(newValue) { }
        string get_name()
            { return name; }
        int get_score()
            { return score; }
    private:
        string name;
        int score;
};

void create_records(vector<Name_value>& records);
void print_records(const vector<Name_value>& records);
void search_records(const vector<Name_value>& records);
void print_score(string query, const vector<Name_value>& records);
void print_names(int query, const vector<Name_value>& records);

int main()
{   try
    {
        vector<Name_value> records;
        
        create_records(records);

        print_records(records);

        search_records(records);
    }
    catch (exception& e) {
        cerr << "ERROR: "<< e.what() << '\n';
        return 1;
    }
    catch (...) {
        cerr << "ERROR: Unknown exception!\n";
        return 2;
    }
    return 0;
}

void create_records(vector<Name_value>& records)
    //Prompts user for name-score pairs to insert into the records
    //vector
{
    string name;
    int score = 0;
    cout << "Enter names followed by values, separated by spaces. To"
       << " terminate input, enter 'NoName 0': \n";
    cin >> name >> score;
    while (name != "NoName" && score != 0) {
        for (Name_value record : records) {
            if (name == record.get_name()) {
                error("duplicate entry: ", name);
            }
        }
        Name_value newRecord{name,score};
        records.push_back(newRecord);
        cin >> name >> score;
    }
    return;
}

void print_records(const vector<Name_value>& records)
    //Prints out each name-score pair in the vector on its own line
{
    if (records.size() == 0){
        error("Empty vector");
    }
    cout << '\n';
    for (Name_value record : records) {
        cout << record.get_name() << " " << record.get_score() << '\n';
    }
    return;
}

void search_records(const vector<Name_value>& records)
    //Prompts the user to search the records by name or by
    //score and prints out the results, or a 'not found' 
    //message. A bad query produces an error
{
    if (records.size() == 0 ) {
        error("Empty vector");
    }
    string query;
    char type;
    cout << "Enter a score followed by 's' to retrieve names or a name"
       <<" followed by 'n' to retrieve a score:\n";
    cin >> query >> type;
    switch(type) {
        case 'n': case 'N':
            print_score(query, records);
            break;
        case 's': case 'S':
            print_names(stoi(query), records);
            break;
        default:
            error("Unrecognized query");
    }
    return;
}

void print_score(string query, const vector<Name_value>& records)
    //Searches records for a name matching query and prints the score
    //or 'Name not found' if there is no such name stored
{
    for (Name_value record : records) {
        if (record.get_name() == query) {
            cout << record.get_score() << '\n';
            return;
        }
    }
    cout << "Name not found.\n";
    return;
}

void print_names(int query, const vector<Name_value>& records)
    //Searches records for a score matching query and prints all names
    //with that score, or 'Score not found' if there is no such score
{
    bool found = false;
    for (Name_value record : records) {
        if (record.get_score() == query) {
            found = true;
            cout << record.get_name() << '\n';
        }
    }
    if (!found) {
        cout << "Score not found.\n";
    }
    return;   
}
