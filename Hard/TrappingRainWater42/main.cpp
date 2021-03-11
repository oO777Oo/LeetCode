#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}


int trap(vector<int>& height) {
    int ans = 0;
    int backIterator = height.size() - 1;
    std::vector<int> maxLeft = {};
    std::vector<int> maxRight = {};
    for (int i = 0; i < height.size(); i++) {
    	if (maxLeft.empty() && maxRight.empty()) {
    		maxLeft.push_back(height[i]);
    		maxRight.push_back(height[backIterator]);
    	} else {
    		// Left side.
    		if (maxLeft.back() < height[i]) {
    			maxLeft.push_back(height[i]);
    		} else {
    			maxLeft.push_back(maxLeft.back());
    		}
    		// Right side.
    		if (maxRight.back() < height[backIterator]) {
    			maxRight.push_back(height[backIterator]);
    		} else {
    			maxRight.push_back(maxRight.back());
    		}
    	}
    	backIterator --;
    }

    for (int i = 0; i < maxLeft.size(); i++) {
    	ans += min(maxLeft[i], maxRight.back()) - height[i];
    	maxRight.pop_back();
    }

    for (int i = 0; i < maxLeft.size(); i++) {
    	cout << height[i] << " ";
    }
    cout<< " " << endl;
    for (int i = 0; i < maxLeft.size(); i++) {
    	cout << maxLeft[i] << " ";
    }
    cout<< " " << endl;
    for (int i = 0; i < maxLeft.size(); i++) {
    	cout << maxRight[i] <<  " ";
    }
    cout<< " " << endl;
    return ans;
}

int main() {
	vector<int> nums = {4,2,0,3,2,5};
	cout<<trap(nums)<<endl;
	return 0;
}