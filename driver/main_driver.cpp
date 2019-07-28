//
//  main.cpp
//  knn
//
//  Created by Jacob Mathai on 3/12/19.
//  Copyright © 2019 Jacob Mathai. All rights reserved.
//

#include "routines.h"

// argv[1] is neighbors for euclid dist, argv[2] is neighbors for manhattan
int main(int argc, char* argv[])
{
    std::ifstream in("KNNdata.txt"), test("KNNtest.txt"); // Read dataframe and testframe
    list<point> dataframe, testframe;
    load_csv(in, dataframe);
    load_csv(test, testframe);
    list<point>::iterator i = dataframe.begin();
    
    // Print frames
    cout << "DATA FRAME:" << endl << endl;
    for (; i != dataframe.end(); ++i)
        cout << *i << endl;
    
    cout << endl << "TEST FRAME:" << endl << endl;
    i = testframe.begin();
    for (; i != testframe.end(); ++i)
        cout << *i << endl;
   
    // Compute distances and report predictions
    int euclid_count = 0, manhattan_count = 0, temp;
    list<int> euclid_predictions, manhattan_predictions;
    list<point>::iterator i = testframe.begin();
    cout << "ACTUAL \t EUCLIDEAN \t MANHATTAN" << endl;
    for (; i != testframe.end(); ++i)
    {
        cout << "\t" << i -> attributes.back() << "\t";
        temp = knn_classify(dataframe, *i, atoi(argv[1]), sq_euclid_dist);
        cout << temp << "\t";
        if (temp == i -> attributes.back())
            ++euclid_count;
        temp = knn_classify(dataframe, *i, atoi(argv[1]), manhattan_dist);
        cout << temp << endl;
        if (temp == i -> attributes.back())
            ++manhattan_count;
    }
    
    // Report accuracy
    cout << endl << "Euclid accuracy: ";
    cout << (1.0 * euclid_count / euclid_predictions.size()) * 100;
    cout << "%" << endl << "Manhattan accuracy: ";
    cout << (1.0 * manhattan_count / euclid_predictions.size()) * 100 << "%";
    cout << endl << endl;
}
