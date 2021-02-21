#include <iostream>
#include <vector>

using namespace std;

bool canChoose(vector<vector<int>> &groups, vector<int> &nums);

int main() {
    vector<vector<int>> groups = {{1, -1, -1},
                                  {3, -2, 0}};
    vector<int> nums = {1, -1, 0, 1, -1, -1, 3, -2, 0};
    std::cout << canChoose(groups, nums) << std::endl;
    return 0;
}

bool canChoose(vector<vector<int>> &groups, vector<int> &nums) {
    int groupsLength = groups.size();
    int groupsFlag = 0;
    for (int numsItem = 0; numsItem < nums.size();) {
        if (groups[groupsFlag][0] == nums[numsItem]) {
            int currentLength = groups[groupsFlag].size();
            for (int groupItem = 0; groupItem < groups[groupsFlag].size(); groupItem++, numsItem++) {
                if (groups[groupsFlag][groupItem] == nums[numsItem]) {
                    currentLength--;
                } else {
                    break;
                }

                if (currentLength == 0) {
                    groupsFlag++;
                    groupsLength--;
                    if (groupsLength == 0) {
                        return true;
                    }
                }
            }
        } else {
            numsItem++;
        }
    }
    return groupsLength == 0;
}
