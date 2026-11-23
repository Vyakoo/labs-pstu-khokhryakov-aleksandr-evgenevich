/* Задача 1 (массивы): Дан одномерный массив целых чисел. Найти 
максимальный и минимальный
элементы. Вывести их значения, индексы первого встретившегося 
максимального и минимального
элементов, а также посчитать количество элементов, 
равных максимальному и минимальному (если их
несколько). Исходный массив создать самостоятельно 
(не использовать rand), чтобы можно было
проверить все случаи. */
#include <iostream>

using std::cout, std::endl;

int main () {
    int arr[10] = {1, 12, 12, 2, 3, 12, 432, 432, 21, 42, };
    int length = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0], min = arr[0], maxIndex = 0, minIndex = 0, maxCount = 0, minCount = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] > max) max = arr[i], maxIndex = i, maxCount = 0;
        if (arr[i] < min) min = arr[i], minIndex = i, minCount = 0;

        if (arr[i] == max) maxCount++;
        if (arr[i] == min) minCount++;
    }
    cout << "Максимальное число:" << max << "\t\tИндекс:" << maxIndex << "\t\tКоличество повторов:" << maxCount << endl;
    cout << "Минимальное число:" << min << "\t\tИндекс:" << minIndex << "\t\tКоличество повторов:" << minCount << endl;

    return 0;
}