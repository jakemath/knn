# KNN-Implementation
A C++ implementation of the KNN algorithm. The function signature mimics the KNN_Classify function in Python SKLearn.

The program parses a dataset and a test set. Given an input for k neighbors, the program classifies each test point with two distance metrics: Square Euclidean Distance and Manhattan Distance. In comparison.ipynb, a brief analysis of the performance of each metric for a given k is made.

To run the driver program, place KNNdata.txt, KNNtest.txt, build_driver.sh, main_driver.cpp, routines.h and routines.cpp in the same directory. Then type
    
    >>> chmod +x build_driver.sh
    >>> ./build_driver.sh
    >>> ./a.out <euclid_neighbors> <manhattan_neighbors>
  
where euclid_neighbors and manhattan_neighbors are commandline arguments to be passed to the respective distance functions.
