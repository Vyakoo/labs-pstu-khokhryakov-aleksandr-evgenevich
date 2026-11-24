
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 256
#define HEIGHT 9
#define WIDTH 80

void printBySineWave(const char* str) {
    char screen[HEIGHT][WIDTH + 1];
    int len = strlen(str);

    if (len > WIDTH) {
        len = WIDTH;
    }

    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < len; c++) {
            screen[r][c] = ' ';
        }
        screen[r][len] = '\0';
    }

    int wave[] = {4, 2, 1, 0, 1, 2, 4, 6, 7, 8, 7, 6};
    int period = 12;

    for (int i = 0; i < len; i++) {
        int row = wave[i % period];
        screen[row][i] = str[i];
    }

    printf("\nТекст по синусоиде:\n\n");
    for (int r = 0; r < HEIGHT; r++) {
        printf("%s\n", screen[r]);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    char s[MAX_LEN];

    printf("Введите предложение (до 255 символов, в конце точка):\n");
    fgets(s, MAX_LEN, stdin);
    s[strcspn(s, "\n")] = '\0';

    int len = strlen(s);
    if (len == 0 || s[len - 1] != '.') {
        printf("Ошибка: строка должна быть непустой и заканчиваться точкой!\n");
        return 1;
    }

    printBySineWave(s);

    return 0;
}
