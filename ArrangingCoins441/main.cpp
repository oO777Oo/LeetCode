#include <iostream>


using namespace std;

// First possibility
int arrangeCoins1(int n) {
    /** We have formula k(k+1) / 2 for numbers 1+2+3+4+...k
     * That's means k(k+1) / 2 = n
     * k^2 + k - 2n = 0
     * Δ = 1 + 8n;
     * x1 = [-1 + sqrt(Δ)] / 2
     * x2 is not interesting for us because is negative 0 point from parabola
     * and we search positive number
     * floating point number will be recast to left because of int
     * for example 4.8 -> 4;
     * */

    long long int delta  = 1 + 8 * (long long int) n;
    return (int) (-1 + sqrt(delta)) / 2;
}

// Solved using binary search
int arrangeCoins(int n) {
    long long int start = 1;
    long long int end = n;
    if(n == 0) {
        return 0;
    }

    while (end - start > 1) {
        long long int mid = (end + start) / 2;
        long long int ans = mid*(mid +1) / 2;
        if (ans <= n) {
            start = mid;
        } else {
            end = mid;
        }
    }
    return (int) start;
}


int main() {
    int x = arrangeCoins(2147483647);
    std::cout << x << std::endl;
    return 0;
}
