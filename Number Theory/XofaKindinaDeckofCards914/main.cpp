#include <iostream>
#include <vector>

using namespace std;


int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

bool hasGroupsSizeX(vector<int>& deck) {
    int arr[10000] = {};
    // Init array
    for (int i = 0; i < size(deck); i++) {
    	arr[deck[i]] ++; 
    }

    int ans = -1;

    for (int i = 0; i < 10000; i++) {
    	if (arr[i] > 0) {
    		if (ans == -1) {
    			ans = arr[i]; // first case.
    		} else {
    			ans = gcd(ans, arr[i]); // Return biggest Common divisor
    		}
    	}
    }
    return ans >= 2;
}

int gcd(int x, int y) {
	/* if ( x == 0 ) {
	       return y;
	   else {
	       return gcd(y % x, x);
	   }	
	*/
	return x == 0 ? y : gcd(y % x , x);
}