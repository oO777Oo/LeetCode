#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList);

int main() {
    vector<vector<int>> firstList = {{0,  2},
                                     {5,  10},
                                     {13, 23},
                                     {24, 25}};
    vector<vector<int>> secondList = {{1,  5},
                                      {8,  12},
                                      {15, 24},
                                      {25, 26}};
    intervalIntersection(firstList, secondList);
    return 0;
}

vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
    vector<vector<int>> ans;

    if (firstList.empty() || secondList.empty()) {
        return ans;
    }

    int firstPointer = 0;
    int secondPointer = 0;

    while (firstPointer < firstList.size() && secondPointer < secondList.size()) {
        int minimum = max(firstList[firstPointer][0], secondList[secondPointer][0]);
        int maximum = min(firstList[firstPointer][1], secondList[secondPointer][1]);
        if (minimum <= maximum) {
            ans.push_back({minimum, maximum});
        }
        if (firstList[firstPointer][1] < secondList[secondPointer][1]) {
            ++firstPointer;
        } else {
            ++secondPointer;
        }
    }

    return ans;
}
