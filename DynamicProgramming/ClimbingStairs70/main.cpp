#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if (n <= 3) {
    	return n;
    }
    std::vector<int> v = {1,2,3};
    for (int i = 4; i <= n; i++) {
    	int number = v.back();
    	v.pop_back();
    	int sencond = v.back();
    	v.push_back(number);
    	v.push_back(number + sencond);
    } 
    return v.back();

}

int main() {

	return 0;
}