#include <iostream>

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int n) {
    int number = 1702766719;
    if(n < number) {
        return 1;
    } else if (n > number) {
        return -1;
    } else {
        return 0;
    }
}

int guessNumber(int n) {
    long long number = n / 2;
    long long start = 0;
    long long end = n;

    while (start < end) {
        int ans = guess(number);

        if (ans == 0) {
            break;
        }

        if (ans == -1) {
            end = number - 1;
            number = (long long) (end + start) / 2;
        } else {
            start = number + 1;
            number = (long long) (end + start) / 2;
        }
    }
    return number;
}

int main() {
    std::cout << guessNumber(2126753390) << std::endl;
    return 0;
}
