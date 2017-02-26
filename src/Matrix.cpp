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
	quicksort(0, data.size() - 1);
	output_to_file("cc0032_1.txt");
}

void Matrix::sort_method2() 
{

}

void Matrix::quicksort(int left, int right)
{
	if(left < right) {
		int pivot = quicksort_partition(left, right);
		quicksort(left, pivot - 1);
		quicksort(pivot + 1, right);
	}
}

int Matrix::quicksort_partition(int left, int right)
{
	int i = left + 1;
	int j = right;

	while(i <= j) {
		if(comp.leq(data[i], data[left])){
			i++;
		}
		else if(comp.geq(data[j], data[left])) {
			j--;
		}
		else {
			int temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			i++;
			j--;
		}
	}

	int temp = data[left];
	data[left] = data[j];
	data[j] = temp;

	return j;
}

void Matrix::output_to_file(std::string path) 
{
	std::ofstream file(path);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
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