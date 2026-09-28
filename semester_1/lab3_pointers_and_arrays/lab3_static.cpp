//var 8
// solve task with usage of
// static arrays

#include <iostream>
#include <random>

const int MAXSIZE = 10000;

int checkInput(int &size) {
    if (!(std::cin >> size) || size > MAXSIZE || size <= 0) {
        std::cout << "ERROR: wrong size";
        return 1;
    }
    return 0;
}

int inputArray(double* array, int size) {
    for (int i = 0; i < size; i++) {
        if (!(std::cin >> array[i])) {
            std::cout << "ERROR: not a number";
            return 1;
        }
    }
    return 0;
}

int askEnterMode(int& mode) {
    if (!(std::cin >> mode) || (mode != 1 && mode != 2)) {
        std::cout << "ERROR: wrong mode";
        return 1;
    }
    return 0;
}

int enterBounds(double& a, double& b) {
    if (!(std::cin >> a >> b) || a > b) {
        std::cout << "ERROR: wrong bounds";
        return 1;
    }
    return 0;
}

int inputAmount(int& amount, int size) {
    if (!(std::cin >> amount) || amount > size) {
        std::cout << "ERROR: wrong amount";
        return 1;
    }
    return 0;
}

void enterRandom(double* array, int size, double a, double b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(a, b);

    for (int i = 0; i < size; i++) {
        array[i] = dist(gen);
    }
}

void outputArray(double* array, int size) {
        std::cout << "[ ";
        for (int i = 0; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << "]";
    }

int findMinIndex(double* array, int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void moveLeft(double* array, int size, int index) {
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
}

void removeAndAddZero(double* array, int size, int amount) {
    int original_n = size;              

    for (int k = 0; k < amount; k++) {    
        int minIndex = findMinIndex(array, size);   
        moveLeft(array, size, minIndex);           
        size--;                                     
    }

    for (int i = size; i < original_n; i++) {       
        array[i] = 0.0;
    }
}

int main()
{
    double arr[MAXSIZE];
    int n;
    int N;
    int mode;

    std::cout << "Enter the size: ";
    if (checkInput(n) != 0)
        return 1;

 
    std::cout << "Enter mode (1 - manual, 2 - random): ";

    if (askEnterMode(mode) != 0)
        return 1;

    if (mode == 1) {
        std::cout << "Enter the elements: ";
        if (inputArray(arr, n) != 0)
            return 1;
    }
    else {
        double a, b;
        std::cout << "Enter a and b (a <= b): ";
        if (enterBounds(a, b) != 0)
            return 1;
        enterRandom(arr, n, a, b);
    }

    std::cout << "Enter the amount of min elements: ";
    if (inputAmount(N, n) != 0)
        return 1;

    removeAndAddZero(arr, n, N);
    outputArray(arr, n);

    return 0;
}
