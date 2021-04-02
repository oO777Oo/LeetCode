#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int maxSumAfterPartitioning(std::vector<int>& arr, int k);

int main() {

	return 0;
}

int maxSumAfterPartitioning(std::vector<int>& arr, int K) {
    int length = arr.size();
    std::vector<int> dp(length + 1);
    for (int i = 1; i <= length; ++i) {
        int current = 0, best = 0;
        for (int k = 1; k <= K && i - k >= 0; ++k) {
            current = std::max(current, arr[i - k]);
            best = std::max(best, dp[i - k] + current * k);
        }
        dp[i] = best;
    }
    return dp[length];
    
}