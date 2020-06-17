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
    list<point>::iterator i;
    // Print frames
    cout << "DATA FRAME:" << endl << endl;
    for (i = dataframe.begin(); i != dataframe.end(); ++i)
        cout << *i << endl;
    cout << endl << "TEST FRAME:" << endl << endl;
    for (i = testframe.begin(); i != testframe.end(); ++i)
        cout << *i << endl;
    // Compute distances and report predictions
    int euclid_count = 0, manhattan_count = 0, euclid_predict, manhattan_predict;
    list<int> euclid_predictions, manhattan_predictions;
    cout << "ACTUAL \t EUCLIDEAN \t MANHATTAN" << endl;
    for (i = testframe.begin(); i != testframe.end(); ++i)
    {
        cout << "\t" << i -> attributes.back() << "\t";
        euclid_predict = knn_classify(dataframe, *i, atoi(argv[1]), sq_euclid_dist);
        cout << euclid_predict << "\t";
        if (euclid_predict == i -> attributes.back())
            ++euclid_count;
        manhattan_predict = knn_classify(dataframe, *i, atoi(argv[1]), manhattan_dist);
        cout << manhattan_predict << endl;
        if (manhattan_predict == i -> attributes.back())
            ++manhattan_count;
    }
    // Report accuracy
    cout << "Euclid correct: " << euclid_count << ", ";
    cout << (1.0 * euclid_count / testframe.size()) * 100 << "%" << endl;
    cout << "Manhattan correct: " << manhattan_count << ", ";
    cout << (1.0 * manhattan_count / testframe.size()) * 100 << "%";
    cout << endl << endl;
}
