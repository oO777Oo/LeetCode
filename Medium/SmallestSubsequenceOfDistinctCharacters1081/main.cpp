#include <iostream>
#include <vector>
#include <map>

using namespace std;
string returnAns(vector<int>& v, int k) {
    string ans = "";
    if(k >= 0) {
        for (int i = 0; i < v.size() - k; i++) {
            ans += v[i];
        }
    } else {
        for (int i = 0; i < v.size(); i++) {
            ans += v[i];
        }
    }
    return ans;
}


string removeKdigits(string num, int k) {
    if(k >= num.length()) {
        return "0";
    }

    std::vector<int> v = {};
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
    for (int i = 0; i < v.size() - k; i++) {
        ans += v[i];
    }
    if(empty(ans)) {
        return "0";
    }
    return ans;
}



int main() {
    cout<< removeKdigits("112", 1);
    return 0;
}