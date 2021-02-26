#include <iostream>
#include <vector>

using namespace std;

bool backspaceCompare(string S, string T);

void changeValue(vector<char> &vv, string s, int pointer);

int main() {
    string s = "xywrrmp";
    string t = "xywrrmu#p";
    std::cout << backspaceCompare(s,t) << std::endl;
    return 0;
}

bool backspaceCompare(string S, string T) {
    vector<char> stackS = {};
    vector<char> stackT = {};

    int sSize = S.size();
    int tSize = T.size();

    int iterator;

    if (sSize < tSize) {
        iterator = tSize;
    } else {
        iterator = sSize;
    }

    for(int i = 0; i < iterator; i++) {
        if (i < sSize) {
            changeValue(stackS, S, i);
        }
        if(i < tSize) {
            changeValue(stackT, T, i);
        }
    }
    return stackS == stackT;
}

void changeValue(vector<char> &vv, string s, int pointer) {
    if (s[pointer] != '#') {
        vv.push_back(s[pointer]);
    } else if (!empty(vv)) {
        vv.pop_back();
    }
}
