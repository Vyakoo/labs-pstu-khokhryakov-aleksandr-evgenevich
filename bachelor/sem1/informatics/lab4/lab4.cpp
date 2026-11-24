#include <iostream>

using namespace std;

void printRing(int a[], int n, int k) {
    if (n <= 0) {
        cout << "Кольцо пустое." << endl;
        return;
    }

    int current = ((k % n) + n) % n;

    for (int step = 0; step < n; ++step) {
        cout << a[current];
        if (step < n - 1) {
            cout << " -> ";
        }
        current = (current - 1 + n) % n;
    }
    cout << endl;
}

void sortDescending(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void removeOdd(int a[], int& n) {
    int newSize = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            a[newSize] = a[i];
            newSize++;
        }
    }
    n = newSize;
}

int main() {
    setlocale(LC_ALL, "Russian");

    const int N = 100;
    int a[N];
    int n;

    cout << "Введите реальную длину массива (не более " << N << "): ";
    cin >> n;

    if (n <= 0 || n > N) {
        cout << "Ошибка: длина должна быть от 1 до " << N << "." << endl;
        return 0;
    }

    cout << "Введите " << n << " элементов массива: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int k;
    cout << "Введите индекс K (от 0 до " << n - 1 << "): ";
    cin >> k;

    cout << "\nПросмотр кольца от K до K+1: ";
    printRing(a, n, k);

    sortDescending(a, n);
    cout << "После сортировки по убыванию: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    removeOdd(a, n);
    cout << "После удаления нечетных элементов: ";
    if (n == 0) {
        cout << "элементов не осталось";
    } else {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
    }
    cout << endl;

    cout << "Итоговый просмотр кольца от K до K+1: ";
    printRing(a, n, k);

    return 0;
}
