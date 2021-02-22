#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s);

int main() {
    string s = " ";
    cout << lengthOfLongestSubstring("ggububgvfk") << std::endl;
    return 0;
}

int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) {
        return 0;
    }
    int arr[128] = {};
    int maxLength = 0;

    int currentLength = 0;
    int pointer = 0;

    for (int i = 0; i < s.size(); i++) {
        arr[s[i]]++;
        currentLength++;

        while (arr[s[i]] > 1) {
            arr[s[pointer]]--;
            pointer++;
            currentLength--;
        }
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    return maxLength;
}
