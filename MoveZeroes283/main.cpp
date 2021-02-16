#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int pointer1 = 0;
    int pointer2 = 0;
    while (pointer2 < nums.size()) {
        if (nums[pointer1] != 0) {
            pointer1 ++;
            pointer2 ++;
        } else if(nums[pointer2] == 0) {
            pointer2 ++;
        } else {
            int c = nums[pointer1];
            nums[pointer1] = nums[pointer2];
            nums[pointer2] = c;
        }
    }
}

int main() {
    // [0,1,0,3,12]
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    return 0;
}
