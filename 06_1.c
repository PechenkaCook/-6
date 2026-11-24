#include <stdio.h>
#include <ctype.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    int ch;
    int previous = 0;
    unsigned long long count = 0;

    while ((ch = getchar()) != EOF && ch != '#') {
        if (isalpha((unsigned char)ch) && previous == 'i' && ch == 'f') {
            count++;
        }
        previous = ch;
    }

    printf("Вхождений if: %llu\n", count);
    return 0;
}
