#include <iostream>

using namespace std;


bool hasElement(const int* arr, int offset, int len, int target) {
    for (int i = 0; i < len; ++i) {
        if (arr[offset + i] == target) return true;
    }
    return false;
}


void restoreMatrix(const int* flat, int** matrix, int rows, int cols) {
    int colsStart = rows * cols; 
    

    for (int i = 0; i < rows; ++i) {
        int target = flat[colsStart + i];
        for (int r = 0; r < rows; ++r) {
            if (hasElement(flat, r * cols, cols, target)) {
                for (int j = 0; j < cols; ++j) {
                    matrix[i][j] = flat[r * cols + j];
                }
                break;
            }
        }
    }

   
    for (int j = 0; j < cols; ++j) {
        int target = matrix[0][j];
        for (int c = 0; c < cols; ++c) {
            if (hasElement(flat, colsStart + c * rows, rows, target)) {
                for (int i = 0; i < rows; ++i) {
                    matrix[i][j] = flat[colsStart + c * rows + i];
                }
                break;
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) cout << matrix[i][j] << "\t";
        cout << "\n";
    }
}

int main() {
    int rows, cols;
    cout << "Введите N и M: ";
    cin >> rows >> cols;

    int* flat = new int[2 * rows * cols];
    cout << "Введите элементы одномерного массива:\n";
    for (int i = 0; i < 2 * rows * cols; ++i) cin >> flat[i];

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) matrix[i] = new int[cols];

    restoreMatrix(flat, matrix, rows, cols);
    
    cout << "Результат:\n";
    printMatrix(matrix, rows, cols);

    delete[] flat;
    for (int i = 0; i < rows; ++i) delete[] matrix[i];
    delete[] matrix;
    return 0;
}


