#include <iostream>
#include <cmath>

//Стандартный способ избавиться от std::
using std::cout; 
using std::endl;
using std::pow;


//функция подсчета выражения с использованием float
void float_res() {
    float a = 1000.0f; 
    float b = 0.0001f;

    // Числитель и знаминатель
    float numerator = pow(a - b, 3) - (pow(a, 3) - 3 * pow(a, 2) * b);
    float denominator = pow(b, 3) - 3 * a * pow(b, 2);

    float result_float = numerator / denominator;

    //Вывожу результат
    cout << result_float << endl;
}


//функция подсчета выражения с использованием double
void double_res() {
    double a = 1000.0; 
    double b = 0.0001;

    // Числитель и знаминатель
    double numerator = pow(a - b, 3) - (pow(a, 3) - 3 * pow(a, 2) * b);
    double denominator = pow(b, 3) - 3 * a * pow(b, 2);

    double result_double = numerator / denominator;

    //Вывожу результат
    cout << result_double << endl;
}

int main() {
    float_res();
    double_res();
    return 0;
}