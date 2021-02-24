#include <iostream>
#include <string>
#include <vector>

using namespace std;

/** Using 2 pointers */
bool checkInclusion(string s1, string s2);

/** Second Method using char*/
bool checkInclusion1(string s1, string s2);

void fillArrayBack(string s, int data[]);

int main() {
    /**
     * hello
     * ooohlleoooleh
     * */
    string s1 = "hello";
    string s2 = "ooolleoooleh";
    std::cout << checkInclusion(s1, s2) << std::endl;
    return 0;
}

// 2 Pointers
bool checkInclusion(string s1, string s2) {
    int n1= s1.length(), n2= s2.length();
    if(n1>n2) return false;
    vector<int>arr1(26,0), arr2(26,0);

    int i;
    for(i=0; i<n1; i++) {
        arr1[s1[i]-97]++;
        arr2[s2[i]-97]++;
    }
    if(arr1==arr2) return true;

    for(; i<n2; i++) {
        arr2[s2[i-n1]-97]--;
        arr2[s2[i]-97]++;
        if(arr1==arr2) return true;
    }
    return false;
}


// Chars!
bool checkInclusion1(string s1, string s2) {
    if (s1.size() > s2.size()) {
        return false;
    }
    int data[26] = {};
    for (char i : s1) {
        if (data[i - 97] == 0) {
            data[i - 97] = 2;
        } else {
            data[i - 97]++;
        }
    }
    string intermediate = "";
    for (int i = 0; i < s2.size(); i++) {
        if (intermediate.size() == s1.size()) {
            return true;
        }
        if (data[s2[i] - 97] == 0) {
            fillArrayBack(intermediate, data);
            intermediate = "";
        } else if (data[s2[i] - 97] > 1) {
           intermediate += s2[i];
           data[s2[i]-97]--;
        } else {
            data[intermediate[0] - 97] ++;
            intermediate.erase(0,1);
            i--;
        }
    }
    return intermediate.size() == s1.size();

}

void fillArrayBack(string s, int data[]) {
    for (char &i:s) {
        if(data[i - 97] == 1) {
            data[i-97] = 2;
        } else {
            data[i - 97] ++;
        }
    }
}