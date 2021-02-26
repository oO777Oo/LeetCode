#include <iostream>
#include <vector>

using namespace std;

int minAddToMakeValid(string S);


int main() {
    cout << minAddToMakeValid("(())(") << endl;
    return 0;
}


int minAddToMakeValid(string S) {
    vector<char> stack = {};

    for (int i = 0; i < S.size(); i++) {
        if (empty(stack)) {
           stack.push_back(S[i]);
        }
        if (stack[stack.size() - 1] + 1 == S[i]) {
            stack.pop_back();
        } else {
            stack.push_back(S[i]);
        }
    }
    return stack.size();
}