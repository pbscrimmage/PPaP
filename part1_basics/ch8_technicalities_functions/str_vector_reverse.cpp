/**
 * str_vector_reverse.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Write two functions that reverse the order of elements
 *      in a vector<string>. The first function should produce a 
 *      new vector, leaving the original vector unchanged. The
 *      second should reverse the original vector in place.
 */
#include "../std_lib_facilities.h"

vector<string> newReverse(const vector<string>& v)
{
    vector<string> reversed;
    for (int i = v.size()-1; i >= 0; --i) {
       reversed.push_back(v[i]);
    }
    return reversed;
}

void inPlaceReverse(vector<string>& v)
{
    int last = v.size()-1;
    for (int i = 0; i < (last)/2; ++i) {
        string temp = v[i];
        v[i] = v[last - i];
        v[last - i] = temp;
    } 
}

int main()
{
    vector<string> strs{"a","garbage","caviar","cdef","aliens"};

    //Print original vector
    cout << "Original vector: \n";
    for (string s : strs) {
        cout << s << " ";
    }
    cout << '\n';

    //Print new vector
    vector<string> reversed = newReverse(strs); 
    cout << "New vector: \n";
    for (string s : reversed) {
        cout << s << " ";
    }
    cout << '\n';

    //Print changed vector
    cout << "Changed vector: \n";
    inPlaceReverse(strs);
    for (string s : strs) {
        cout << s << " ";
    }
    cout << '\n';

    return 0;

}
