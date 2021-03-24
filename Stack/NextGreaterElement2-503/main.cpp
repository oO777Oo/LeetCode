#include <iostream>
#include <vector>

using namespace std;

vector<int> nextGreaterElements(vector<int> &nums);

int main() {
    return 0;
}

vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> ans = nums;
    vector<int> stack = {};
    int length = nums.size();
    for (int i = length * 2 - 1; i >= 0; i--) {
        while (!empty(stack) && stack.back() <= nums[i % length]) {
            stack.pop_back();
        }
        if (empty(stack)) {
            ans[i % length] = -1;
        } else {
            ans[i % length] = stack.back();
        }
        stack.push_back(nums[i % length]);
    }
    return ans;
}


