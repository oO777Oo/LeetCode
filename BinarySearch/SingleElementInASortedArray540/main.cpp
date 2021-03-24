#include <iostream>
#include <vector>

using namespace std;


int singleNonDuplicate1(vector<int>& nums) {
    for (int i = 0 ; i < nums.size();) {
        if (nums[i] == nums[i + 1]) {
           i = i + 2;
        } else {
            return nums[i];
        }
    }
}

/**
 * Using binary search
 * */
int singleNonDuplicate(vector<int>& nums) {
    int start = 0;
    int end = nums.size();
    if (nums.size() == 1) {
        return nums[0];
    }
    while (end - start > 1) {
        int mid = (end + start) / 2;
        if (nums[mid] == nums[mid + 1]) {
            mid++;
        } else if (nums[mid] != nums[mid - 1]) {
            return nums[mid];
        }
        if ((end - 1 - mid) % 2 == 0) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return nums[start];
}

int main() {
    // [1,1,2,3,3,4,4,8,8]
    // [0,1,2,3,4,5,6,7,8]
    vector<int> nums = {3,3,7,7,10,11,11};
    int x = singleNonDuplicate(nums);
    std::cout << x << std::endl;

    return 0;
}
