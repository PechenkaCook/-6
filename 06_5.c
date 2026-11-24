#include <stdio.h>
#include <math.h>
#ifdef _WIN32
#include <windows.h>
#endif

int clear_line(void)
{
    int ch;
    int valid = 1;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch != ' ' && ch != '\t' && ch != '\r') {
            valid = 0;
        }
    }
    return valid;
}

int read_value(double *value)
{
    int status = scanf("%lf", value);
    if (status == EOF) {
        return -1;
    }
    int valid = clear_line();
    if (status != 1 || !valid || !isfinite(*value)) {
        return 0;
    }
    return 1;
}

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    double choice, amount, percent;

    while (1) {
        puts("\n1 Процент от суммы");
        puts("2 Сумма с НДС 20%");
        puts("3 Сумма без НДС 20%");
        puts("4 Чаевые 10%");
        puts("0 Выход");
        printf("Выберите пункт: ");

        int status = read_value(&choice);
        if (status == -1) {
            break;
        }
        if (status == 0 || choice < 0 || choice > 4 || choice != (int)choice) {
            puts("Ошибка: введите целый номер от 0 до 4.");
            continue;
        }
        if (choice == 0) {
            break;
        }

        printf("Введите неотрицательную сумму: ");
        status = read_value(&amount);
        if (status == -1) {
            break;
        }
        if (status == 0 || amount < 0.0) {
            puts("Неверная сумма.");
            continue;
        }

        switch ((int)choice) {
            case 1:
                printf("Введите неотрицательный процент: ");
                status = read_value(&percent);
                if (status == -1) {
                    return 0;
                }
                if (status == 0 || percent < 0.0) {
                    puts("Неверный процент.");
                    continue;
                }
                printf("Результат: %.2f\n", amount * (percent / 100.0));
                break;
            case 2:
                printf("С НДС: %.2f\n", amount * 1.20);
                break;
            case 3:
                printf("Без НДС: %.2f\n", amount / 1.20);
                break;
            case 4:
                printf("Чаевые: %.2f\n", amount * 0.10);
                break;
        }
    }
    return 0;
}
