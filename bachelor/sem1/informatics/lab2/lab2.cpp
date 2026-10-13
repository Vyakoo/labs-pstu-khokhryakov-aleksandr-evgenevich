#include <iostream>
#include <cmath>

using std::cout;
using std::pow;
using std::endl;
using std::exp;
using std::sqrt;




int main() {
    double totalSum = 0.0;
    double aN = 0.0;
    for (int n = 1; n <=7; ++n) {
        aN = pow(n, 2) * exp(-sqrt(n));
        cout << "Элемент - " << n << " = " << aN << endl; 
        totalSum += aN;
    }
    cout << "Итоговая сумма равна: " << totalSum << endl;
    return 0;
}
