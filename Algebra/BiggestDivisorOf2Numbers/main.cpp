#include <iostream>
#include <vector>

__int128 noodOfTwoNumbers(__int128 x, __int128 y);

int main() {
	__int128 x = 0;
	__int128 y = 0;
	std::cin >> x >> y;
	__int128 ans = noodOfTwoNumbers(x,y);
	std::cout << ans;
	return 0;
}

__int128 noodOfTwoNumbers(__int128 x, __int128 y) {
	if (x == 0) {
		return y;
	} else {
		return noodOfTwoNumbers(y % x, x);
	}
}
