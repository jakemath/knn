//
//  routines.cpp
//  knn
//
//  Created by Jacob Mathai on 3/12/19.
//  Copyright © 2019 Jacob Mathai. All rights reserved.
//

#include "knn.h"

double sq_euclid_dist(point x, point y)    // Square Euclidean distance
{
    double total = 0;
    list<double>::iterator i = x.attributes.begin(), j = y.attributes.begin();
    for (; i != x.attributes.end() && j != y.attributes.end() ; ++i, ++j)
        total += pow(*i - *j, 2);
    return total;
}

double manhattan_dist(point x, point y)    // Manhattan distance
{
    double total = 0;
    list<double>::iterator i = x.attributes.begin(), j = y.attributes.begin();
    for (; i != x.attributes.end() && j != y.attributes.end() ; ++i, ++j)
        total += abs(*i - *j);
    return total;
}

// Classify point c based on k nearest neighbors in dataframe with given distance function
int knn_classify(list<point>& dataframe, point c, int k, double (*dist)(point,point))
{
    set<point,point_compare> distances; // Store points in dataframe, ordered by proximity to c
    list<point>::iterator i = dataframe.begin();
    for (; i != dataframe.end(); ++i)   // Iterate through all points in dataframe
    {
        i -> distance = dist(c, *i); // Compute distance to c
        distances.insert(*i); // Insert into set based on distance
    }
    map<int,int> counts; // Map classification to number of instances in the k-nearest neighbors to c
    int l = 1, max_instances = 1, max_type = -1, *temp;
    set<point>::iterator j = distances.begin(); // Iterate through the first k elements of the set
    for (; l <= k && j != distances.end(); ++l, ++j)
    {
        if (counts.find(int(j -> attributes.back())) != counts.end()) // Increment instances
        {
            temp = &counts[int(j -> attributes.back())];
            ++*temp;
            if (*temp > max_instances)  // Update max
            {
                max_instances = *temp;
                max_type = j -> attributes.back();
            }
        }
        else    // Create first instance
            counts[int(j -> attributes.back())] = 1;
    }
    return max_type;    // Return most common value
}

// Parse a single line of comma separated values into a point instance
void split(const std::string& s, char c, point& p)
{
    std::string str;
    std::istringstream tokenStream(s);
    while (getline(tokenStream, str, ','))
        p.attributes.push_back(stod(str));
}

// Load txt file of comma separated values into a dataframe
void load_csv(std::istream& in, list<point>& frame)
{
    std::string str;
    while (!in.eof())
    {
        point p;
        getline(in, str, '\n');
        split(str, ',', p);
        frame.push_back(p);
    }
}

std::ostream& operator <<(std::ostream& out, const point& p)
{
    list<double>::const_iterator i = p.attributes.begin();
    for (; i != p.attributes.end(); ++i)
        out << *i << " ";
    return out;
}
