//
//  knn.h
//
//  Created by Jacob Mathai on 3/12/19.
//  Copyright © 2019 Jacob Mathai. All rights reserved.
//

#ifndef knn_h
#define knn_h

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>

using std::map;
using std::set;
using std::list;
using std::cout;
using std::endl;

// Struct to represent a single data point in dataframe
// and distance to point of interest
struct point {
    point() {}
    point(list<double>& data) : attributes(data) {} // Attribute values stored in list
    list<double> attributes; // Attribute values stored in list. attributes.back() is the classification
    double distance;    // Distance from point in KNN call
};

// Comparison operator for ordering points in dataframe
// according to distance to point of interest
struct point_compare {
    bool operator() (const point& x, const point& y) const {
        if (x.distance != y.distance)
            return x.distance < y.distance;
        return x.attributes.front() < y.attributes.front();
    }
};

double sq_euclid_dist(point x, point y);
double manhattan_dist(point x, point y);
int knn_classify(list<point>& dataframe, point c, int k, double (*dist)(point,point));
void split(const std::string& s, char c, point& p);
void load_csv(std::istream& in, list<point>& frame);
std::ostream& operator <<(std::ostream& out, const point& p);

#endif /* knn_h */
