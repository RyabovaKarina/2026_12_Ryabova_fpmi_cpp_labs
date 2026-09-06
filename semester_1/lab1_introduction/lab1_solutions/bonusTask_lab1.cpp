#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    int counter = 1;
    
    for (int i = 1; i < n; i++) {
        std::cout << "   ";
        counter += 1;
    }
    
    for (int i = 1; i <= k; i++) {
        if (i < 10) {
            std::cout << " ";
        }
        std::cout << i;
        
        counter += 1;
        
        if (counter == 8) {
            std::cout << std::endl;
            counter = 1;
        } else {
            if (i != k) {
                std::cout << " ";
            }
        }
    }
    
    return 0;
}