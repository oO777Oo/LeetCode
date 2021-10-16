#include <iostream>
#include <utility>
#include <vector>

std::pair<int,int> solve(int x, int y , int z, int w);
int noodOfTwoNumbers(int x, int y);

int main() {
	int firstTop = 0;
	int firstBot = 0;
	int secondTop = 0;
	int secondBot = 0;
	std::cin >> firstTop >> firstBot >> secondTop >> secondBot;
	std::pair<int,int> ans = solve(firstTop, firstBot, secondTop, secondBot);
	std::cout<< ans.first << "/" << ans.second;
	return 0;
}


std::pair<int,int> solve(int x, int y , int z, int w) {
	std::pair<int,int> ans;
	int numberBot = y * w;
	int numberTop = x * w + z * y;
	int bd = noodOfTwoNumbers(numberTop, numberBot);
	ans.first = numberTop / bd;
	ans.second = numberBot / bd;
	return ans;
}	


int noodOfTwoNumbers(int x, int y) {  
	if(x == 0) {
		return y;
	} else {
		return noodOfTwoNumbers(y % x, x);
	}
}
