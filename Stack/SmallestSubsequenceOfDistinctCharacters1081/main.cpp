#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int calculateArea(vector<int>& heights);

int maximalRectangle(vector<vector<int>>& matrix) {
    int maximalArea = 0;
    vector<int> arr(matrix[0].size());

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] != 0) {
                arr[j] += matrix[i][j];
            } else {
                arr[j] = 0;
            }
        }
        int area = calculateArea(arr);
        if (maximalArea < area) {
            maximalArea = area;
        }
    }
    return maximalArea;
}

int calculateArea(vector<int>& heights) {
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
            vecSize--;
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

        if (!mobilLessRight.empty()) {
            lessRight.push_back(mobilLessRight.back());
        } else {
            lessRight.push_back(integralMinRight);
        }

        mobilLessRight.push_back(vecSize);
        mobilLessLeft.push_back(i);
        vecSize--;
    }

    // Calculate area.
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++, afterLength--) {
        if (maxArea < (lessRight[afterLength] - lessLeft[i] - 1) * heights[i]) {
            maxArea = (lessRight[afterLength] - lessLeft[i] - 1) * heights[i];
        }
    }
    return maxArea;
}

int main() {
    int t, n, m;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        cin >> n >> m; // read n and then m.
        vector<vector<int>> vec( n , vector<int> (m));
        for(int o = 0; o < n; o++) {
            for(int j = 0; j < m; j++) {
                cin>>vec[o][j];
            }
        }
        for(int o = 0; n < sizeof(vec) ; o++) {
            for(int j = 0; m < sizeof(vec[o]); j++) {
                cout<<vec[o][j];
            }
        }

        cout << "Case #" << i << ": " << (n + m) << " " << (n * m) << endl;
        // cout knows that n + m and n * m are ints, and prints them accordingly.
        // It also knows "Case #", ": ", and " " are strings and that endl ends the line.;
    }
    return 0;
}
