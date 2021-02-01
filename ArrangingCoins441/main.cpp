#include <iostream>


using namespace std;

int arrangeCoins(int n) {
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

int main() {
    int x = arrangeCoins(1804289383);

    std::cout << x << std::endl;
    std::cout << 1804289383 * 8 << std::endl;
    return 0;
}
