#include <iostream>
#include <vector>

using namespace std;



/** The problem is to return one peak not the highest peak.
 * Solved with binary search.
 * */
int findPeakElement(vector<int>& nums) {
    int start = 0;
    int end = nums.size();

    /* Condition for size 1 and 2 */
    if (end == 1) {
        return 0;
    } else if(end == 2) {
        if (nums[0]> nums[1]) {
            return 0;
        } else {
            return 1;
        }
    }

    while(end - start > 1) {
        int mid = (end + start) / 2;

        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) { // exit condition
            return mid;
        }
        if (nums[mid] >= nums[start] && nums[mid] >= nums[mid - 1]) { // condition for start changing
            /* if value on index 'mid' is bigger as value on index 'start' and value on position is bigger as
             * value on index 'mid - 1' means we go on top of peak and we move start to right;
             * */
            start = mid + 1;
        } else {
            // else peak is between start and mid that's why we move end.
            end = mid;
        }
    }
    return start;
}

int main() {
    vector<int> nums = {1,3,2,1};

    std::cout << findPeakElement(nums) << std::endl;
    return 0;
}
