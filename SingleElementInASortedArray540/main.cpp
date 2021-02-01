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

int singleNonDuplicate(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    if(end == 0) {
        return nums[0];
    }
    if (nums[0] != nums[1]) {
        return nums[0];
    }
    if (nums[end] != nums[end - 1]) {
        return nums[end];
    }

    while (start <= end) {
        int mid = (start + end) / 2;
        if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }
        if (nums[mid] == nums[mid + 1]) {
            if((end - mid + 1) % 2 == 0) {
                end = mid;
            } else if ((end - mid + 1) % 2 != 0) {
                start = mid - 1;
            }
        } else if (nums[mid] == nums[mid - 1]) {
            if((mid - 1 - start) % 2 == 0){
                start = mid;
            }else if ((mid - 1 - start) % 2 != 0) {
                end = mid - 1;
            }
        }
    }
    return 0;
}

int main() {
    // [1,1,2,3,3,4,4,8,8]
    // [0,1,2,3,4,5,6,7,8]
    vector<int> nums = {2,2,3,3,4,4,8};
    int x = singleNonDuplicate(nums);
    std::cout << x << std::endl;

    return 0;
}
