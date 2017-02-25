#include <iostream>

#include "includes.hpp"
#include "comparator.hpp"

int main(int argc, char ** argv) 
{
	Comparator<int> comp;
	debug(true, "2 < 4: %d", comp.leq(2, 4));
	debug(true, "compare_count: %d", comp.getCount());
}