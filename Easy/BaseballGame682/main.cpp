#include <iostream>
#include <vector>

using namespace std;

int calPoints(vector<string> &ops);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int calPoints(vector<string> &ops) {
    vector<int> arr = {};
    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == "C") {
            arr.pop_back();
        } else if (ops[i] == "D") {
            arr.push_back(arr.back() * 2);
        } else if (ops[i] == "+") {
            arr.push_back(arr[arr.size() - 2] + arr.back());
        } else {
            arr.push_back(atoi((ops[i]).c_str()));
        }
    }
    int sum = 0;
    while (!arr.empty()) {
        sum += arr.back();
        arr.pop_back();
    }
    return sum;
}
