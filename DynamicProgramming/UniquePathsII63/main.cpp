#include <iostream>
#include <vector>
#include <algorithm>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    int vertical = obstacleGrid.size();
    int horizontal = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1) {
        return 0;
    }

    // change vertical values
    int precedent = 1;
    for (int i = 0; i < vertical; i++) {
        if (obstacleGrid[i][0] == 1) {
            precedent = 0;
        }
        obstacleGrid[i][0] = precedent;
    }

    // change horizontal value
    precedent = 1;
    for (int i = 1; i < horizontal; i++) {
        if (obstacleGrid[0][i] == 1) {
            precedent = 0;
        }
        obstacleGrid[0][i] = precedent;
    }

    for (int i = 1; i < vertical; i++) {
        for (int j = 1; j < horizontal; j++) {
            if (obstacleGrid[i][j] == 1) {
                obstacleGrid[i][j] = 0;    
            } else {
                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
    }
    return obstacleGrid[vertical-1][horizontal-1];
}

int main() {
	return 0;
}