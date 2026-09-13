#include <iostream>

int main() {
    int a, b;
    std::cout << "Enter a and b: ";
    
    if (!(std::cin >> a >> b)) {
        std::cout << "Error: invalid input" << std::endl;
        return 1;
    }

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    bool flag = true;

    std::cout << "Result: ";

    for (int i = a; i <= b; i++) {

        bool notPrime = false;  //checking if prime
        if (i <= 1) {
            notPrime = true;
        } else {
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    notPrime = true;
                    break;
                }
            }
        }

        if (notPrime) {  
            continue;
        }

        bool differentDigits = true;   //checking difference

        int current = i;
        while (current >= 1 && differentDigits) {
            int digit1 = current % 10;
            int ostatok = current / 10;

            while (ostatok > 0) {
                int digit2 = ostatok % 10;

                if (digit1 == digit2) {
                    differentDigits = false;
                    break;
                }
                
                ostatok /= 10;
            }
            current /= 10;
        }
 
        if (differentDigits) {
            std::cout << i << " ";
            flag = false;
        }

    }    
    

    if (flag) {
        std::cout << "No numbers";
    }

    return 0;
}