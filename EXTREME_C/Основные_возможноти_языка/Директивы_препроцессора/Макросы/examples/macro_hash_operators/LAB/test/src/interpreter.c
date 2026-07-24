#include <stdio.h>
#include <string.h>

#define CMD(NAME) \
    char NAME ## _cmd[256] = ""; \
    strcpy(NAME ## _cmd, #NAME);

int execute_command_interpreter(void) {
    CMD(copy)
    CMD(paste)
    CMD(cut)

    char cmd[256]; // Строго массив!

    // Передаем cmd без знака &
    if (scanf("%255s", cmd) != 1) {
        return -1;
    }

    if (strcmp(cmd, copy_cmd) == 0) {
        return 1;
    }
    if (strcmp(cmd, paste_cmd) == 0) {
        return 2;
    }
    if (strcmp(cmd, cut_cmd) == 0) {
        return 3;
    }

    return 0;
}
/*
#ifndef TESTING
int main(int argc, char **argv) {
    return execute_command_interpreter();
}
#endif*/
