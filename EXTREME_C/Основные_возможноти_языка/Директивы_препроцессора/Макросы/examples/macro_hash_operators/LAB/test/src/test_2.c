#include <stdio.h>
#include <string.h>
#include <assert.h>

#define CMD(NAME) \
    char NAME ## _cmd[256] = ""; \
    strcpy(NAME ## _cmd, #NAME);

int execute_command_interpreter(void) {
    CMD(copy)
    CMD(paste)
    CMD(cut)

    char cmd[256];
    if (scanf("%255s", cmd) != 1) return -1; // Защита от переполнения и конца файла

    if(strcmp(cmd, copy_cmd) == 0) {
        return 1; // Возвращаем ID команды для верификации в тесте
    }
    if(strcmp(cmd, paste_cmd) == 0) {
        return 2;
    }
    if(strcmp(cmd, cut_cmd) == 0) {
        return 3;
    }
    return 0;
}

void run_file_mock_test(const char* input_text, int expected_result) {
    // Создаем временный файл с тестовыми данными
    FILE* tmp = fopen("mock_input.txt", "w+");
    fputs(input_text, tmp);
    rewind(tmp);

    // Подменяем stdin временным файлом
    FILE* saved_stdin = stdin;
    stdin = tmp;

    // Выполняем тестируемую функцию
    int result = execute_command_interpreter();

    // Восстанавливаем stdin и закрываем файл
    stdin = saved_stdin;
    fclose(tmp);
    remove("mock_input.txt");

    // Проверяем утверждение
    assert(result == expected_result);
}

int main() {
    run_file_mock_test("copy", 1);
    run_file_mock_test("paste", 2);
    run_file_mock_test("unknown", 0);

    printf("Вариант 1 (Файловый Mock): Все тесты успешно пройдены!\n");
    return 0;
}
