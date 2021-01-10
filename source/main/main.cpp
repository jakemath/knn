//
//  main.cpp
//  knn
//
//  Created by Jacob Mathai on 3/12/19.
//  Copyright © 2019 Jacob Mathai. All rights reserved.
//

#include "../header/knn.h"

int main(int argc, char* argv[]) {
    std::ifstream in("../data/KNNdata.txt"), test("../data/KNNtest.txt"); // Read dataframe and testframe
    list<point> dataframe, testframe;
    cout << "Parsing datasets..." << endl;
    load_csv(in, dataframe);
    load_csv(test, testframe);
    list<point>::iterator i;
    cout << "DATA FRAME:" << endl << endl;
    for (i = dataframe.begin(); i != dataframe.end(); ++i)
        cout << *i << endl;
    cout << endl << "TEST FRAME:" << endl << endl;
    for (i = testframe.begin(); i != testframe.end(); ++i)
        cout << *i << endl;
    cout << endl;
    int euclid_count = 0, manhattan_count = 0, prediction;
    cout << "ACTUAL \t EUCLIDEAN \t MANHATTAN" << endl;
    for (i = testframe.begin(); i != testframe.end(); ++i) {
        cout << "\t" << i->attributes.back() << "\t";
        prediction = knn_classify(dataframe, *i, atoi(argv[1]), sq_euclid_dist);
        cout << prediction << "\t";
        if (prediction == i->attributes.back())
            ++euclid_count;
        prediction = knn_classify(dataframe, *i, atoi(argv[1]), manhattan_dist);
        cout << prediction << endl;
        if (prediction == i->attributes.back())
            ++manhattan_count;
    }
    // Report accuracy
    cout << "Euclid correct: " << euclid_count << ", "
         << (1.0*euclid_count/testframe.size())*100 << "%" << endl
         << "Manhattan correct: " << manhattan_count << ", "
         << (1.0*manhattan_count/testframe.size())*100 << "%"
         << endl << endl;
}
