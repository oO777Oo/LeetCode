#include <iostream>
#include <vector>

using namespace std;

string removeKdigits(string num, int k) {
    if(k == 0) {
        return num;
    }
    
    if(k >= num.length()) {
        return "0";
    }

    vector<int> v = {};
    string ans = "";

    for (int i = 0; i < num.length(); i++) {
        int number = num[i];
        if (empty(v)) {
            if (number != 48) {
                v.push_back(number);
            } else {
                k--;
            }
        } else {
            if (k <= 0) {
                v.push_back(number);
            } else {
                while (k > 0 && !empty(v) && number < v.back()) {
                    v.pop_back();
                    k--;
                }
                v.push_back(num[i]);
            }
        }
        if (k < 0) {
            k = 0;
        }
    }

    bool flag = false;
    for (int i = 0; i < v.size() - k; i++) {
        if(empty(ans) && v[i] == 48) {
            continue;
        } else {
            ans += v[i];
        }
    }
    if(empty(ans)) {
        return "0";
    }
    return ans;
}

int main() {

	cout << removeKdigits("1234567890", 9);
	return 0;
}