#include <my_logger.h>

#include <assert.h>
#ifdef _WIN32
#    include <windows.h>
#else
#    include <locale.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
#ifdef _WIN32
    SetConsoleOutputCP(65001); // Для Windows
#else
    setlocale(LC_ALL, "Russian");
#endif
    DEBUG("SYSTEM LOGGINGS ACTIVATED :) !!! \n\n", "");
    return 0;
}
