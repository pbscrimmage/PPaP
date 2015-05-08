/**
 * coordinate_vector.cpp
 *
 * Author: Patrick Rummage
 *          [patrickbrummage@gmail.com]
 *
 * Objective:
 *      Create a program that reads and writes coordinate points
 *      from/to files. Point objects are stored in vectors inside
 *      the program.
 */
#include "../std_lib_facilities.h"

struct Point {
   int x;
   int y;
};

void write_points(const vector<Point>& points, const string& filename)
{
    ofstream ost {filename};
    if (!ost)
        error("can't open output file ", filename);

    for (Point p : points)
        ost << '(' << p.x << ',' << p.y << ")\n";
}

void read_points(vector<Point>& points, const string& filename)
{    
    ifstream ist {filename};
    if (!ist)
        error("can't open input file ", filename);    

    int x,y;
    char ch1, ch2, ch3;
    while (ist >> ch1 >> x >> ch2 >> y >> ch3)
        points.push_back(Point{x,y});
}

int main()
{
    vector<Point> original_points;

    cout << "Enter pairs of coordinates. [CTRL-D] ends input: " << endl;
    int x, y;
    while (cin >> x >> y)
        original_points.push_back(Point{x,y});

    string filename = "mydata.txt";
    write_points(original_points, filename);

    vector<Point> file_points;
    read_points(file_points, filename);
   
    cout << "From memory: \n";
    for (Point p : file_points) {
        cout << '(' << p.x << ',' << p.y << ")\n";
    }

    cout << "From file: \n";
    for (Point p : file_points) {
        cout << '(' << p.x << ',' << p.y << ")\n";
    }

    return 0;
}
