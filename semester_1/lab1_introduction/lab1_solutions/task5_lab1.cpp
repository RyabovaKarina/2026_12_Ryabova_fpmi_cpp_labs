#include <iostream>

int main() {
    int number;
    std::cin >> number;

    int f0 = 0;
    int f1 = 1;
    std::cout << f0 << std::endl;
    std::cout << f1 << std::endl;

    for (int i = 2; i < number; i++) {
        int fn = f0 + f1;
        std::cout << fn << std::endl;
        f0 = f1;
        f1 = fn;
    }

    return 0;
}