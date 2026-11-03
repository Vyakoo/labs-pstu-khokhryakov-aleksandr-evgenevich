#include <iostream>

using std::cout, std::endl;

int main() {
    int A[7] = {5, 2, 8, 1, 9, 3, 7};
    int N = 7;

    // Сортировка вставками
    for (int i = 1; i < N; ++i) {
        int y = A[i]; // Запоминаем текущий элемент в буфер
        int j = i - 1;
        
        // Сдвигаем элементы, которые больше y, вправо
        while (j >= 0 && A[j] > y) {
            A[j + 1] = A[j];
            j--;
        }
        // Вставляем буфер на освободившееся место
        A[j + 1] = y; 
    }

    // Вывод результата
    std::cout << "Вставка: ";
    for (int i = 0; i < N; ++i) std::cout << A[i] << " ";
    std::cout << "\n";

    return 0;
}