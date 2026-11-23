#include <iostream>

int main() {
    int n = 5; 

  
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 1;
        }
    }

    
    for (int i = 0; i < n; ++i) {
        matrix[i][i] = 0;             // Главная диагональ
        matrix[i][n - 1 - i] = 0;     // Побочная диагональ
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    for (int i = 0; i < n; ++i) {
        delete[] matrix[i]; 
    }
    delete[] matrix; 
    return 0;
}
