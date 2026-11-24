#include <stdio.h>
#include <math.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    double energy;
    double part1 = 0.0, part2 = 0.0, part3 = 0.0;

    printf("Введите расход электроэнергии в кВт·ч: ");
    if (scanf("%lf", &energy) != 1 || !isfinite(energy) || energy < 0.0) {
        puts("Ошибка: нужен неотрицательный конечный расход.");
        return 0;
    }

    if (energy <= 200.0) {
        part1 = energy;
    } else if (energy <= 500.0) {
        part1 = 200.0;
        part2 = energy - 200.0;
    } else {
        part1 = 200.0;
        part2 = 300.0;
        part3 = energy - 500.0;
    }

    double cost1 = part1 * 0.05;
    double cost2 = part2 * 0.10;
    double cost3 = part3 * 0.15;

    printf("Исходный расход: %.2f кВт·ч\n", energy);
    printf("До 200: %.2f * 0.05 = %.2f\n", part1, cost1);
    printf("От 200 до 500: %.2f * 0.10 = %.2f\n", part2, cost2);
    printf("Свыше 500: %.2f * 0.15 = %.2f\n", part3, cost3);
    printf("Итого: %.2f\n", cost1 + cost2 + cost3);
    return 0;
}
