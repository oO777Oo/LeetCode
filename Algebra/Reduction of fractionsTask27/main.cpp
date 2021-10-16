#include <iostream>
#include <vector>

int noodOfTwoNumbers(int x, int y);

int main() {
	int x = 0;
	int y = 0;
	std::cin >> x >> y;
	int bd = noodOfTwoNumbers(x,y);
	std::cout<< x / bd << "/" << y / bd;
	return 0;
}

int noodOfTwoNumbers(int x, int y) {
	if(x == 0) {
		return y;
	} else {
		return noodOfTwoNumbers(y % x, x);
	}
}
