#include <iostream>
#include <vector>


int minFallingPathSum(std::vector<std::vector<int>>& matrix);

int main(int argc, char const *argv[]) {
	return 0;
}

int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
    int maxRow = matrix.size();
    int maxSize = matrix[0].size();
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 0; j < maxSize; j++) {
            int centerPosition = matrix[i - 1][j];
            int leftPosition = matrix[i - 1][j];
            int rightPosition = matrix[i - 1][j];

            if (j != 0) {
                leftPosition = matrix[i - 1][j - 1];
            }
            if (j + 1 < maxSize) {
                rightPosition = matrix[i - 1][j + 1];
            }
            int current = matrix[i][j];
            matrix[i][j] = std::min(std::min(current + centerPosition, current + rightPosition),
                               std::min(current + leftPosition, current + centerPosition));
        }
    }
    int minPath = INT_MAX;
    for (int i = maxRow - 1, j = 0; j < matrix[i].size(); j++) {
        minPath = std::min(minPath, matrix[i][j]);
    }
    return minPath;

}