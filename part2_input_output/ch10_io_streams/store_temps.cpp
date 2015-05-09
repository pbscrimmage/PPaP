/**
 * store_temps.cpp
 *
 * Author: Patrick Rummage
 *          [patrickbrummage@gmail.com]
 *
 * Objective:
 *      Create a program that prompts the user to enter temperature
 *      data and then stores the data in a file called raw_temps.txt.
 */
#include "../std_lib_facilities.h"

struct Reading {
    int hour;
    double temperature;
};

ostream& operator<<(ostream& os, const Reading& r)
{
    return os << '(' << r.hour 
              << ',' << r.temperature 
              << ')';
}

void write_temps(const vector<Reading>& readings, const string& filename)
{
    ofstream ost {filename};
    if (!ost)
        error("Can't open file for writing: ", filename);

    for (Reading r : readings)
        ost << r << "\n";
}

int main()
{
    vector<Reading> readings;
    
    int hour;
    double temp;
    cout << "Enter temperature readings. [CTRL-D] to end input: \n";
    while (cin >> hour >> temp) {
        readings.push_back(Reading{hour,temp});
    }

    write_temps(readings, "raw_temps.txt");

    return 0;
}
