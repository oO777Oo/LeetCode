#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numRescueBoats(vector<int>& people, int limit);

int main() {
    vector<int> people = {5,1,4,2};
    cout << numRescueBoats(people, 6) << endl;
    return 0;
}

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int firstPointer = 0, secondPointer = people.size() - 1;
    int boats = 0;

    while (firstPointer <= secondPointer) {
        boats++;
        if (people[firstPointer] + people[secondPointer] <= limit)
            firstPointer++;
        secondPointer--;
    }
    return boats;
}
