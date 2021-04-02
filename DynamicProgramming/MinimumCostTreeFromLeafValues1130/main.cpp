#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>


int mctFromLeafValues(std::vector<int>& arr);

int main() {
	return 0;
}

int mctFromLeafValues(std::vector<int>& arr) {
	int biggest = INT_MIN;
    int secondBiggest = INT_MIN;
    for(int i : arr) {
        if(biggest < i) {
            secondBiggest = biggest;
            biggest = i;
        } else if(secondBiggest < i) {
            secondBiggest = i;
        }
    }

    int ans = biggest * secondBiggest;
    std::vector<std::vector<int>> workStack = {arr};

    while(!empty(workStack)) {
        std::vector<int> current = workStack.back();
        workStack.pop_back();
        std::vector<int> nextStack;
        std::vector<std::pair<int,int>> array = {{current[0], 0}};

        nextStack.push_back(current[0]);

        for(int i = 1; i < current.size(); i++) {
            // init last pair
            std::pair<int,int> lastValue =  array.back();
            std::pair<int,int> val = {current[i], 0};

            // in caz cind cifra este fara pereche
            if (lastValue.second != 1) {
                lastValue.first = lastValue.first * current[i];
                lastValue.second = 1;

                // delete last value
                nextStack.pop_back();

                // add new value
                nextStack.push_back(lastValue.first);
                ans += lastValue.first;

                array.pop_back();
                array.push_back(lastValue);
            } else {
                // in caz ca cu valuarea cu urmatoare pereche ii mai mica decit precedenta
                if (lastValue.first > current[i-1] * current[i]) {
                    ans -= lastValue.first; // scoatem din raspuns
                    nextStack.pop_back(); // scoatem din stackul urmator
                    nextStack.push_back(lastValue.first / current[i-1]); // adaugam elementu fara pereche in stackul urmator!
                    nextStack.push_back(current[i-1] * current[i]); // adaugam elementu cu pereche in stackul urmator!

                    // init pair
                    val.first = current[i-1] * current[i];
                    val.second = 1;
                    array.push_back(val); // adaugam in lista cu perechi
                    ans += val.first; // adaugam pereche in raspuns
                } else {
                    // in caz ca inmultirea ii mai mare
                    array.push_back(val);
                    nextStack.push_back(val.first);
                }
            }
        }
        if (nextStack.size() > 2) {
            workStack.push_back(nextStack);
        }
    }
    return ans;
}