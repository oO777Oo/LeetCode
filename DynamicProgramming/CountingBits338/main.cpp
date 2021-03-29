#include <iostream>
#include <vector>

/** The biggest problem was to find this pattern.
	pattern for dp problem is:
	0 -> 0
	1 -> ans from index 1 / 2 + 1 % 2 =>>>>> 0 + 1 = 1;
	2 -> ans from index 2 / 2 + 2 % 2 =>>>>> 1 + 0 = 1;
	3 -> ans[3 / 2] + 3 % 2           =>>>>> 1 + 1 = 2;
	4 -> ans[4 / 2] + 4 % 2           =>>>>> 1 + 0 = 1; 
	... 

*/

vector<int> countBits(int num) {
    std::vector<int> v;
    v.push_back(0);
    for (int i=1;i<=num;i++){
        v.push_back(v[i / 2] + (i % 2));
    }
    return v;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}