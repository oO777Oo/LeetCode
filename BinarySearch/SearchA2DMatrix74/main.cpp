#include <iostream>
#include <vector>

using namespace std;

/** Binary Search Horizontal
 * This method will search target horizontal in array
 * after we find vertical in which array can be our target;
 * */
bool binarySearchHorizontal(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size();

    while (end - start > 1) {
        int mid = (end + start) / 2;
        if(arr[mid] == target) {
            return true;
        }
        if(target < arr[mid]) {
            end = mid;
        } else {
            start = mid;
        }
    }
    return arr[start] == target;
}


/** Binary Search Vertical
 * This method will search target in matrix only for index 0
 * example matrix[n][0] to check in which array can be our target.
 * */
int binarySearchVertical(vector<vector<int>>& matrix, int target) {
    int start = 0;
    int end = matrix.size();

    while (end - start > 1) {
        int mid = (start + end) / 2;
        if (matrix[mid][0] == target) {
            return mid;
        }
        if(target < matrix[mid][0]) {
            end = mid;
        } else {
            start = mid;
        }
    }
    return start;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 1) {
        return binarySearchHorizontal(matrix[0], target);
    } else if (matrix[0].size() == 1) {
        return target == matrix[binarySearchVertical(matrix, target)][0];
    }
    return binarySearchHorizontal(matrix[binarySearchVertical(matrix, target)], target);
}

int main() {
    vector<vector<int>> matrix = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    std::cout << searchMatrix(matrix, 16) << std::endl;
    return 0;
}
