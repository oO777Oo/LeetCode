#include <iostream>
#include <vector>
#include <algorithm>

int solution(int r, int c);

int main() {
	int row = 0;
	int column = 0;
	std::cin>> row >> column;
	std::cout<< solution(row, column);
	return 0;
}

int solution(int r, int c) {
	long arr[r][c];

	// init vertical
	for (int i = 0; i < r; i++) {
		arr[i][0] = 1;
	}
	
	// init horizontal
	for (int i = 0; i < c; i++) {
		arr[0][i] = 1;
	}

	// Construct matrix (dp[i][j] = dp[i-1][j] + dp[i][j-1])
	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			arr[i][j] = arr[i-1][j] + arr[i][j-1];
		}
	}
	return arr[r-1][c-1];	
}