#include <iostream>
#include <vector>
#include <algorithm>

/*Is not the most optimal solution becouse we construct length*length matrix but we don't need this*/
int stoneGameII(std::vector<int>& piles) {
	int length = piles.size();
    std::vector<std::vector<int>>dp(length + 1, std::vector<int>(length + 1,0));
    std::vector<int> sufsum (length + 1, 0);
    for (int i = length - 1; i >= 0; i--) {
        sufsum[i] = sufsum[i + 1] + piles[i];
    }
    for (int i = 0; i <= length; i++) {
        dp[i][length] = sufsum[i];
    }
    for (int i = length - 1; i >= 0; i--) {
        for (int j = length - 1; j >= 1; j--) {
            for (int X = 1; X <= 2 * j && i + X <= length; X++) {
                dp[i][j] = std::max(dp[i][j], sufsum[i] - dp[i + X][std::max(j, X)]);
            }
        }
    }
    return dp[0][1];
}


int main() {
 	return 0;
} 