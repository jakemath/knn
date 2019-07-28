# KNN-Implementation
A C++ implementation of the KNN algorithm. The function signature mimics the KNN_Classify function in Python SKLearn.

The program parses a dataset and a test set. Given an input for k neighbors, the program classifies each test point with two distance metrics: Square Euclidean Distance and Manhattan Distance. 

The comparison folder contains a slightly modified main program and a brief analysis of the performance of each metric for a given k in a Jupyter notebook.

To run the driver program, place KNNdata.txt, KNNtest.txt, main_driver.cpp, routines.h and routines.cpp in the same directory. Then type
    
    >>> g++ main_driver.cpp routines.h routines.cpp
    >>> ./a.out <euclid_neighbors> <manhattan_neighbors>
  
where euclid_neighbors and manhattan_neighbors are commandline arguments to be passed to the respective distance functions.
