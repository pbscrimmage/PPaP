/**
 * name_val_class.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Create a class that stores a name and a value and a vector
 *      of Name_value objects. Allow the user to input a series of
 *      name-value pairs terminated by 'NoName 0.' Check that each 
 *      entered name is unique and terminate with an error if a name 
 *      is entered twice. Then print out all the name-value pairs,
 *      one per line.
 */

#include "../std_lib_facilities.h"

class Name_value {
    public:
        Name_value(string newName, int newValue)
            :name(newName), value(newValue) { }
        string getname()
            { return name; }
        int getvalue()
            { return value; }
    private:
        string name;
        int value;
};

int main()
{
    vector<Name_value> records;

    string name;
    int value = 0;
    cout << "Enter names followed by values, separated by spaces. To"
       << " terminate input, enter 'NoName 0': \n";
    cin >> name >> value;
    while (name != "NoName" && value != 0) {
        for (Name_value record : records) {
            if (name == record.getname()) {
                error("duplicate entry: ", name);
            }
        }
        Name_value newRecord{name,value};
        records.push_back(newRecord);
        cin >> name >> value;
    }
    if (records.size() > 0) {
        cout << '\n';
        for (Name_value record : records) {
            cout << record.getname() << " " << record.getvalue() << '\n';
        }
    }
    return 0;
}
