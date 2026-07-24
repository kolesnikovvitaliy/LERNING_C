#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <string.h>
#include "cmocka.h"

// Объявляем тестируемую функцию
int execute_command_interpreter(void);

// Безопасный Mock для scanf
int __wrap_scanf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Извлекаем указатель на массив cmd, переданный в scanf
    char *out_str = va_arg(args, char *);

    // Берём строку из очереди will_return
    const char *mocked_input = mock_type(const char *);

    // Безопасно копируем данные
    strcpy(out_str, mocked_input);

    va_end(args);
    return 1; // Имитируем успешное чтение одного аргумента
}

static void test_copy_command(void **state) {
    (void) state;

    will_return(__wrap_scanf, "copy"); // Передаем "copy"

    int result = execute_command_interpreter();
    assert_int_equal(result, 1);       // Ожидаем 1
}

static void test_cut_command(void **state) {
    (void) state;

    will_return(__wrap_scanf, "cut");  // Исправлено: передаем "cut" вместо "paste"

    int result = execute_command_interpreter();
    assert_int_equal(result, 3);       // Ожидаем 3
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_copy_command),
        cmocka_unit_test(test_cut_command),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
