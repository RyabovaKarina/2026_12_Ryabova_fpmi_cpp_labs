#include <iostream>

int main() {
    int number;
    std::cin >> number;

    int duplicate = number;
    int reversed = 0;

    while (number > 0) {
        reversed *= 10;
        reversed += number % 10;
        number /= 10;
    }

    if (duplicate == reversed) {
        std::cout << "Palindrome";
    } else {
        std::cout << "Not palindrome";
    }

    return 0;
}