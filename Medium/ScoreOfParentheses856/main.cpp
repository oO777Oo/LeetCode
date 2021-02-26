#include <iostream>
#include <vector>

using namespace std;

int scoreOfParentheses(string S);

int main() {
    std::cout << scoreOfParentheses("(()())") << std::endl;
    return 0;
}

int scoreOfParentheses(string S) {
    vector<int> stack = {0};

    for (char c : S) {
        if (c == 40) {
            stack.push_back(0);
        } else {
            int x = stack.back();
            stack.pop_back();
            int y = stack.back();
            stack.pop_back();
            if (2 * x < 1) {
                stack.push_back(y + 1);
            } else {
                stack.push_back(y + 2 * x);
            }
        }
    }
    return stack[stack.size() - 1];
}