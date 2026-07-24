#include <stdio.h>
#include <string.h>
#include <assert.h>

#define CMD(NAME) \
    char NAME ## _cmd[256] = ""; \
    strcpy(NAME ## _cmd, #NAME);

// Функция теперь принимает поток извне
int execute_command_interpreter_di(FILE* input_stream) {
    CMD(copy)
    CMD(paste)
    CMD(cut)

    char cmd[256];
    if (fscanf(input_stream, "%255s", cmd) != 1) return -1;

    if(strcmp(cmd, copy_cmd) == 0) return 1;
    if(strcmp(cmd, paste_cmd) == 0) return 2;
    if(strcmp(cmd, cut_cmd) == 0) return 3;

    return 0;
}

void run_di_test() {
    // Для теста используем временный файл без подмены глобальных переменных
    FILE* test_input = tmpfile();
    fputs("paste", test_input);
    rewind(test_input);

    int result = execute_command_interpreter_di(test_input);
    fclose(test_input);

    assert(result == 2);
}

int main() {
    // В реальном приложении вызывалось бы так: execute_command_interpreter_di(stdin);
    run_di_test();
    printf("Вариант 3 (DI Mock): Все тесты успешно пройдены!\n");
    return 0;
}
