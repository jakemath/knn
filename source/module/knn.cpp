//
//  knn.cpp
//  knn
//
//  Created by Jacob Mathai on 3/12/19.
//  Copyright © 2019 Jacob Mathai. All rights reserved.
//

#include "../header/knn.h"


// Square Euclidean distance
double sq_euclid_dist(point x, point y) {
    double total = 0, diff;
    list<double>::iterator x_i = x.attributes.begin(), y_i = y.attributes.begin();
    for (; x_i != x.attributes.end() && y_i != y.attributes.end() ; ++x_i, ++y_i) {
        diff = *x_i - *y_i;
        total += diff*diff;
    }
    return total;
}


// Manhattan distance
double manhattan_dist(point x, point y) {
    double total = 0;
    list<double>::iterator x_i = x.attributes.begin(), y_i = y.attributes.begin();
    for (; x_i != x.attributes.end() && y_i != y.attributes.end() ; ++x_i, ++y_i)
        total += abs(*x_i - *y_i);
    return total;
}


// Classify point p based on closest k_neighbors in dataframe according to given distance function
int knn_classify(list<point>& dataframe, point p, int k_neighbors, double (*distance_fn)(point, point)) {
    set<point, point_compare> distances;
    for (auto& datapoint : dataframe) {
        datapoint.distance = distance_fn(p, datapoint);
        distances.insert(datapoint);
    }
    map<int, int> class_counts_map;
    map<int, int>::iterator class_type;
    int neighbors_counted = 0, max_class = -1, max_class_instances = 1;
    for (const auto& datapoint : distances) {
        class_type = class_counts_map.find(int(datapoint.attributes.back()));
        if (class_type != class_counts_map.end()) {
            ++(class_type->second);
            if (class_type->second > max_class_instances)  {
                max_class_instances = class_type->second;
                max_class = datapoint.attributes.back();
            }
        }
        else
            class_counts_map[int(datapoint.attributes.back())] = 1;
        ++neighbors_counted;
        if (neighbors_counted >= k_neighbors)
            break;
    }
    return max_class;
}


// Parse a row of comma separated values into a point instance
void split(const std::string& s, char c, point& p) {
    std::string str;
    std::istringstream tokenStream(s);
    while (getline(tokenStream, str, ','))
        p.attributes.push_back(stod(str));
}


// Load txt file of comma separated values into a dataframe
void load_csv(std::istream& in, list<point>& frame) {
    std::string str;
    while (!in.eof()) {
        point p;
        getline(in, str, '\n');
        if (!str.empty()) {
            split(str, ',', p);
            frame.push_back(p);
        }
    }
}


std::ostream& operator <<(std::ostream& out, const point& p) {
    for (const auto& attr : p.attributes)
        out << attr << " ";
    return out;
}
