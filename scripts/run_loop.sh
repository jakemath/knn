#!/bin/bash
cd ../source
g++ main/main_loop.cpp header/knn.h module/knn.cpp
i=1
while [[ $i -lt 214 ]]; do
	./a.out $i >> ../comparison/comparison.txt
	let i=i+1
done
