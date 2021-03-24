#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(string s);

int main() {
    string x = "abcbcababcabbbcbbc";
    isValid(x);

    return 0;
}

bool isValid(string s) {
    // If 's' start not with 'a' or  ended not with 'c' we return false
    if (s[0] != 97 || s.back() != 99) {
        return false;
    }
    vector<int> vector = {s[0]}; // Our stack
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 99) {
            // check only when we have 'c' on position
            if (vector.size() < 2) {
                // if we have on position i -> 'c' but stack is < as 2 we can not have 'a' and 'b' there
                return false;
            } else if (vector[vector.size() - 1] != 98 || vector[vector.size() - 2] != 97) {
                // check if last one was 'b' and for 'b' was 'a'
                // can be like [b,a,c] -> this is not correct that's why we check this step!
                return false;
            }
            // If we are here all was correct and we take oul last 2 elements from stack! We find a group 'abc'
            vector.pop_back();
            vector.pop_back();
        } else {
            // if is not 'c' on position
            vector.push_back(s[i]);
        }
    }
    // return empty vector because at last 'c' we need to take out last 2 elements and stack is empty
    return empty(vector);
}

