#include <iostream>
#include <vector>

int noodOfTwoNumbers(int x, int y);

int main() {
	int x = 0;
	int y = 0;
	std::cin >> x >> y;
	int ans = noodOfTwoNumbers(x,y);
	return 0;
}

int noodOfTwoNumbers(int x, int y) {
	if(x == 0) {
		return y;
	} else {
		return noodOfTwoNumbers(y % x, x);
	}
}
