#include <iostream>
#include <vector>


using namespace std;

/* Algo complexity is N*log(N) */
/* Check method to control if mid number come in range what we need */
long long int checkArray(vector<int>& nums, long long int mid) {
    long long int sum = 0;
    for (long long int i : nums) {
        if (i <= mid) {
            sum += 1;
        } else {
            if(i % mid == 0){
                sum += i / mid;
            } else {
                sum += i / mid + 1;
            }
        }
    }
    return sum;
}


int smallestDivisor(vector<int>& nums, int threshold) {
    long long int sum = 0;
    long long int start = 1;
    long long  int end = 0;

    /* Find maxim number and check sum of numbers */
    for (long long int i : nums) {
        sum += i;
        if (end < i) {
            end = i;
        }
    }

    if (sum <= threshold) {
        return 1;
    }
    end ++;

    while (end - start > 1) {
        long long int mid = (end + start) / 2;
        if (checkArray(nums, mid) <= threshold) { // if mid is in range end come to mid
            end = mid;
        } else {
            start = mid;
        }
    }
    return (int) end;
}



int main() {
    vector<int> nums = {1,2,3};
    std::cout << smallestDivisor(nums, 6) << std::endl;
    return 0;
}
