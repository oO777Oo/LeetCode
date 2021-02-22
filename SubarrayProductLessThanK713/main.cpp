#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k);

/*TODO check for test case
 * [10,2,2,5,4,4,4,3,7,7]
 * 289
 * Need some changes
 * */


int main() {

    /**
     * [10,9,10,4,3,8,3,3,6,2,10,10,9,3]
        19
     *
     * */
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}

int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int pointer1 = 0;
    int pointer2 = 0;
    int product = 1;
    int ans = 0;

    while (pointer1 < nums.size()) {
        if (pointer2 != nums.size() && product * nums[pointer2] < k) {
            product *= nums[pointer2];
            pointer2++;
            ans++;
            if (nums.size() == pointer2 && pointer1 + 1 == pointer2) {
                break;
            }
        } else if (product < k && (pointer2 - pointer1 > 1 || pointer2 == nums.size())) {
            product /= nums[pointer1];
            pointer1++;
            ans++;
        } else {
            product /= nums[pointer1];
            pointer1++;
        }
    }
    return ans;
}

