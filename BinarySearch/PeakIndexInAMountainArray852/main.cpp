#include <iostream>
#include <vector>

using namespace std;

/**
 * First possibility O(n)
 * */
int findPeakElement1(vector<int>& nums) {
    int start = nums[0];
    int position = 0;
    for (int i = 1 ; i < nums.size(); i++) {
        if (start < nums[i]) {
            start = nums[i];
            position = i;
        } else {
            break;
        }
    }
    return position;
}

/**
 * Second possibility binary search iterative O(log n)
 * */
int findPeakElement2(vector<int>& arr) {
    int minPosition = 0;
    int maxPosition = arr.size() - 1;

    while (minPosition < maxPosition) {
        int position = minPosition + (maxPosition - minPosition) / 2;

        if (arr[position] < arr[position + 1]) {
            minPosition = position + 1;
        } else {
            maxPosition = position;
        }
    }
    return minPosition;
}

/**
 * Third possibility binary search recursive
 * */
int binarySearch(int max, int min, vector<int> arr) {
    int position = min + (max - min) / 2;
    if (arr[position] > arr[position + 1] && arr[position] > arr[position - 1]) {
        return position;
    }
    if (arr[position] < arr[position + 1]) {
        min = position + 1;
    }
    return binarySearch(position, min, arr);
}

int findPeakElement(vector<int>& arr) {
    return binarySearch((int) arr.size() - 1, 0, arr);
}

int main() {
    vector<int> nums = {24,69,100,99,79,78,67,36,26,19};
    int x = findPeakElement(nums);
    std::cout << x  << std::endl;
    return 0;
}
