/**
 * word_grep.cpp
 *
 * Author: Patrick Rummage
 *          [patrickbrummage@gmail.com]
 *
 * Objective:
 *      Write a program that given a file name and a word outputs each line that
 *      contains that word together with the line number.
 */
#include "../std_lib_facilities.h"

void search_file(const string& filename, string s, vector<string>& matches) {
    ifstream ifs {filename};
    if (!ifs) {
        error("Can't open ", filename);
    }

    string line;
    int ln_count = 0;
    while (getline(ifs, line)) {
        string word;
        stringstream ss {line};
        while (ss >> word) {
            if (word == s) {
                matches.putback(to_string(ln_count) + ": " + line); 
            }
        }
    }
}

void print_lines(const vector<string>& lines) {
    if (lines.size() == 0) {
        cout << "No results" << "\n";
    } else {
        for (string l : lines) {
            cout << l << "\n";
        }
}

int main(int argc, char* argv[]) {
    string fname = argv[0];
    string query = argv[1];    

    vector<string> results;

    search_file(fname, query, results);

    print_lines(results);

    return 0;
}
