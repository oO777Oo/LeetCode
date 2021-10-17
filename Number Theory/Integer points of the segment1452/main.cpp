#include <iostream>
#include <vector>

int noodOfTwoNumbers(int x, int y);
int ans(int x, int y, int z, int w);

using namespace std;

int main() {
	int x = 0;
	int y = 0;
  int z = 0;
  int w = 0;
	std::cin >> x >> y >> z >> w;
	int bd = std::abs(noodOfTwoNumbers(x,y));
  std::cout<< ans(x,y,z,w);
	return 0;
}

int ans(int x, int y, int z, int w) {
  pair<int,int> data;
  data.first = abs(z-x);
  data.second = abs(w-y);
  return noodOfTwoNumbers(data.first, data.second) + 1;
}

int noodOfTwoNumbers(int x, int y) {
	if(x == 0) {
		return y;
	} else {
		return noodOfTwoNumbers((y % x), x);
	}
}