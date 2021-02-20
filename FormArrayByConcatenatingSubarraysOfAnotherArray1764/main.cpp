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
    for (int i = 0; i < nums.size();) {
        if (groups[groupsFlag][0] == nums[i]) {
            int currentLength = groups[groupsFlag].size();
            for (int groupItem = 0; groupItem < groups[groupsFlag].size(); groupItem++) {
                if (groups[groupsFlag][groupItem] == nums[i]) {
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
                i++;
            }
        } else {
            i++;
        }
    }
    return groupsLength == 0;
}
