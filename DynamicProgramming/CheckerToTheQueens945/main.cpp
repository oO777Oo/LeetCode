#include <iostream>
#include <vector>
#include <algorithm>

int solution1(int a, int b) {
	// First solution is to construct direct
	std::vector<std::vector<int>> matrix = {
		{35, 69, 89, 103, 103, 89, 69, 35},
		{20, 35, 49, 54, 54, 49, 35, 20},
		{10, 20, 25, 29, 29, 25, 20, 10},
		{6, 10, 14, 15, 15, 14, 10, 6},
		{3, 6, 7, 8, 8, 7, 6, 3},
		{2, 3, 4, 4, 4, 4, 3, 2},
		{1, 2, 2, 2, 2, 2, 2, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};
	return matrix[b-1][a-1];
}

// Second solution using dp!
int solution(int a, int b) {
	std::vector<int> finish = {0,1,1,1,1,1,1,1,1,0};
	std::vector<std::vector<int>> stack = {finish};
	int count = 2;
	while(count <= 9 - b) {
		std::vector<int> current = stack.back();
		std::vector<int> nextLine(10);
		for (int i = 1; i < current.size() - 1; i++) {
			nextLine[i] = current[i-1] + current[i+1];
		}
		stack.pop_back();
		stack.push_back(nextLine); 
		count ++;
	}
	return stack.back()[a];
}

int main() {
	int a,b;
	std::cin>>a>>b;
	std::cout<<solution(a,b);
	return 0;
}