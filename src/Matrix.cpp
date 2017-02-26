#include "matrix.hpp"

Matrix::Matrix(){
	rows = 0;
	cols = 0;
}

void Matrix::read_from_file(std::string path) 
{
	std::fstream file(path, std::ios_base::in);

	if(file.is_open()) {
		file >> rows >> cols;

		data.clear();
		data.resize(rows * cols);

		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
		  		file >> data[(i * cols) + j];
		  	}
	  	}
	}
	// print_matrix();
	file.close();
}

void Matrix::sort_method1() 
{
	quicksort(&data, 0, data.size() - 1);
	output_to_file("cc0032_1.txt");
}

void Matrix::sort_method2() 
{
	// Quicksort rows
	for(int i = 0; i < rows; i++) {
		quicksort(&data, (i * cols), (i * cols) + (cols - 1));
	}

	// Quicksort cols
	for(int i = 0; i < cols; i++) {
		matrix_data temp(rows);
		for(int j = 0; j < rows; j++) {
			temp[j] = data[(j * cols) + i];
		}
		quicksort(&temp, 0, temp.size());
		for(int j = 0; j < rows; j++) {
			data[(j * cols) + i] = temp[j];
		}
	}
	output_to_file("cc0032_2.txt");
}

void Matrix::quicksort(matrix_data* d, int left, int right)
{
	if(left < right) {
		int pivot = quicksort_partition(d, left, right);
		quicksort(d, left, pivot - 1);
		quicksort(d, pivot + 1, right);
	}
}

int Matrix::quicksort_partition(matrix_data* d, int left, int right)
{
	int i  = left + 1;
	int j = right;
	first = &Matrix::quicksort_partition_icomp;
	second = &Matrix::quicksort_partition_icomp;

	while(i <= j) {
		if(comp.leq((*d)[i], (*d)[left])){
			i++;
		}
		else if(comp.geq((*d)[j], (*d)[left])) {
			j--;
		}
		else {
			int temp = (*d)[i];
			(*d)[i] = (*d)[j];
			(*d)[j] = temp;
			i++;
			j--;
		}
	}

	int temp = (*d)[left];
	(*d)[left] = (*d)[j];
	(*d)[j] = temp;

	return j;
}

bool Matrix::quicksort_partition_icomp(int lhs, int rhs)
{
	bool ret = comp.leq(lhs, rhs);
	if(ret){
		i_iter++;
		first = &Matrix::quicksort_partition_icomp;
	}
	return ret;
}

bool Matrix::quicksort_partition_jcomp(int lhs, int rhs)
{
	bool ret = comp.geq(lhs, rhs);
	if(ret){
		j_iter++;
		first = &Matrix::quicksort_partition_jcomp;
	}
	return ret;
}

void Matrix::output_to_file(std::string path) 
{
	std::ofstream file(path);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			file << data[(i * cols) + j] << " ";
		}
		file << "\n";
	}

	file << "compare_count: " << Comparator<int>::getCount() << "\n";

	file.close();
}

void Matrix::print_matrix() 
{
	for(int i : data) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}