#include <iostream>

using namespace std;

string minWindow(string s, string t);
bool controlAns(string s, int arr[]);

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    std::cout << minWindow(s, t) << std::endl;
    return 0;
}

string minWindow(string s, string t) {
    int tData[57] = {};
    string ans = "";
    int ansLength = s.size();

    int length = 0;
    int pointer = 0;

    for (char i : t) {
        if (tData[i - 65] == 0) {
            tData[i - 65]++;
        }
        tData[i - 65]++;
    }
    string intermediate = "";
    int counter = t.size();
    for (int i = 0; i < s.size(); i++) {
        if (tData[s[i] - 65] != 0) {
            tData[s[i] - 65] --;
            counter --;
        }
        intermediate += s[i];
        length++;
        if (counter == 0 && length < ansLength) {
            ansLength = length;
            ans = intermediate;
        }
        while (counter < 0) {
            if(tData[s[pointer] - 65] != 0) {
                tData[s[pointer] - 65]++;
                counter ++;
            }
            length --;
            intermediate.erase(0,0);
            pointer ++;
        }

    }

    return ans;
}

/*TODO check method */
bool controlAns(string s, int arr[]) {
    for (int i = 0; i < s.length(); i++) {

    }
}
