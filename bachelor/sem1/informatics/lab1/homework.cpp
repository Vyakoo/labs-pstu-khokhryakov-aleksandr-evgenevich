#include <iostream>
#include <cmath>

//Стандартный способ избавиться от std::
using std::cout; 
using std::endl;
using std::pow;


int main() {
    //Используем тип long double чтобы не терять в точности вычислений (с double выдавало число -1.00136 что является ошибкой)
    long double a = 1000.0; 
    long double b = 0.0001;

    // Числитель и знаминатель
    long double numerator = pow(a - b, 3) - (pow(a, 3) - 3 * pow(a, 2) * b);
    long double denominator = pow(b, 3) - 3 * a * pow(b, 2);

    long double result = numerator / denominator;

    //Вывожу результат
    cout << result << endl;
    return 0;
}