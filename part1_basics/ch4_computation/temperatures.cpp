/* Reads temperature data into a vector and computes the median and
 * the average*/
#include "../std_lib_facilities.h"

int main()
{
    /*Create temperature vecture*/
    vector<double>temps;
    cout << "Enter temperatures. Enter a non-numeric value"
        << " (i.e. '|') to end input.\n";
    for (double temp; cin>>temp; )
        temps.push_back(temp);

    /*Compute average temperature*/
    double sum = 0;
    for (int x : temps) sum += x;
    cout << "Average temperature: " << sum / temps.size() << "\n";

    /*Compute median temperature*/
    sort(temps);
    double median = 0;
    int middle = temps.size() / 2;
    if (temps.size() % 2 == 0) //Even-sized vectors
        median = (temps[middle] + temps[middle -1]) / 2;
    else
        median = temps[middle];
    
    cout << "Median temperature: " << median << "\n";

    return 0;
}
