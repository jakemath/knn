#include "routines.h"

int main(int argc, char* argv[])
{
    std::ifstream in("KNNdata.txt"), test("KNNtest.txt"); // Read dataframe and testframe
    list<point> dataframe, testframe;
    load_csv(in, dataframe);
    load_csv(test, testframe);
    
    // Compute distances
    int euclid_count = 0, manhattan_count = 0, temp;
    list<int> euclid_predictions, manhattan_predictions;
    list<point>::iterator i = testframe.begin();
    for (; i != testframe.end(); ++i)
    {
        temp = knn_classify(dataframe, *i, atoi(argv[1]), sq_euclid_dist);
        if (temp == i -> attributes.back())
            ++euclid_count;
        temp = knn_classify(dataframe, *i, atoi(argv[1]), manhattan_dist);
        if (temp == i -> attributes.back())
            ++manhattan_count;
    }
    
    cout << argv[1] << " ";
    cout << (1.0 * euclid_count / testframe.size()) * 100 << " ";
    cout << (1.0 * manhattan_count / testframe.size()) * 100 << endl;
}
