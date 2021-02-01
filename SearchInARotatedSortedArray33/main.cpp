#include <iostream>
#include <vector>

using namespace std;




/**
 * First Method
 * */
int search1 (vector<int>& nums, int target) {
    for(int i = 0 ; i < nums.size(); i ++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}


/**
 * Second Method
 * */

int search(vector<int>& nums, int target) {
    int length = nums.size();
    int start = 0, end = length - 1;

    while (start <= end) {
        int mid = (end + start) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[start] <= nums[mid]) {
            if (target >= nums[start] && target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            if (target > nums[mid] && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main() {

    vector<int> nums = {4,5,6,7,0,1,2};
    int x = search(nums, 0);
    std::cout << x << std::endl;
    return 0;
}
