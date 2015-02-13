/**
 * int_vector_reverse.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Write two functions that reverse the order of elements
 *      in a vector<int>. The first function should produce a 
 *      new vector, leaving the original vector unchanged. The
 *      second should reverse the original vector in place.
 */
#include "../std_lib_facilities.h"

vector<int> newReverse(const vector<int>& v)
{
    vector<int> reversed;
    for (int i = v.size()-1; i >= 0; --i) {
       reversed.push_back(v[i]);
    }
    return reversed;
}

void inPlaceReverse(vector<int>& v)
{
    int last = v.size()-1;
    for (int i = 0; i < (last)/2; ++i) {
        int temp = v[i];
        v[i] = v[last - i];
        v[last - i] = temp;
    }
}

int main()
{
    vector<int> nums{5,7,4,0,99,3};

    //Print original vector
    cout << "Original vector: \n";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << '\n';

    //Print new vector
    vector<int> reversed = newReverse(nums); 
    cout << "New vector: \n";
    for (int x : reversed) {
        cout << x << " ";
    }
    cout << '\n';

    //Print changed vector
    cout << "Changed vector: \n";
    inPlaceReverse(nums);
    for (int x : nums) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}
