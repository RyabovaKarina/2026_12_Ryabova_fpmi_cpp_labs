#include <iostream>

int main() {
    int a, b, d;
    std::cin >> a >> b >> d;

    for (int temp = a; temp <= b; temp = temp + d) {
        if (temp % 3 == 0) {
            std::cout << temp << std::endl;
        }
    }

    return 0;
}