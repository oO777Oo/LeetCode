#include <iostream>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans = {};
    for (int i = 0; i < asteroids.size(); i++){
        if(empty(ans)) {
            ans.push_back(asteroids[i]);
        } else if (ans.back() > 0 && asteroids[i] < 0) {
            while (abs(asteroids[i]) >= ans.back() && ans.back() > 0) {
                if (abs(asteroids[i]) == ans.back()) {
                    ans.pop_back();
                    break;
                }
                ans.pop_back();
                if (empty(ans)) {
                    ans.push_back(asteroids[i]);
                    break;
                }
                if (ans.back() < 0) {
                    ans.push_back(asteroids[i]);
                    break;
                }
            }
        } else {
            ans.push_back(asteroids[i]);
        }
    }
    return ans;
}



int main() {

	return 0;
}