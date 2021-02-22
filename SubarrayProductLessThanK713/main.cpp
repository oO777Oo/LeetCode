#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k);

int main() {
    vector<int> nums = {10, 9, 10, 4, 3, 8, 3, 3, 6, 2, 10, 10, 9, 3};
    int k = 19;

    cout << numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}

int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    if (k <= 1) {
        return 0;
    }
    int pointer1 = 0, pointer2 = 0, ans = 0, product = 1;

    while (pointer2 < nums.size()) {
        product *= nums[pointer2];
        while (product >= k) {
            product /= nums[pointer1++];
        }
        ans += pointer2 - pointer1 + 1;
        pointer2++;
    }
    return ans;
}

