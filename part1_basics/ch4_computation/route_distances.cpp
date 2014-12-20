/* Reads a series of values, representing distances between cities along a route,
 * into a vector. Prints the smallest, greatest, and the mean of distances.*/
#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter the distances for the route. Terminate input with any"
       << " non-numeric value. (EX: '|')\n";

    vector<double>distances;
    for (double distance; cin>>distance; )
        distances.push_back(distance);

    sort(distances);

    /*Find smallest and largest values*/
    cout << "The smallest distance is: " << distances[0] << "\n";
    int length = distances.size();
    cout << "The largest distance is: " << distances[length-1] << "\n";

    /*Find mean distance*/
    double sum;
    for (double x : distances)
        sum += x;
    double mean = sum / length;
    cout << "The mean of the distances is: " << mean << "\n";

    return 0;
}
