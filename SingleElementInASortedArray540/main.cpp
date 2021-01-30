#include <iostream>
#include <vector>

using namespace std;


int singleNonDuplicate(vector<int>& nums) {
    for (int i = 0 ; i < nums.size();) {
        if (nums[i] == nums[i + 1]) {
           i = i + 2;
        } else {
            return nums[i];
        }
    }
}

int main() {
    // [1,1,2,3,3,4,4,8,8]
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    int x = singleNonDuplicate(nums);
    std::cout << x << std::endl;

    return 0;
}
