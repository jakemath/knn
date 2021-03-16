//
//  main.cpp
//  knn
//
//  Created by Jacob Mathai on 3/12/19.
//  Copyright © 2019 Jacob Mathai. All rights reserved.
//

#include "../header/knn.h"

int main(int argc, char* argv[]) {
    unsigned k_neighbors = atoi(argv[1]);
    std::ifstream in("../data/KNNdata.txt"), test("../data/KNNtest.txt"); // Read dataframe and testframe
    list<point> dataframe, testframe;
    cout << "Parsing datasets..." << endl;
    load_csv(in, dataframe);
    load_csv(test, testframe);
    cout << "DATA FRAME:" << endl << endl;
    for (const auto& datapoint : dataframe)
        cout << datapoint << endl;
    cout << endl << "TEST FRAME:" << endl << endl;
    for (const auto& datapoint : testframe)
        cout << datapoint << endl;
    cout << endl;
    int euclid_count = 0, manhattan_count = 0, prediction;
    cout << "ACTUAL \t EUCLIDEAN \t MANHATTAN" << endl;
    for (const auto& datapoint : testframe) {
        cout << "\t" << datapoint.attributes.back() << "\t";
        prediction = knn_classify(dataframe, datapoint, k_neighbors, sq_euclid_dist);
        cout << prediction << "\t";
        if (prediction == datapoint.attributes.back())
            ++euclid_count;
        prediction = knn_classify(dataframe, datapoint, k_neighbors, manhattan_dist);
        cout << prediction << endl;
        if (prediction == datapoint.attributes.back())
            ++manhattan_count;
    }
    cout << "Euclid correct: " << euclid_count << ", "
         << (1.0*euclid_count/testframe.size())*100 << "%" << endl
         << "Manhattan correct: " << manhattan_count << ", "
         << (1.0*manhattan_count/testframe.size())*100 << "%"
         << endl << endl;
}
