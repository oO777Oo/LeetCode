#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<pair<int, int>> data = {};
    int length = -1;

    void push(int x) {
        if (this->data.empty()) {
            data.emplace_back(x, x);
        } else {
            int min = this->getMin();
            if (min > x) {
                data.emplace_back(x, x);
            } else {
                data.emplace_back(x, min);
            }
        }
        this->length++;
    }

    void pop() {
        this->data.pop_back();
        this->length--;
    }

    int top() {
        return this->data[this->length].first;
    }

    int getMin() {
        return this->data[this->length].second;
    }
};


int main() {
    auto *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl; // return -3
    minStack->pop();
    cout << minStack->top() << endl;   // return 0
    cout << minStack->getMin() << endl; // return -2
    return 0;
}

