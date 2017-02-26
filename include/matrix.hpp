#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "includes.hpp"
#include "comparator.hpp"

using matrix_data = std::vector<int>;

class Matrix 
{
private:
	Comparator<int> comp;
	matrix_data data;

public:
	Matrix(); 
	void read_from_file(std::string path);
	void method1();
	void method2();
	void outputToFile(matrix_data d, std::string path);
	void print_matrix();
};