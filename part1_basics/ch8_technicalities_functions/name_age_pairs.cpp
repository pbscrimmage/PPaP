/**
 * name_age_pairs.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Read names into a vector<string> names. Then prompt the
 *      user for the ages of the people named and store the ages
 *      in a vector<double> ages. Sort the names and then print
 *      out the name-age pairs, preserving the relationship 
 *      between the names and their ages.
 */
#include "../std_lib_facilities.h"

void getNames(vector<string>& names)
{
    string name;
    cin >> name;
    while (name != "0") {
        names.push_back(name);
        cin >> name;
    }
}

void getAges(vector<double>& ages, vector<string>& names)
{
    int age;
    for (int i = 0; i < names.size(); ++i) {
        cout << names[i] << ": ";
        cin >> age;
        ages.push_back(age);
    }
}

vector<double> sortAges(const vector<string>& names, 
        const vector<string>& namesCpy, const vector<double>& ages)
{
    vector<double> sorted;
    for (string s : names) {
        for (int i = 0; i <= namesCpy.size()-1; ++i) {
            if (s == namesCpy[i]) {
                sorted.push_back(ages[i]);
            }
        }
    }
    return sorted;
}

int main()
{
    vector<string> names;
    vector<double> ages;

    cout << "Enter a series of names. Enter a 0 to end input: \n";
    getNames(names);

    cout << "Enter ages for the names you entered: \n";
    getAges(ages, names);

    //Print the pairs as entered
    cout << '\n';
    for (int i = 0; i <= names.size()-1; ++i) {
        cout << names[i] << ": " << ages[i] << '\n';
    }
    cout << '\n';

    //Make a copy of names before sorting
    vector<string> namesCopy;
    for (string s : names) {
        namesCopy.push_back(s);
    }

    sort(names.begin(),names.end());

    vector<double> sortedAges = sortAges(names, namesCopy, ages);
    for (int i = 0; i <= names.size()-1; ++i) {
        cout << names[i] << ": " << sortedAges[i] << '\n';
    }
    cout << '\n';

    return 0;
}
