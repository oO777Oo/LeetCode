#include <iostream>
#include <vector>

using namespace std;

string removeOuterParentheses(string S);

int main() {
    removeOuterParentheses("(()())(())(()(()))");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

string removeOuterParentheses(string S) {
    vector<char> stack = {};
    string ans = "";
    int open = 0;

    for (int i = 0; i < S.size(); i++) {
        if (empty(stack)) {
            open++;
            stack.push_back(S[i]);
        } else {
            if (S[i] == 40) {
                stack.push_back(S[i]);
                ans += S[i];
                open++;
            } else if (open != 1 && S[i] == 41) {
                ans += S[i];
                stack.pop_back();
                open--;
            } else {
                stack.pop_back();
                open--;
            }
        }
    }
    return ans;

}
