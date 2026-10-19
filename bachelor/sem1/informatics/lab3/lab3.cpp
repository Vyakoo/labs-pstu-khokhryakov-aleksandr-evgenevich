#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double a = 0.1;
    double b = 1.0;
    double step = (b - a) / 10;
    int n = 20;
    double eps = 0.0001;

    // Настройка формата вывода данных
    cout << fixed << setprecision(6);
    cout << "---------------------------------------------------------\n";
    cout << "X\t\tSN (n=20)\tSE (eps=0.0001)\tY (Exact)\n";
    cout << "---------------------------------------------------------\n";

    for (double x = a; x <= b + 0.0001; x += step)
    {
        // Для k=0 первый член ряда равен x, инициализируем им суммы
        double SN = x, SE = x, a1 = x, b1 = x;

        // Вычисление при фиксированном n = 20
        for (int k = 1; k <= n; k++)
        {
            a1 = a1 * (x * x) / ((2 * k) * (2 * k + 1));
            SN += a1;
        }

        // Вычисление с заданной точностью eps
        for (int k = 1; fabs(b1) >= eps; k++)
        {
            b1 = b1 * (x * x) / ((2 * k) * (2 * k + 1));
            SE += b1;
        }

        // Точное значение функции для сравнения
        double Y = (exp(x) - exp(-x)) / 2.0;

        // Вывод результатов по форме методических указаний
        cout << "X=" << x << "\tSN=" << SN << "\tSE=" << SE << "\tY=" << Y << endl;
    }
    cout << "---------------------------------------------------------\n";

    return 0;
}
