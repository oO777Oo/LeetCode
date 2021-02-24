#include <iostream>
#include <vector>

using namespace std;



/**
 * Problem has 3 sids not 2 like Search in rotated array, with out value repetition
 * because in Search in rotated array with out repetition we have only 2 sids left and right,
 * in this problem we have mid side too because mid with a value can has a whole part of array
 * like in example {..., 8, 8, 8, 8, ...}. In this case we have 3 cases!
 * 1) If left side has the same value till mid like in example: {2,2,2,2,2,2,3,4,5,6}
 *      1.1) In this case if target is not 2 than we search target number in the right side of array!
 * 2) If mid value is the same till right side like in example: {1,2,3,4,5,5,5,5,5}
 *      2.1) In this case if target is not 5 than we search target number in the left side of array!
 * 3) If array is like {1,2,3,4,5,6,7}
 *      3.1) In this case is used only binary search.
 *
 * All 3 cases can be combined that's why is used a control if mid is the same like start or
 * mid is the same like end of the array. In case of both ifs are false is used binary search algorithm.
 * */
bool controlRight(int start, int mid) {
    return start == mid;
}

bool controlLeft(int mid, int end) {
    return mid == end;
}

bool search(vector<int>& nums, int target) {
    int start = 0; // start of array
    int end = nums.size(); // end of array

    if (nums.size() == 1) { // case when array has only one element
        return target == nums[0];
    }
    if (nums.size() == 2) { // case if array has 2 elements
        if (nums[0] == target || nums[1] == target) {
            return true;
        } else {
            return false;
        }
    }

    while (end - start > 1) {
        int mid = (end + start) / 2;
        int rightPart = 0; // check right side
        int leftPart = 0; // check left side

        if (nums[mid] == target) {
            // Exit condition
            return true;
        }

        if(controlRight(nums[start], nums[mid])) {
            // Condition if value in mid is the same like value on start!
            for (int i = mid ; i >= start ; i--) {
                // Check if all numbers from start till mid are the same number
                if(nums[i] != nums[mid]) {
                    rightPart = i;
                    break;
                }
            }
            /* if rightPart are 0 that's means that loop till start is finished and target can not be there.
             * Target can not be there because we check if mid value is target and if value is target
             * the method is finished and we come not in this block of code, that's means target is not
             * in range [left .. mid] because in this range is the same value*/
            if (rightPart == 0) {
               start = mid;
            }
        }
        if(controlLeft(nums[mid], nums[end - 1])) {
            // Control leftPart the same logic like rightPart only in range [mid .. right]
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
            /* If code come in this block means that mid != left and mid != right and we need to find where
             * is our target location.
             * */
            if (nums[mid] >= nums[start]) {
                // if mid value > start value means are sorted numbers from start to mid!
               if (target <= nums[mid] && target >= nums[start]) {
                   /* condition if target is <= mid value and >= start value
                    * means that target must be between left and mid.
                    * With using binary search algorithm we give mid value to end */
                   end = mid;
               } else {
                   // else target is on the right side and we give mid value to start
                   start = mid + 1;
               }
            } else {
                /* This else means if mid value is not bigger as left value
                 * in this case we control if target is between mid and right
                 * */
                if (target >= nums[mid] && target <= nums[end-1]) {
                    // if target is between mid and right we give mid value to start
                    start = mid + 1;
                } else {
                    // else target is on left side and we give mid value to end
                    end = mid;
                }
            }
        }
    }
    return nums[start] == target; // Return start
    /* I can return start because as right value I use a not correct value,
     * that's why my exit while condition is end-start > 1 because of end.
     * I use binary search a little bit different end is arr.size() and not arr.size() - 1
     * */
}



int main() {
    /*Test cases:
     * [1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1], target 2
     * [1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1], target 13
     * [2,2,2,3,1], target 1
     * [2,5,6,0,0,1,2], target 0
     * */
    vector<int> x = {2,2,2,3,1};
    std::cout << search(x, 1) << std::endl;
    return 0;
}
