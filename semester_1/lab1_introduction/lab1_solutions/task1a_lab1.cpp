//only prime factors


#include <iostream>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;


    for (int i = 2; i <= std::min(M, N); i++) {
        if (N % i == 0 && M % i == 0) {
            bool isPrime = true;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                }
            }
            if (isPrime) {
                std::cout << i << std::endl;
            }
        }
    }

    return 0;
}