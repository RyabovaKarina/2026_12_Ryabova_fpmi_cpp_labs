#include <iostream>

int main() {
    int number;
    std::cin >> number;

    int sum1 = 0;
    int sum2 = 0;
    
    for (int i = 0; i < 3; i++) {
        sum1 += number % 10;
        number /= 10;
    }

    for (int i = 0; i < 3; i++) {
        sum2 += number % 10;
        number /= 10;
    }

    std::cout << (sum1 == sum2 ? "Lucky" : "Not lucky");

    return 0;
}