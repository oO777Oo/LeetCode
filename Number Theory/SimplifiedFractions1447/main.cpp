#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    return 0;
}

vector<string> simplifiedFractions(int n) {
    std::vector<string> v;

    int number1 = n;
    int number2 = n;

    for(;number1 > 1; number1 --) {
        number2 = number1 - 1;
        for (;number2 > 0; number2 --) {
            if (euclid(number1, number2) == 1) {
                v.push_back(to_string(number2) + "/" + to_string(number1));
            } 
        }
    }
    return v;
}
    
int euclid(int x, int y) {
    return x == 0 ? y : euclid(y % x , x);
}

