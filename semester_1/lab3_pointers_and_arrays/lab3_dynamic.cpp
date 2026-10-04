//var 10
// solve task with usage of
// dymanic arrays

#include <iostream>
#include <random>

int checkInput(int &size) {
    std::cout << "Enter the size: ";
    if (!(std::cin >> size) || size <= 0) {
        std::cout << "ERROR: wrong size";
        return 1;
    }
    return 0;
}

int inputArray(int* array, int size) {
    std::cout << "Enter " << size << " elements" << std::endl;
    for (int i = 0; i < size; i++) {
        if (!(std::cin >> array[i])) {
            std::cout << "ERROR: wrong element";
            return 1;
       }
    }
    return 0;
}

int askEnterMode(int& mode) {
    std::cout << "Enter mode (1 - manual, 2 - random): ";
    if (!(std::cin >> mode) || (mode != 1 && mode != 2)) {
        std::cout << "ERROR: wrong mode";
        return 1;
    }
    return 0;
}

int enterBounds(int& a, int& b) {
    std::cout << "Enter a and b (a <= b): ";
    if (!(std::cin >> a >> b) || a > b) {
        std::cout << "ERROR: wrong bounds";
        return 1;
    }
    return 0;
}

void enterRandom(int* array, int size, int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(a, b);

    for (int i = 0; i < size; i++) {
        array[i] = dist(gen);
    }
}

void moveLeft(int* array, int size, int index) {
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
}

bool hasOddOnes(int n) {
    int count = 0;
    unsigned int value = (n < 0) ? static_cast<unsigned int>(-n) : static_cast<unsigned int>(n);
    while (value > 0) {
        if (value & 1) {
            ++count;
        }
        value >>= 1;
    }
    return (count % 2) != 0;
}

void removeAndAddZero(int* array, int size) {
    int writeIdx = 0;
    for (int readIdx = 0; readIdx < size; readIdx++) {
        if (!hasOddOnes(array[readIdx])) {
            array[writeIdx++] = array[readIdx];
        }
    }
    for (int i = writeIdx; i < size; i++) {
        array[i] = 0;
    }
}

void outputArray(int* array, int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]";
}

int main() {
    int n;
    int mode;

    if (checkInput(n) != 0)
        return 1;

    if (askEnterMode(mode) != 0)
        return 1;

    int* arr = new int[n];

    if (mode == 1) {
        if (inputArray(arr, n) != 0) {
            delete[] arr;
            return 1;
        }
    }
    else {
        int a, b;
        if (enterBounds(a, b) != 0) {
            delete[] arr;
            return 1;
        }
        enterRandom(arr, n, a, b);
    }

    std::cout << "Original array: ";
    outputArray(arr, n);
    std::cout << std::endl;

    removeAndAddZero(arr, n);

    std::cout << "Result array:   ";
    outputArray(arr, n);
    std::cout << std::endl;

    delete[] arr;

    return 0;
}