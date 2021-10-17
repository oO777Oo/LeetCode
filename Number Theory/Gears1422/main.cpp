#include <iostream>
#include <vector>

int noodOfTwoNumbers(int x, int y);
int ans(int x, int y);

using namespace std;

int main() {
	int x = 0;
	int y = 0;
	std::cin >> x >> y ;
	int bd = std::abs(noodOfTwoNumbers(x,y));
  std::cout<< ans(x,y);
	return 0;
}

int ans(int x, int y) {
  return x / noodOfTwoNumbers(x, y)  * y;
}

int noodOfTwoNumbers(int x, int y) {
	if(x == 0) {
		return y;
	} else {
		return noodOfTwoNumbers((y % x), x);
	}
}