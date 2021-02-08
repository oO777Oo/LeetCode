#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size();

    while (end - start > 1) {
        int mid = (start + end) / 2;
        if (arr[mid] == target) {
            return true;
        }
        if (arr[mid] > target) {
            end = mid;
        } else {
            start = mid;
        }
    }
    return arr[start] == target;
}


/** TODO find a second binary search implementation for this case! */
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(int i = 0; i < matrix.size(); i ++) {
        if (binarySearch(matrix[i], target)) {
            return true;
        }
    }
    return false;
}


int main() {
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    std::cout << searchMatrix(matrix, 5) << std::endl;
    return 0;
}
