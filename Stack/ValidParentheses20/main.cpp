#include <iostream>
#include <vector>

using namespace std;

bool isValid(string s);

int main() {
    isValid("(){[}]");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool isValid(string s) {
    char *arr = &s[0]; // init start point from string to arr
    vector<int> stack = {};
    for (int i = 0; i < s.size(); i++) {
        if (stack.empty()) {
            if (arr[i] == 41 || arr[i] == 125 || arr[i] == 93) {
                // check if value is one of ], }, ) make no sense to continue!
                return false;
            }
            stack.push_back(arr[i]);
        } else {
            if (arr[i] - 2 == stack[stack.size() - 1] || arr[i] - 1 == stack[stack.size() - 1]) {
                // using -2 and -1 while, '(' == 40 and ')' == 41 but for {} and [] are 123-125 and 91-93
                // check if currentValue is pair for last value ex: () [] {}
                stack.pop_back();
            } else if (arr[i] == 41 || arr[i] == 125 || arr[i] == 93) {
                // check if last one open bracket is different from current close bracket make no sense to continue
                return false;
            } else {
                stack.push_back(arr[i]);
            }
        }
    }
    return empty(stack);
}
