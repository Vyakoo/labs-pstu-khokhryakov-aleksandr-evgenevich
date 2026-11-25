#include <iostream>

using namespace std;

// Поиск числа в части массива
bool contains(int arr[], int start, int len, int target) {
    for (int i = 0; i < len; i++) {
        if (arr[start + i] == target) {
            return true;
        }
    }
    return false;
}

// Восстановление матрицы из одномерного массива
void restoreMatrix(int flat[], int** matrix, int N, int M) {
    int half = N * M; // Начало столбцов в общем массиве

    // Расставляем строки по первому столбцу
    for (int i = 0; i < N; i++) {
        int needed = flat[half + i];

        for (int r = 0; r < N; r++) {
            if (contains(flat, r * M, M, needed)) {
                for (int j = 0; j < M; j++) {
                    matrix[i][j] = flat[r * M + j];
                }
                break;
            }
        }
    }

    // Расставляем столбцы по первой строке
    for (int j = 0; j < M; j++) {
        int needed = matrix[0][j];

        for (int c = 0; c < M; c++) {
            if (contains(flat, half + c * N, N, needed)) {
                for (int i = 0; i < N; i++) {
                    matrix[i][j] = flat[half + c * N + i];
                }
                break;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int N, M;
    cout << "Введите размерность матрицы N и M: ";
    cin >> N >> M;

    int total = 2 * N * M;
    int* flat = new int[total];

    cout << "Введите " << total << " элементов одномерного массива:\n";
    for (int i = 0; i < total; i++) {
        cin >> flat[i];
    }

    // Выделяем память под матрицу
    int** matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[M];
    }

    restoreMatrix(flat, matrix, N, M);

    cout << "\nВосстановленная матрица:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    // Освобождаем память
    delete[] flat;
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
