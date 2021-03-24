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
 * Binary Method
 * */

int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size();

    if(nums.size() == 1) {
        if (nums[0] == target) {
            return 0;
        } else {
            return -1;
        }
    }

    while (end - start > 1) {
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[start] == target ) {
            return start;
        }
        if (nums[mid] > nums[start]) {
            if (target <= nums[mid] && target >= nums[start]) {
              end = mid;
            } else {
               start = mid + 1;
            }
        } else {
            if (target >= nums[mid] && target <= nums[end - 1]) {
               start = mid + 1;
            } else {
                end = mid;
            }
        }
    }
    if (start < nums.size() && nums[start] == target) {
        return -1;
    } else {
        return -1;
    }
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8};
    int x = search(nums, 4);
    std::cout << x << std::endl;
    return 0;
}
