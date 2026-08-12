#include <stdio.h>
#include <stddef.h>

void demonstrate_pointer_dereference(void)
{
    int var = 100;
    int *ptr = NULL;

    printf("--- 1. Начальное состояние ---\n");
    printf("Значение var: %d\n", var);
    printf("Адрес var в памяти (&var): %p\n", (void*)&var);
    printf("Значение ptr до инициализации: %p\n\n", (void*)ptr);

    // Связываем указатель с переменной (записываем адрес var в ptr)
    ptr = &var;

    printf("--- 2. После ptr = &var ---\n");
    printf("Куда указывает ptr (значение ptr): %p\n", (void*)ptr);
    printf("Значение, на которое указывает ptr (*ptr): %d\n\n", *ptr);

    // Меняем значение в памяти через указатель (разыменование)
    *ptr = 200;

    printf("--- 3. После *ptr = 200 ---\n");
    printf("Новое значение var: %d\n", var);
    printf("Значение через *ptr: %d\n", *ptr);
}

int main(int argc, char **argv)
{
    // Подавление предупреждений компилятора о неиспользуемых переменных
    (void)argc;
    (void)argv;

    demonstrate_pointer_dereference();
    return 0;
}
