#include <stdio.h>


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    int var = 1;

    int *int_ptr_var = NULL;
    int_ptr_var = &var;

    char *char_ptr_var = NULL;
    char_ptr_var = (char*)&var;

    printf("\nBefore arithmetic: int_ptr_var: %u, char_ptr_var: %u\n", (unsigned int)int_ptr_var, (unsigned int)char_ptr_var);

    int_ptr_var++; // Арифметический шаг обычно равен 4 в зависисмости от архитектуры;
    char_ptr_var++; // Арифметический шаг равен 1 байту;

    printf("After arithmetic: int_ptr_var: %u, char_ptr_var: %u\n\n", (unsigned int)int_ptr_var, (unsigned int)char_ptr_var);
    return 0;
}
