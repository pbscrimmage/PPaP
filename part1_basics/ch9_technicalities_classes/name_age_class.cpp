/**
 * name_age_class.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Implement a Name_pairs class holding pairs where
 *      name is a string and age is a double. Represent
 *      that as a vector<string> called names, and a
 *      vector<double> called ages. Provide class methods
 *      read_names() and read_ages() to get user input
 *      for the name-age pairs. Provide a print() method
 *      as well as a sort() method that sorts the names,
 *      in alphabetical order and reorganizes the age 
 *      vector to match.
 */
#include "../std_lib_facilities.h"

class Name_pairs {
    public:
        void read_names();
        void read_ages();
        void print();
        void sort();
    private:
        vector<string> names;
        vector<double> ages;
};

void Name_pairs::read_names()
{
    cout << "Enter a series of names. Enter a 0 to end input: \n";
    string name;
    cin >> name;
    while (name != "0") {
        names.push_back(name);
        cin >> name;
    }
}

void Name_pairs::read_ages()
{
    cout << "Enter ages for the names you entered: \n";
    int age;
    for (int i = 0; i < names.size(); ++i) {
        cout << names[i] << ": ";
        cin >> age;
        ages.push_back(age);
    }
}

void Name_pairs::print()
{
    cout << '\n';
    for (int i = 0; i <= names.size()-1; ++i) {
        cout << names[i] << ": " << ages[i] << '\n';
    }
    cout << '\n';
}

void Name_pairs::sort()
{
    //Make a copy of names before sorting
    vector<string> namesCpy;
    for (string s : names) {
        namesCpy.push_back(s);
    }
    
    std::sort(names.begin(),names.end());

    //Create sorted age vector to match names
    vector<double> sorted;
    for (string s : names) {
        for (int i = 0; i <= namesCpy.size()-1; ++i) {
            if (s == namesCpy[i]) {
                sorted.push_back(ages[i]);
            }
        }
    }

    //Replace ages with sorted
    for (int i = 0; i < ages.size(); ++i) {
        ages[i] = sorted[i];
    }
}

int main()
{
    Name_pairs pairs;

    pairs.read_names();
    pairs.read_ages();

    pairs.print();

    pairs.sort();
    pairs.print();

    return 0;
}
