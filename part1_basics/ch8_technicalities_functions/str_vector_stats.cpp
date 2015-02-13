/**
 * str_vector_stats.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Create a function that takes a vector<string> argument
 *      and returns a vector<int> containing the number of 
 *      characters in each string. Also find the longest and
 *      the shortest string and the lexicographically first 
 *      and last string.
 */
#include "../std_lib_facilities.h"

string findShortest(const vector<string>& v)
{
    string shortest = v[0];
    for (string s: v) {
        if (s.size() < shortest.size()) {
            shortest = s;
        }
    }
    return shortest;
}

string findLongest(const vector<string>& v)
{
    string longest = "";
    for (string s : v) {
        if (s.size() > longest.size()) {
            longest = s;
        }
    }
    return longest;
}

string findFirst(const vector<string>& v)
{
    string first = v[0];
    for (string s : v) {
        int i = 0;
        while (s[i] == first[i]) {
            ++i;
        }
        if (s[i] < first[i]) {
            first = s;
        }
    }
    return first;
}

string findLast(const vector<string>& v)
{
    string last = v[0];
    for (string s : v) {
        int i = 0;
        while (s[i] == last[i]) {
            ++i;
        }
        if (s[i] > last[i]) {
            last = s;
        }
    }
    return last;
}

vector<int> getLengths(const vector<string>& v)
{
    vector<int> strLengths;

    for (string s : v) {
        strLengths.push_back(s.size());
    }
    return strLengths; 
}

int main ()
{
    vector<string> strList{"abcd","abbathing","efghi","else","constable","zxvtu"};

    cout << "Strings: " << '\n';    //Print strings
    for (string str : strList) {
        cout << str << " ";
    }
    cout << '\n';

    vector<int> lengths = getLengths(strList);  //Print string lengths
    cout << "String Lengths: \n";
    for (int i = 0; i < lengths.size(); ++i) {
        cout << lengths[i] << " ";
    }
    cout << '\n';
    
    //Print other info
    cout << "Shortest string: " << findShortest(strList) << '\n';
    cout << "Longest string: " << findLongest(strList) << '\n';
    cout << "First string: " << findFirst(strList) << '\n';
    cout << "Last string: " << findLast(strList) << '\n';
  
    return 0;
}
