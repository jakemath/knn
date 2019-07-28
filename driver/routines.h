//
//  routines.h
//  knn
//
//  Created by Jacob Mathai on 3/12/19.
//  Copyright © 2019 Jacob Mathai. All rights reserved.
//

#ifndef routines_h
#define routines_h

#include <iostream>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <iterator>
#include <fstream>
#include <sstream>

using std::list;
using std::map;
using std::set;
using std::cout;
using std::endl;

// Struct to represent a single data point in dataframe
// and distance to point of interest
struct point
{
    point() {}
    point(list<double>& data) : attributes(data) {} // Attribute values stored in list
    list<double> attributes; // Attribute values stored in list. attributes.back() is the classification
    double distance;    // Distance from point in KNN call
};

// Comparison operator for ordering points in dataframe
// according to distance to point of interest
struct point_compare
{
    bool operator() (const point& x, const point& y) const
    {
        if (x.distance != y.distance)
            return x.distance < y.distance;
        return x.attributes.front() < y.attributes.front();
    }
};

double sq_euclid_dist (point x, point y);   // Square euclidean distance
double manhattan_dist (point x, point y);   // Manhattan distance

int knn_classify (list<point>& dataframe, point c, int k, double (*dist)(point,point));   // KNN function

void split (const std::string& s, char c, point& p); // Txt file parsing functions
void load_csv (std::istream& in, list<point>& frame);

std::ostream& operator << (std::ostream& out, const point& p);  // Print point

#endif /* routines_h */
