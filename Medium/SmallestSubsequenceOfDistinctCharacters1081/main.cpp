#include <iostream>
#include <vector>


using namespace std;

string smallestSubsequence(string s) {
    int chars[30] = {};
    vector<char> stack = {};
    int lengthAns = 0;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (chars[s[i] - 97] != 1) {
            chars[s[i] - 97] = 1;
            stack.push_back(s[i]);
        } else {
            if (lengthAns < stack.size()) {
                ans = readString(stack, s[i]);
                lengthAns = stack.size();
            }
            stack.push_back(s[i]);
        }
    }
    if (lengthAns <= stack.size()) {
        ans = readString(stack, s[i]);
    }
    return ans; 
}

string readString(vector<char>& data, char ex) {
    string ans = "";
    int current = 0;
    for (int i = 0; i < data.size(); i++) {
        if(data[i] == ex) {
            current = i;
        }
        ans += data[i];
    }
    data.erase(data.begin(), data.begin() + current + 1);
    return ans;
}

int main() {
    
    return 0;
}
