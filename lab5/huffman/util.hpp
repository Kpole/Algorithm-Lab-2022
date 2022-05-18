#ifndef UTIL_HPP
#define UTIL_HPP

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
int Sleep(int ms) {
    return usleep(ms * 1000);
}
#endif // _WIN32

void Pause() {
#ifdef _WIN32
    system("pause");
#else
    printf("Press Enter to continue");
    getchar();
#endif // DEBUG
}

#endif // !1 UTIL_HPP
