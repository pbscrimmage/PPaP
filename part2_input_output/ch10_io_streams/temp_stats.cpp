/**
 * temp_stats.cpp
 *
 * Author: Patrick Rummage
 *          [patrickbrummage@gmail.com]
 *
 * Objective:
 *      Create a program that reads temperature data from a file
 *      called raw_temps.txt and computes the mean and median 
 *      temperatures.
 */
#include "../std_lib_facilities.h"

struct Reading {
    int hour;
    double temperature;
};

istream& operator>>(istream& ist, Reading& r)
{
    char ch1, ch2, ch3; // Eat (,)
    ist >> ch1 >> r.hour >> ch2 >> r.temperature >> ch3;

    return ist;
}

bool compare(Reading r1, Reading r2)
{
    return r1.temperature < r2.temperature;
}

void read_temps(vector<Reading>& readings, const string& filename)
{
    ifstream ist {filename};
    if (!ist)
        error("Can't open file for reading: ", filename);

    Reading r;
    while (ist >> r) {
        readings.push_back(r);
    }
}

double find_mean(const vector<Reading>& readings)
{
    double sum = 0;
    for (Reading r : readings) {
        sum += r.temperature;
    }

    return sum / readings.size();
}

double find_median(const vector<Reading>& readings)
{
    vector<Reading> sorted;     // Make copy for sorting
    for (Reading r : readings) {
        sorted.push_back(r);
    }

    sort(sorted.begin(), sorted.end(), compare);

    int length = sorted.size();
    int half = length / 2;

    if (length % 2 == 0) {
        return (sorted[half].temperature + sorted[half-1].temperature) / 2;
    } else {
        return sorted[half].temperature;
    }
}

int main()
{
    vector<Reading> data;

    string filename = "raw_temps.txt";

    read_temps(data, filename);

    double mean = find_mean(data);
    double median = find_median(data);

    cout << "Mean: " << mean << '\n';
    cout << "Median: " << median << '\n';

    return 0;
}
