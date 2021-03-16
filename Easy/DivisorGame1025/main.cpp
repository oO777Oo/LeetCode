#include <iostream>
#include <vector>

using namespace std;

bool divisorGame(int N) {
	int counter = 0;
	for (int i = 0; i < N; i++) {
		if(N % i == 0) {
			counter ++;
			if(N-i <= 1) {
				break;
			} else {
				N = N - i;
				cout << N << " ";
			}
		}
	}      
	return !(counter % 2 == 0);
}


int main() {
	divisorGame(6);
	return 0;
}