//M and N are negative


#include <iostream>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    int absN = N < 0 ? N * (-1) : N;
    int absM = M < 0 ? M * (-1) : M;

    for (int i = 1; i <= std::min(M, N); i++) {
        if (N % i == 0 && M % i == 0) {
            std::cout << i << std::endl;
            std::cout << i * (-1) << std::endl;
        }
    }

    return 0;
}