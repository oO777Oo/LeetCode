#include <iostream>

using namespace std;

string minWindow(string s, string t);

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    std::cout << minWindow(s, t) << std::endl;
    return 0;
}

string minWindow(string s, string t) {
    if (t.size() > s.size()) {
        return "";
    }

    int tData[57] = {};
    int mobileVector[57] = {};
    int counter = t.size();
    int minimum = INT_MAX;
    pair<int, int> indexes;
    int pointer = 0;

    for (int i = 0; i < t.size(); i++) {
        tData[t[i] - 65]++;
        mobileVector[t[i] - 65]++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (tData[s[i] - 65] != 0) {
            if (mobileVector[s[i] - 65] - 1 >= 0) {
                counter--;
            }
            mobileVector[s[i] - 65]--;
        }
        while (counter == 0) {
            if (minimum > i - pointer) {
                indexes.first = pointer;
                indexes.second = i;
                minimum = i - pointer;
            }
            if (tData[s[pointer] - 65] > 0) {
                if (mobileVector[s[pointer] - 65] >= 0) {
                    counter++;
                }
                mobileVector[s[pointer] - 65]++;
            }
            pointer++;
        }
    }
    string ans = "";
    if (minimum != INT_MAX) {
        for (int i = indexes.first; i <= indexes.second; i++) {
            ans += s[i];
        }
    }
    return ans;
}
