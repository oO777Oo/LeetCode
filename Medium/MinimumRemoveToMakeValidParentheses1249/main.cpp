#include <iostream>
#include<vector>

using namespace std;

string minRemoveToMakeValid(string s);

int main() {
    cout << minRemoveToMakeValid("a)b(c)d") << endl;
    return 0;
}

string minRemoveToMakeValid(string s) {
    vector<pair<char, int>> checkStack = {};
    vector<char> stack = {};
    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] < 97) {
            if (empty(checkStack)) {
                checkStack.push_back(pair{s[i], i});
                stack.push_back('#');
            } else if (checkStack[checkStack.size() - 1].first + 1 == s[i]) {
                stack[checkStack[checkStack.size() - 1].second] = checkStack[checkStack.size() - 1].first;
                stack.push_back(s[i]);
                checkStack.pop_back();
            } else {
                checkStack.push_back(pair{s[i], i});
                stack.push_back('#');
            }
        } else {
            stack.push_back(s[i]);
        }
    }
    for (char i : stack) {
        if (i != '#') {
            ans += i;
        }
    }
    return ans;
}
