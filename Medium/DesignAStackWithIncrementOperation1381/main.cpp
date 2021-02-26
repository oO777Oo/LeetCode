#include <iostream>
#include <vector>

using namespace std;

class CustomStack;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class CustomStack {
    /** It's possible to design with out currentSize and to use stack.size() but like this we win some speed! */
public:
    int maxSize;
    int currentSize = 0;
    vector<int> stack = {};

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (this->maxSize > this->currentSize) {
            this->stack.push_back(x);
            this->currentSize ++;
        }
    }

    int pop() {
        if (this->currentSize == 0) {
            return -1;
        }
        int lastItem = this->stack.back();
        this->stack.pop_back();
        this->currentSize --;
        return lastItem;
    }

    void increment(int k, int val) {
        if(this->currentSize <= k) {
            for (int i = 0; i < this->currentSize; i++) {
                stack[i] += val;
            }
        } else {
            for (int i = 0; i < 5; i++) {
                stack[i] += val;
            }
        }
    }
};