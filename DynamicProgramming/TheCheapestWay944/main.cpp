#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<std::vector<int>> &matrix) {

	//init vertical
	int interSum = 0;
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i][0] += interSum;
		interSum = matrix[i][0];
	}

	// init horizontal
	interSum = 0;
	for (int i = 0; i < matrix[0].size(); i++) {
		matrix[0][i] += interSum;
		interSum = matrix[0][i];
	}

	for (int i = 1; i < matrix.size(); i++) {
		for(int j = 1; j < matrix[0].size(); j++) {
			matrix[i][j] = matrix[i][j] + std::min(matrix[i-1][j], matrix[i][j-1]);
		}
	}
	return matrix.back().back();

}

int main() {	
	int row = 0;
	int column = 0;
	std::cin >> row >> column;
	std::vector<std::vector<int>> matrix;
	for (int i = 0; i < row; i++) {
		std::vector<int> inter;
		for (int j = 0; j < column; j++) {
			int number;
			std::cin >> number;
			inter.push_back(number);
		}
		matrix.push_back(inter);
	}
	std::cout<< solution(matrix);
	return 0;
}