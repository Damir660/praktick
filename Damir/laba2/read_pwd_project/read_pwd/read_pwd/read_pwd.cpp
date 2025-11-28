#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif

int main(int argc, char* argv[]) {
    int timeout_sec = 20;
    if (argc >= 2) timeout_sec = atoi(argv[1]);
    if (timeout_sec <= 0) timeout_sec = 20;

    const char* pwd1 = "edit123";   // пароль для редактирования
    const char* pwd2 = "prog123";   // пароль для программирования

    char buf[128];
    int len = 0;

#ifdef _WIN32
    DWORD start = GetTickCount();

    while (1) {
        DWORD now = GetTickCount();
        if ((now - start) >= (DWORD)(timeout_sec * 1000)) {
            return 4; // таймаут
        }

        if (_kbhit()) {
            int ch = _getch(); // НЕ выводит символ на экран

            if (ch == '\r') { // Enter
                buf[len] = '\0';
                break;
            }
            if (ch == '\b') { // Backspace
                if (len > 0) len--;
                continue;
            }

            if (len < (int)sizeof(buf) - 1) {
                buf[len++] = (char)ch;
            }
        }

        Sleep(10);
    }
#else
    // На не-Windows просто читаем как обычно (без скрытия)
    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\r\n")] = 0;
#endif

    if (strcmp(buf, pwd1) == 0) return 1;
    if (strcmp(buf, pwd2) == 0) return 2;
    return 3;
}
