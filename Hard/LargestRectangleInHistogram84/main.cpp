#include <iostream>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    std::vector<int> lessLeft = {};
    std::vector<int> lessRight = {};
    
    std::vector<int> mobilLessLeft = {};
    std::vector<int> mobilLessRight = {};

    int integralMinLeft = -1;
    int integralMinRight = heights.size();
    int vecSize = integralMinRight - 1;
    int afterLength = vecSize;

    for (int i = 0; i < heights.size(); i++) {
        // First Iteration: initialization
        if (lessLeft.empty() && lessRight.empty()) {
            lessLeft.push_back(integralMinLeft);
            lessRight.push_back(integralMinRight);
            mobilLessRight.push_back(vecSize);
            mobilLessLeft.push_back(i);
            vecSize --;
            continue;
        }

        // Less Left block.
        while (!mobilLessLeft.empty() && heights[mobilLessLeft.back()] >= heights[i]) {
            mobilLessLeft.pop_back();
        }
        
        if (!mobilLessLeft.empty()) {
            lessLeft.push_back(mobilLessLeft.back());
        } else {
            lessLeft.push_back(integralMinLeft);
        }

        // Less Right block.
        while (!mobilLessRight.empty() && heights[mobilLessRight.back()] >= heights[vecSize]) {
            mobilLessRight.pop_back();
        }

        if(!mobilLessRight.empty()) {
            lessRight.push_back(mobilLessRight.back());
        } else {
            lessRight.push_back(integralMinRight);
        }

        mobilLessRight.push_back(vecSize);
        mobilLessLeft.push_back(i);
        vecSize --;
    }

    // Calculate area.
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++, afterLength --) {
        if(maxArea < (lessRight[afterLength] - lessLeft[i] - 1) * heights[i]) {
            maxArea = (lessRight[afterLength] - lessLeft[i] - 1) * heights[i];
        }
    }
    return maxArea;  
}  


int main() {
    std::vector<int> v = {1,1};
    largestRectangleArea(v);
    return 0;
}