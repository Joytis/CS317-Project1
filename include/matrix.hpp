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
	int rows;
	int cols;
	matrix_data data;

	void quicksort(int left, int right);
	int quicksort_partition(int left, int right);
public:
	Matrix(); 
	void read_from_file(std::string path);
	void sort_method1();
	void sort_method2();
	void output_to_file(std::string path);
	void print_matrix();
};