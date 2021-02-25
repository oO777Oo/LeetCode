#include <iostream>
#include <vector>

using namespace std;

string removeDuplicates(string S);


int main() {
    vector<char> stack = {65};
    std::cout << removeDuplicates("abbaca") << std::endl;
    return 0;
}

string removeDuplicates(string S) {
    vector<char> stack = {};
    for (int i = 0; i < S.size(); i++) {
        if (empty(stack)) {
            stack.push_back(S[i]);
        } else if (stack.back() == S[i]) {
            stack.pop_back();
        } else {
            stack.push_back(S[i]);
        }
    }
    return string(stack.begin(), stack.end());
}
