#include <iostream>
#include <random>

void allocateMatrix(int**& matrix, int rows, int cols) {
    matrix = new int* [rows]();
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols] {};
    }
}

void destroyMatrix(int**& matrix, int rows) {
    if (!matrix) return;
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

bool inputSize(int& rows, int& cols) {
    std::cout << "Enter sizes of rows and cols: ";
    if (!(std::cin >> rows) || rows <= 0 ||
        !(std::cin >> cols) || cols <= 0) {
        std::cout << "ERROR: wrong size\n";
        return false;
    }
    return true;
}

bool askEnterMode(int& mode) {
    std::cout << "Enter mode (1 - manual, 2 - random): ";
    if (!(std::cin >> mode) || (mode != 1 && mode != 2)) {
        std::cout << "ERROR: wrong mode\n";
        return false;
    }
    return true;
}

bool enterBounds(int& a, int& b) {
    std::cout << "Enter a and b (a <= b): ";
    if (!(std::cin >> a >> b) || a > b) {
        std::cout << "ERROR: wrong bounds\n";
        return false;
    }
    return true;
}

bool inputMatrix(int** matrix, int rows, int cols) {
    std::cout << "Enter matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(std::cin >> matrix[i][j])) {
                std::cout << "ERROR: wrong element\n";
                return false;
            }
        }
    }
    return true;
}

void enterRandomMatrix(int** matrix, int rows, int cols,
    int a, int b, std::mt19937& gen) {
    std::uniform_int_distribution<int> dist(a, b);
    for (int i = 0; i < rows; i++) {
        int* row = matrix[i];
        for (int j = 0; j < cols; j++) {
            row[j] = dist(gen);
        }
    }
}

void createPrefMatrix(int** matrix, int** matrix_prefsum, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix_prefsum[i][j] = matrix[i][j];
            if (i > 0) {
                matrix_prefsum[i][j] += matrix_prefsum[i - 1][j];
            }
            if (j > 0) {
                matrix_prefsum[i][j] += matrix_prefsum[i][j - 1];
            }
            if (i > 0 && j > 0) {
                matrix_prefsum[i][j] -= matrix_prefsum[i - 1][j - 1];
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    std::mt19937 gen(12345);

    int** mat = nullptr;
    int** mat_result = nullptr;
    int rows1, cols1;

    if (!(inputSize(rows1, cols1))) return 1;

    int mode;
    if (!askEnterMode(mode)) return 1;

    allocateMatrix(mat, rows1, cols1);
    allocateMatrix(mat_result, rows1, cols1);

    if (mode == 1) {
        if (!inputMatrix(mat, rows1, cols1)) {
            destroyMatrix(mat, rows1);
            destroyMatrix(mat_result, rows1);
            return 1;
        }
    }
    else {
        int a, b;
        if (!enterBounds(a, b)) {
            destroyMatrix(mat, rows1);
            destroyMatrix(mat_result, rows1);
            return 1;
        }
        enterRandomMatrix(mat, rows1, cols1, a, b, gen);
    }

    createPrefMatrix(mat, mat_result, rows1, cols1);

    std::cout << "\nOriginal matrix:\n";
    printMatrix(mat, rows1, cols1);

    std::cout << "\nPrefix sum matrix:\n";
    printMatrix(mat_result, rows1, cols1);

    destroyMatrix(mat, rows1);
    destroyMatrix(mat_result, rows1);

    return 0;
}