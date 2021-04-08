#include <iostream>
#include <vector>
#include <algorithm>


int knightDialer(int n) {
    std::vector<std::vector<int>> posibilities = {
		{4,6},    // -> 0 
		{6,8},    // -> 1
		{7,9},    // -> 2
		{4,8},    // -> 3
		{0,3,9},  // -> 4
		{},       // -> 5
		{0,1,7},  // -> 6
		{2,6},    // -> 7
		{1,3},    // -> 8
		{2,4}     // -> 9
	};
	std::vector<std::vector<int>> dp = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	for (int i = 1; i <= n; i++) {
		std::vector<int> currentPosibilities(10);
		for(int j = 0; j <= 9; j++) {
			for(int pos = 0; pos < posibilities[j].size(); pos++) {
				currentPosibilities[j] = (currentPosibilities[j] + dp[i-1][posibilities[j][pos]]) % 1000000007;
			}
		}
		dp.push_back(currentPosibilities);
	}     
	long ans = 0;
	for(int i = 0 ; i <= 9; i++) {
		ans = (ans + dp[n-1][i]) % 1000000007;	
	}
	return ans; 
}

int main() {
	return 0;
}