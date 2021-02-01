#include <iostream>

using namespace std;

/** First method*/
int mySqrt1(int x) {
    return (int) sqrt(x);
}

/** Second method binary search */
int mySqrt(int x) {
    long long int number = x / 2;
    long long int start = 0;
    long long int end = x;

    if (x == 1) {
        return 1;
    } else if (x == 0) {
        return 0;
    }

    while (start <= end) {
        if (number * number == x || (number * number < x && (number + 1) * (number + 1) > x)) {
            return (int) number;
        }
        if (number * number > x) {
            end = number - 1;
            number = (start + end) / 2;
        } else {
            start = number + 1;
            number = (start + end) / 2;
        }
    }
    return x;
}


int main() {
    int x = mySqrt(6);
    std::cout << x << std::endl;
    return 0;
}
