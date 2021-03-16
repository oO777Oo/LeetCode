#include <iostream>
#include <vector>
#include <map>

using namespace std;

string smallestSubsequence(string s) {
    vector<int> count(256);
    for(int i = 0; i < s.size(); i++) {
      count[s[i]]++;
    }
    vector<bool> added(256);

    string out;
    for(int i = 0; i < s.size(); i++) {
      if(!added[s[i]]) {
        while(out.size() > 0 && out.back() > s[i] && count[out.back()] > 0) {
          added[out.back()] = false;
          out.pop_back();
        }
        added[s[i]] = true;
        out.push_back(s[i]);
      }
      count[s[i]] --;
    }

    return out;
}

int main() {
    std::vector<int> v = {7,5,12,9,3,13,8,11};
    largestRectangleArea(v);
    return 0;
}
