/*
Подсчитать сумму элементов каждой строки двумерного
массива. Отработать форматированный вывод матрицы
по правому краю (без «лесенки») и строго построчное
отображение.
*/

#include <iostream>
#include <iomanip>

using std::cout, std::endl, std::setw;

int main() {
    const int ROWS = 3;
    const int COLS = 4;
    
    // Инициализация двумерного массива
    int matrix[ROWS][COLS] = {
        {2, 2, 3, 5},
        {25, 6, 70, 8},
        {91, 10, 121, 12}
    };
    
    for (int i = 0; i < ROWS; ++i) {
        int sum = 0;
        for (int j = 0; j < COLS; ++j) {
            sum += matrix[i][j];
            // setw(5) выделяет 5 символов под число, выравнивая по правому краю
            cout << setw(5) << matrix[i][j]; 
        }
        cout << " | Сумма: " << sum << endl;
    }
    return 0;
}