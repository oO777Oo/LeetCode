#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */


class NumArray {
public:
    std::vector<pair<int,int>> nums;
    
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
        	this->nums.push_back({nums[i], sum});
            sum += nums[i];       
        }    
    }
    
    int sumRange(int i, int j) {
        return (this->nums[j]).first + (this->nums[j]).second - (this->nums[i]).second;
    }
};


int main() {

	return 0;
}