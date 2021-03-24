#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
 	std::vector<int> stack = {cost[0],cost[1]};
 	int arrLength = cost.size();
 	for (int i = 2; i < cost.size(); i++) {
 		stack.push_back(min(stack[i-1], stack[i-2]) + cost[i]);
 	}
 	return min(stack[arrLength - 1], stack[arrLength - 2]);
}

int main() {
	std::vector<int> v = {1,100,1,1,1,100,1,1,100,1};
	cout << minCostClimbingStairs(v);
	return 0;
}