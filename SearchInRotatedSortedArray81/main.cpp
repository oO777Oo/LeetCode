#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target) {
    long long int start = 0;
    long long int end = nums.size() - 1;

    while (start <= end) {
        long long int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[start] <= nums[mid]) {
            if (target > nums[start] && target < nums[mid]) {
               end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            if (target > nums[mid] && target < nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    vector<int> x = {1,0,1,1,1}; // fail on this test case
    std::cout << search(x, 0) << std::endl;
    return 0;
}
