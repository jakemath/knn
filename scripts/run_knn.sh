#!/bin/bash
NEIGHBORS=$1
cd ../source
g++ -std=c++2a main/main.cpp header/knn.h module/knn.cpp
./a.out $NEIGHBORS
rm a.out header/*.gch
