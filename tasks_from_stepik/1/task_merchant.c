#include <stdio.h>
#define ARRAY_SIZE 100

int assign_initial_coins(int*, int*);
int is_coins_even(int, int);
//######################################################
int
main()
{
    int list_of_employees[ARRAY_SIZE];
    int result_coin, number_of_employees, i, flag=0;

    scanf("%d", &number_of_employees);

    assign_initial_coins(
        list_of_employees,
        &number_of_employees
    );

    /*
    Он поставил всех работников в круг. Затем у каждой пары работников он брал деньги и складывал. Если             число монет двух работников нечетное, то одну монету купец забирал себе, а остальное поровну делил             между     этими двумя работниками. Купец начинал круг с пары 1-2, затем 2-3, ... и заканчивал круг         парой последний     и первый работник.
    */

    for (i=0; i < number_of_employees; i++) {
        if ((i+1) == number_of_employees) {
            if (is_coins_even(list_of_employees[i], list_of_employees[0])) {
                printf("is_coins_even I = %d\tI+1 = %d\r\n", i, 0);
            } else {
                result_coin = list_of_employees[i]  list_of_employees[0]
            break;
        }
        if (is_coins_even(list_of_employees[i], list_of_employees[i+1])) {
                printf("is_coins_even I = %d\tI+1 = %d\r\n", i, i+1);
            }
    }


    return 0;
}
//#####################################################
//-----------------------------------------------------
int
assign_initial_coins(int *list_of_employees, int *number_of_employees)
{
    // init_coins_for_employees

    int size_list, start_coins=0;

    size_list = *number_of_employees;

    for (int i=0; i < size_list; i++) {
        scanf("%d", &start_coins);
        list_of_employees[i] = start_coins;
    }
    return 0;
}
//-----------------------------------------------------
int
is_coins_even(int coins1, int coins2)
{
    return !((coins1 + coins2) & 1);
}

