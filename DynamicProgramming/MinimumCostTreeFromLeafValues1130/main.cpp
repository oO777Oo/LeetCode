#include <iostream>
#include <vector>


int mctFromLeafValues(std::vector<int>& arr) {
	int res = 0;
    std::vector<int> stack = {INT_MAX}; // init max possible number. not to pop!
    for (int a : arr) { 
    	/* pop till back is bigger as a */
        while (stack.back() <= a) {
            int mid = stack.back();
            stack.pop_back();
            res += mid * std::min(stack.back(), a); // check if min value is last one or current number.
        }
        stack.push_back(a); // push current number
    }

    for (int i = 2; i < stack.size(); ++i) {
        // in this block stack is in decrease order and we add only current * with [current-1]
        res += stack[i] * stack[i - 1];
    }
    return res;
}

int main() {

	return 0;
}