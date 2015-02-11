#include "../std_lib_facilities.h"

struct Stats {
    int smallest = 0;
    int largest = 0;
    double median = 0;
    double mean = 0;
};

Stats getStats(const vector<int>& v)
{
    Stats vStats;
    vStats.smallest = v[0];
    vStats.largest = v[0];
    double sum = 0;
    for (int x : v) {
        sum += x;
        if (x < vStats.smallest) {
            vStats.smallest = x;
        } 
        if (x > vStats.largest) {
           vStats.largest = x;
        } 
    }
    vStats.mean = sum / v.size();

    int middle = v[v.size()/2];
    if (v.size() % 2 == 0) {
        vStats.median = (v[middle-1] + v[middle]) / 2.0;
    }
    else {
        vStats.median = middle;
    }
    return vStats;
} 

int main()
{
    vector<int> v{5,6,4,9,3};

    Stats vStats = getStats(v);

    cout << "Smallest: " << vStats.smallest << '\n'
        << "Largest: " << vStats.largest << '\n'
        << "Median: " << vStats.median << '\n'
        << "Mean: " << vStats.mean << '\n';

    return 0;
}
