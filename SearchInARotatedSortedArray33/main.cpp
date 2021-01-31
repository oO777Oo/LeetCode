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
    int start, end, middle;
    int length = nums.size();

    if (length % 2 == 0) {
        middle = length / 2;
    } else {
        middle = length / 2 + 1;
    }

    if (nums[middle] < target) {
        return -1;
    } else if (nums[length - 1] < target) {
        start = 0;
        end = middle;
        middle = (end + start) / 2;
    } else {
        start = middle;
        end = length - 1;
        middle = (end + start) / 2;
    }

    while (true) {
        if (target > nums[middle - 1] && target < nums[middle + 1]) {
            return -1;
        }
        if (nums[middle] == target) {
            return middle;
        }
        if (target > nums[middle]) {
           start = middle;
           middle = (start + end) / 2;
        } else {
            end = middle;
            middle = (start + end) / 2;
        }
    }
}

int main() {
    // [4,5,6,0,1,2]
    vector<int> nums = {1,3,2};
    int x = search(nums, 0);
    std::cout << x << std::endl;
    return 0;
}
