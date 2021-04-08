#include <iostream>
#include <vector>
#include <algorithm>

void printSolution(int m) {
	if(m==0) {
		return;
	}
	if(m == 1) {
		std::cout<< 1;
	} else {
		std::cout<<1<<"\n";
		std::cout<<1<<" "<<1<<"\n";
	}
	int count = 3;
	std::vector<long> line = {1,1};
	std::vector<std::vector<long>> stack = {line};
	while(count <= m) {
		std::vector<long> last = stack.back();
		std::vector<long> v = {1};
		stack.pop_back();
		
		std::cout<<1<<" ";
		for(int j = 1; j < count-1; j++) {
			std::cout<<last[j] + last[j-1]<<" ";
			v.push_back(last[j] + last[j-1]);
		}
		std::cout<<1<<"\n";
		v.push_back(1);
		count ++;
		stack.push_back(v);
	}
}

int main() {
	int m = 0;
	std::cin>>m;
	printSolution(m);
	return 0;
}