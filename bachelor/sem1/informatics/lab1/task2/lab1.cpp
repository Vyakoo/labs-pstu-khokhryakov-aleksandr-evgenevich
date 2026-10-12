#include <iostream>

//Стандартный способ избавиться от std::
using std::cout; 
using std::endl;
using std::cin;

//функция подсчета выражения с использованием float
void float_res() {
    float m = 0.0f;
    float n = 0.0f;

    cout << "Введите числа:" << endl;
    cin >> m;
    cin >> n;

    cout << "результаты:" << endl;
    cout << (--m) - (++n) << endl;
    cout << ((m*n) < (n++)) << endl;
    cout << ((n--) > (m++)) << endl;
}


//функция подсчета выражения с использованием double
void double_res() {
    double m = 0.0; 
    double n = 0.0;

    cout << "Введите числа:" << endl;
    cin  >> m;
    cin >> n;

    cout << "результаты:" << endl;
    cout << (--m) - (++n) << endl;
    cout << ((m*n) < (n++)) << endl;
    cout << ((n--) > (m++)) << endl;
}

int main() {
    float_res();
    double_res();

    return 0;
}