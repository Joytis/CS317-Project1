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

	cprint("2 < 4: %d", comp.leq(2, 4));
	cprint("compare_count: %d", Comparator<int>::getCount());
}