#include <bits/stdc++.h>

using namespace std;

bool controlRight(int start, int mid) {
    return start == mid;
}

bool controlLeft(int mid, int end) {
    return mid == end;
}
    
    
bool search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size();

    if (nums.size() == 1) {
        return target == nums[0];
    }
    if (nums.size() == 2) {
        if (nums[0] == target || nums[1] == target) {
            return true;    
        } else {
            return false;
        }
    }

    while (end - start > 1) {
        int mid = (end + start) / 2;
        int rightPart = 0;
        int leftPart = 0;

        if (nums[mid] == target) {
            return true;
        }

        if(controlRight(nums[start], nums[mid])) {
            for (int i = mid ; i >= start ; i--) {
                if(nums[i] != nums[mid]) {
                    rightPart = i;
                    break;
                }
            }
            if (rightPart == 0) {
               start = mid;
            }
        }
        if(controlLeft(nums[mid], nums[end - 1])) {
            for (int i = mid; i < end; i++) {
                if (nums[i] != nums[mid]) {
                    leftPart = i;
                    break;
                }
            }
            if (leftPart == 0) {
               end = mid;
            }
        } else {
            if (nums[mid] >= nums[start]) {
               if (target <= nums[mid] && target >= nums[start]) {
                   end = mid;
               } else {
                   start = mid + 1;
               }
            } else {
                if (target >= nums[mid] && target <= nums[end-1]) {
                   start = mid + 1;
                } else {
                    end = mid;
                }
            }
        }
    }
    return nums[start] == target;
}

int main() {
	return 0;
}