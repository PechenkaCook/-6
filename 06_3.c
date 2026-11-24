#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    int number;
    unsigned long long count1 = 0, count2 = 0;
    double sum1 = 0.0, sum2 = 0.0;

    puts("Вводите целые числа. Для завершения введите 0.");
    while (scanf("%d", &number) == 1 && number != 0) {
        int digits_sum = 0;
        int temp = number;

        while (temp != 0) {
            int digit = temp % 10;
            if (digit < 0) {
                digit = -digit;
            }
            digits_sum += digit;
            temp /= 10;
        }

        if (number > 0 && number % digits_sum == 0) {
            count1++;
            sum1 += number;
        } else {
            count2++;
            sum2 += number;
        }
    }

    printf("Чисел Харшад: %llu\n", count1);
    if (count1 > 0) {
        printf("Среднее: %.4f\n", sum1 / count1);
    } else {
        puts("Среднее не определено: группа пуста.");
    }

    printf("Остальных чисел: %llu\n", count2);
    if (count2 > 0) {
        printf("Среднее: %.4f\n", sum2 / count2);
    } else {
        puts("Среднее не определено: группа пуста.");
    }
    return 0;
}
