#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int totalSum = INT_MIN, currentSum = 0;
    
    for (int i = 0; i <nums.size(); i++) {
        currentSum = max(currentSum + nums[i], nums[i]);
        totalSum = max(currentSum, totalSum);
    }
    return totalSum;
}

int main() {
	return 0;
}