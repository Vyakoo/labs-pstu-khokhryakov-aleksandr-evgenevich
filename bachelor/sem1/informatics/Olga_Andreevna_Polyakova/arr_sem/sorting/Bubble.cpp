#include <iostream>

using std::cout, std::endl;

int main() {
    int A[7] = {5, 2, 8, 1, 9, 3, 7};
    int N = 7;

    // Сортировка пузырьком
    for (int i = 0; i < N - 1; ++i) {
        bool F = false; // Флаг
        
        for (int j = 0; j < N - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                // Обмен через буфер y
                int y = A[j];
                A[j] = A[j + 1];
                A[j + 1] = y;
                F = true; // Фиксируем что был обмен
            }
        }
        
        // Если обменов не было, массив отсортирован, выходим из цикла
        if (F == false) {
            break;
        }
    }

    cout << "Обмен:   ";
    for (int i = 0; i < N; ++i) cout << A[i] << " ";
    cout << endl;

    return 0;
}