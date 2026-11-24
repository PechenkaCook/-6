#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

int main(void)
{
    setlocale(LC_ALL, "");
#ifdef _WIN32
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
#endif
    const wchar_t word[] = L"пока";
    wint_t ch;
    int matched = 0;
    unsigned long long count = 0;

    // getchar читает байты, getwchar преобразует ввод в широкие символы.
    // В UTF-8 одна русская буква занимает несколько байтов.
    while ((ch = getwchar()) != WEOF && ch != L'#') {
        if (ch == (wint_t)*(word + matched)) {
            matched++;
        } else if (ch == L'п') {
            matched = 1;
        } else {
            matched = 0;
        }

        if (matched == 4) {
            count++;
            matched = 0;
        }
    }

    wprintf(L"Вхождений пока: %llu\n", count);
    return 0;
}
