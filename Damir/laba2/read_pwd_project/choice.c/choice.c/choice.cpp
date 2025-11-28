#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h>
#endif

int main(int argc, char* argv[]) {
    if (argc < 2) return 0; // нет вариантов

#ifdef _WIN32
    int ch = _getch();  // читает 1 символ без Enter
    putchar(ch);        // чтобы пользователь видел что нажал
    putchar('\n');
#else
    int ch = getchar();
#endif

    char s[2];
    s[0] = (char)ch;
    s[1] = '\0';

    for (int i = 1; i < argc; i++) {
        if (strcmp(s, argv[i]) == 0) {
            return i; // порядковый номер параметра
        }
    }
    return 0;
}
