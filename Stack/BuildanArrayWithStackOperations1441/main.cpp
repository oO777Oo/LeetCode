#include <iostream>
#include <vector>

using namespace std;

vector<string> buildArray(vector<int> &target, int n);

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

vector<string> buildArray(vector<int> &target, int n) {
    vector<string> ans = {};
    int pointer = 0;
    int i = 1;

    while (i <= n && pointer > target.size()) {
        if (target[pointer] == i) {
            ans.push_back("Push");
            pointer++;
            i++;
        } else {
            ans.push_back("Push");
            ans.push_back("Pop");
            i++;
        }
    }
    return ans;
}
