#include <iostream>
#include <vector>

long long noodOfTwoNumbers(long long x, long long y);

int main() {
	long long x = 0;
	long long y = 0;
	std::cin >> x >> y;
	long long ans = noodOfTwoNumbers(x,y);
	std::cout << ans;
	return 0;
}

long long noodOfTwoNumbers(long long x, long long y) {
	if (x == 0) {
		return y;
	} else {
		return noodOfTwoNumbers(y % x, x);
	}
}
