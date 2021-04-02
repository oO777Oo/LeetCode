#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string longestPath(std::vector<std::vector<int>>& matrix);

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
	std::string ans = longestPath(matrix); 
	std::cout<<matrix[matrix.size()-1][matrix[0].size()-1]<<"\n"<<ans; // ans DDRRRRDD
	return 0;
}

std::string longestPath(std::vector<std::vector<int>>& matrix) {
	/*Example matrix will be this one 
		9 9 9 9 9
		3 0 0 0 0
		9 9 9 9 9
		6 6 6 6 8
		9 9 9 9 9
	*/
	std::vector<int> ans; // 1 is for down 0 is for right
	int lastNumberX = 0;
	int lastNumberY = 0;	
	// init sum prefix first row from matrix.
	for (int j = 0; j < matrix[0].size(); j++) {
		int inter = matrix[0][j];
		matrix[0][j] += lastNumberX;
		lastNumberX += inter;
	}
	// init sum prefix first collumn from matrix
	for (int j = 0; j < matrix.size(); j++) {
		int inter = matrix[j][0];
		matrix[j][0] += lastNumberY;
		lastNumberY += inter;
	}
	/* Now matrix looks like:
		a,  a+b,...   9 18 27 36 45
		a+z,          12 0  0  0  0
		...           21 9  9  9  9
			      27 6  6  6  6
		sum prefix    36 9  9  9  9
		Because the turtle can go right or down we have initialized the x and y axis not to produce index out of bounds
	*/
	for (int i = 1; i < matrix.size(); i++) {
		for (int j = 1; j < matrix[i].size(); j++) {
			int currentValue = matrix[i][j];
			int leftSum = matrix[i][j-1];
			int topSum = matrix[i-1][j];
			matrix[i][j] = std::max(leftSum + currentValue, topSum + currentValue); 
		}	
	}
	// init axys x and y
	int x = matrix.size() - 1;
	int y = matrix[x].size() - 1;
	while(x > 0 && y > 0) {
		/* X is for right and Y is for down.
		  We find the most expensive way until X or Y is 0. 
		  Then we just add what is left of the other element (x or y) until 0.
		*/
		if(matrix[x-1][y] > matrix[x][y-1]) {
			ans.push_back(1);
			x --;
		} else {
			ans.push_back(0);
			y--;
		}
	}
	// Check what is left of till 0.
	while(x > 0) {
		ans.push_back(1);
		x--;
	}
	while(y > 0) {
		ans.push_back(0);
		y--;
	}
	// Construct answer.
	std::string answer;
	for (int i = ans.size() - 1; i >= 0; i--) {
		if(ans[i] == 1) {
			answer += "D";
		} else {
			answer += "R";
		}
	}
	return answer;
}
