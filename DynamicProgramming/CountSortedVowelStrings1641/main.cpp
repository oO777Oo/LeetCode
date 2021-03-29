#include <iostream>
#include <vector>

int countVowelStrings(int n);

/* Interesting DP Problem! 
 * we have chars :
 * u o i e a
 * when n = 1 they are looking like thise:
 * 1 1 1 1 1
 * Patterns looks like:
 * n = 1 -> 1 1 1 1 1
 * n = 2 -> 1 2 3 4 5
 * n = 3 -> 1 3 6 10 15
 * n = 4 -> 1 4 10 20 35
 * n = 5 -> 1 5 15 35 70 
 * ...
 * last number of that index + precedent number 
 * 1- 4-  10- 20- 35
      |   |   |   |
 * 1- 5- 15- 35- 70
      |   |   |   |
 * 1- 6- 21- 56- 126 ...
*/

int main(int argc, char const *argv[])
{
	return 0;
}


int countVowelStrings(int n) {
    std::vector<int> v = {1,1,1,1,1};
    int sum = 0;

    while(n > 1) {
	v[4] += v[3] += v[2] += v[1] += v[0];
	n--;
    }
    for(int i = 0; i < v.size(); i++) {
	sum += v[i];
    }
    return sum;
}
