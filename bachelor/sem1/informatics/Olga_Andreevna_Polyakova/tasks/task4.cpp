/*
Найти максимальный элемент двумерного массива
(матрицы) и вывести его индексы (строку и столбец).
*/

#include <iostream>

using std::cout, std::endl;

int main() {
    const int ROWS = 2;
    const int COLS = 3;
    int matrix[ROWS][COLS] = {
        {1, 5, 3},
        {7, 2, 9}
    };

    int maxVal = matrix[0][0];
    int maxRow = 0, maxCol = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    cout << "Максимальный элемент: " << maxVal << endl;
    cout << "Строка: " << maxRow << ", Столбец: " << maxCol << endl;

    return 0;
}