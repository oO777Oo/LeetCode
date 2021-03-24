#include <iostream>
#include <vector>

using namespace std;

int minOperations(vector<string>& logs);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int minOperations(vector<string>& logs) {
    vector<string> ans = {};
    for (int i= 0; i < logs.size(); i++) {
        if (logs[i] == "../") {
            if(!ans.empty()) {
                ans.pop_back();
            }
        } else if (logs[i] == "./") {
            continue;
        } else {
            ans.push_back(logs[i]);
        }
    }
    return ans.size();
}
