g++ main_loop.cpp routines.h routines.cpp
i=1
while [ $i -lt 214 ]; do
	./a.out $i >> comparison.txt
	let i=i+1
done
