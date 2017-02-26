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
	int i_iter;
	int j_iter;
	matrix_data data;
	bool (Matrix::*first)(int lhs, int rhs);
	bool (Matrix::*second)(int lhs, int rhs);

	void quicksort(matrix_data* d, int left, int right);
	int quicksort_partition(matrix_data* d, int left, int right);
	bool quicksort_partition_icomp(int lhs, int rhs);
	bool quicksort_partition_jcomp(int lhs, int rhs);
public:
	Matrix(); 
	void read_from_file(std::string path);
	void sort_method1();
	void sort_method2();
	void output_to_file(std::string path);
	void print_matrix();
};