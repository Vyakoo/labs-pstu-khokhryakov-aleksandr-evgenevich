#include <iostream>

int main() {
    int A[7] = {5, 2, 8, 1, 9, 3, 7};
    int N = 7;

    // Сортировка выбором
    for (int i = 0; i < N - 1; ++i) {
        int minIndex = i; // Индекс минимального элемента
        
        // Ищем минимум в оставшейся части
        for (int j = i + 1; j < N; ++j) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }
        
        // Если нашли минимум меньше текущего, меняем их местами через буфер y
        if (minIndex != i) {
            int y = A[i];
            A[i] = A[minIndex];
            A[minIndex] = y;
        }
    }

    std::cout << "Выбор:   ";
    for (int i = 0; i < N; ++i) std::cout << A[i] << " ";
    std::cout << "\n";

    return 0;
}