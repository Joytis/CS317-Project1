#include <iostream>

#include "includes.hpp"
#include "comparator.hpp"
#include "matrix.hpp"

int main(int argc, char ** argv) 
{	
	if(argc != 2) {
		return 0;
	}

	Comparator<int> comp;
	std::string path(argv[1]);
	Matrix matrix;

	matrix.read_from_file(path);
	matrix.sort_method1();
	Comparator<int>::resetCount();

	matrix.read_from_file(path);
	matrix.sort_method2();
	Comparator<int>::resetCount();

	return 0;
}