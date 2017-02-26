#include "matrix.hpp"

Matrix::Matrix(){}

void Matrix::read_from_file(std::string path) 
{
	int rows, cols;
	std::fstream file(path, std::ios_base::in);
	std::cout << path << std::endl;

	if(file.is_open()) {
		std::cout << "FILE OPEN: \n";
		file >> rows >> cols;

		data.clear();
		data.resize(rows * cols);

		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
		  		file >> data[(i * cols) + j];
		  	}
	  	}
	}

	print_matrix();

	file.close();
}

void Matrix::method1() 
{

}
void Matrix::method2() 
{

}
void Matrix::outputToFile(matrix_data d, std::string path) 
{

}

void Matrix::print_matrix() 
{
	for(int i : data) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}