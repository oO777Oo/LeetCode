#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target) {
    long int start = 0;
    long long int end = nums.size();

    if(nums.size() == 1) {
        return nums[0] == target;
    }
    if (nums.size() == 2) {
        return target == nums[0] || target == nums[1];
    }

    while (start <= end) {
        int mid = (end + start) / 2;
        int left = mid;
        int right = mid;
        if (nums[mid] == target) {
            return true;
        }
        if(mid != 0 && mid != nums.size()-1 && (nums[mid] == nums[mid -1] || nums[mid] == nums[mid + 1])) {
            while (left >= start && right <= end) {
                if (nums[left] != nums[mid]) {
                    mid = left;
                    break;
                } else {
                    left--;
                }
                if (nums[right] != nums[mid]) {
                    mid = right;
                    break;
                } else {
                    right++;
                }
            }
        }
        if (nums[mid] == target) {
            return true;
        }
        if (nums[start] < nums[mid]) {
            if (target <= nums[mid] && target >= nums[start]) {
               end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
           if(target >= nums[end - 1] && nums[mid] >= target) {
               start = mid + 1;
           } else {
               end = mid - 1;
           }
        }

    }
    return false;
}


int main() {
    //[1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1]
    vector<int> x = {2,5,6,0,0,1,2}; // fail on this test case
    std::cout << search(x, 3) << std::endl;
    return 0;
}
