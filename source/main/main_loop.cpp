#include "routines.h"

int main(int argc, char* argv[])
{
    std::ifstream in("../data/KNNdata.txt"), test("../data/KNNtest.txt"); // Read dataframe and testframe
    list<point> dataframe, testframe;
    load_csv(in, dataframe);
    load_csv(test, testframe);
    int euclid_count = 0, manhattan_count = 0, temp;
    list<int> euclid_predictions, manhattan_predictions;
    for (list<point>::iterator i = testframe.begin(); i != testframe.end(); ++i) {
        prediction = knn_classify(dataframe, *i, atoi(argv[1]), sq_euclid_dist);
        if (prediction == i->attributes.back())
            ++euclid_count;
        prediction = knn_classify(dataframe, *i, atoi(argv[1]), manhattan_dist);
        if (prediction == i->attributes.back())
            ++manhattan_count;
    }
    cout << argv[1] << " " << (1.0 * euclid_count / testframe.size()) * 100 << " "
         << (1.0 * manhattan_count / testframe.size()) * 100 << endl;
}
