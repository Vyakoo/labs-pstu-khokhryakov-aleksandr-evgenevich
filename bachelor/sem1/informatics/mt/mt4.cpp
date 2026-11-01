#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. Запрашиваем слово у пользователя
    string word;
    cout << "Введите строку (из букв a и b): ";
    cin >> word;

    // 2. Делаем ленту: добавляем '2' в начало и в конец
    string tape = "q" + word + "q";
    
    int head = 1;      // Позиция головки (начинаем с первой буквы слова)
    int state = 1;     // Текущее состояние (начинаем с q1)
    bool running = true;

    // 3. Запускаем симуляцию машины
    while (running) {
        char symbol = tape[head]; // Смотрим, какой символ сейчас под головкой

        switch (state) {
            case 1:
                if (symbol == 'a') { state = 2; head++; } // Переходим в q2, сдвиг вправо
                else if (symbol == 'b') { state = 5; head++; } // Переходим в q5, сдвиг вправо
                else if (symbol == '2') { cout << "Результат: TRUE\n"; running = false; }
                break;

            case 2:
                if (symbol == 'a') { head++; } // Остаёмся в q2, сдвиг вправо
                else if (symbol == 'b') { head++; } // Остаёмся в q2, сдвиг вправо
                else if (symbol == '2') { state = 3; head--; } // Встретили границу -> в q3, влево
                break;

            case 3:
                if (symbol == 'a') { tape[head] = '2'; state = 4; head--; } // Стираем 'a' -> в q4, влево
                else if (symbol == 'b') { tape[head] = '2'; state = 8; head--; } // Ошибка (буквы не совпали) -> в q8
                else if (symbol == '2') { cout << "Результат: TRUE\n"; running = false; }
                break;

            case 4:
                if (symbol == 'a') { head--; } // Идём обратно влево к началу
                else if (symbol == 'b') { head--; }
                else if (symbol == '2') { state = 1; head++; } // Дошли до левой границы -> в q1, шаг вправо
                break;

            case 5:
                if (symbol == 'a') { head++; } // Ищем правую границу для буквы 'b'
                else if (symbol == 'b') { head++; }
                else if (symbol == '2') { state = 6; head--; } // Нашли -> в q6, шаг влево
                break;

            case 6:
                if (symbol == 'a') { tape[head] = '2'; state = 8; head--; } // Ошибка (буквы не совпали) -> в q8
                else if (symbol == 'b') { tape[head] = '2'; state = 7; head--; } // Стираем 'b' -> в q7, влево
                break;

            case 7:
                if (symbol == 'a') { head--; } // Идём обратно влево к началу
                else if (symbol == 'b') { head--; }
                else if (symbol == '2') { state = 1; head++; } // Дошли до левой границы -> в q1, шаг вправо
                break;

            case 8:
                if (symbol == 'a' || symbol == 'b') { tape[head] = '2'; head--; } // Стираем остатки ленты
                else if (symbol == '2') { cout << "Результат: FALSE\n"; running = false; }
                break;
        }
    }

    return 0;
}