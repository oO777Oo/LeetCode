#include <iostream>

using namespace std;

bool isSubsequence(string s, string t) {
	int number = s.length();
	int position = 0;
	for (int i = 0; i < t.length(); i++) {
		if(t[i] == s[position]) {
			number --;
			position ++;
		}
		if(number == 0) {
			return true;
		}
	}        
	return number == 0;
}


int main() {
	
	return 0;
}