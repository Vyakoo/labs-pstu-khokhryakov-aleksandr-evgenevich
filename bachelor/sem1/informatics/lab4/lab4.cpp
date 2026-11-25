#include <iostream>

using namespace std;

// Вывод массива по кольцу (влево от K)
void printRing(int a[], int n, int k) {
    if (n <= 0) {
        cout << "Кольцо пустое." << endl;
        return;
    }

    // Если K больше размера массива (после удаления элементов), берем корректный индекс
    int current = k % n; 

    for (int i = 0; i < n; i++) {
        cout << a[current] << " ";
        
        current--;          // Двигаемся влево
        if (current < 0) {  // Если вышли за левый край — прыгаем в конец
            current = n - 1;
        }
    }
    cout << endl;
}

// Сортировка по убыванию (пузырьком)
void sortDescending(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] < a[j + 1]) {
                swap(a[j], a[j + 1]); // Встроенная функция обмена значений
            }
        }
    }
}

// Удаление нечётных элементов
void removeOdd(int a[], int& n) {
    int j = 0; // Индекс для записи чётных чисел
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            a[j] = a[i];
            j++;
        }
    }
    n = j; // Новый размер массива
}

int main() {
    setlocale(LC_ALL, "Russian");

    int a[100];
    int n, k;

    cout << "Введите длину массива (от 1 до 100): ";
    cin >> n;
    if (n <= 0 || n > 100) {
        cout << "Ошибка длины!" << endl;
        return 0;
    }

    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Введите индекс K: ";
    cin >> k;

    cout << "\nКольцо от K до K+1: ";
    printRing(a, n, k);

    sortDescending(a, n);
    cout << "По убыванию: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    removeOdd(a, n);
    cout << "Без нечётных: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    cout << "Итоговое кольцо: ";
    printRing(a, n, k);

    return 0;
}
