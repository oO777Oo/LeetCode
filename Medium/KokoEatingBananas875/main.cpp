#include <iostream>
#include <vector>

using namespace std;


int controlFunction(vector<int>& piles, int eatSpeed) {
    int speed = 0;
    for (int i = 0; i < piles.size(); i++) {
        if(piles[i] % eatSpeed == 0){
            speed += piles[i] / eatSpeed;
        } else {
            speed += piles[i] / eatSpeed + 1;
        }
    }
    return speed;
}


int minEatingSpeed(vector<int>& piles, int H) {
    int max = 0;
    for (int i: piles) {
        if (i > max) {
            max = i;
        }
    }

    int start = 0;
    int end = max + 1;
    int ans = 0;
    while (end - start > 1) {
        int mid = (end + start) / 2;
        if (controlFunction(piles, mid) <= H) {
            ans = mid;
            end = mid;
        } else {
            start = mid;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {3,6,7,11};
    std::cout << minEatingSpeed(arr, 8) << std::endl;
    return 0;
}
