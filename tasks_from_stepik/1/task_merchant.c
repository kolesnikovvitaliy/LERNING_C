#include <stdio.h>
#define ARRAY_SIZE 100

int assign_initial_coins(int*, int*); // Инициализация баланса монет сотрудников
int is_coin_sum_even(int*, int, int);// Проверка на четность
    // суммы монет очередных двоих сотрудников
int get_employee_coins(int*, int); // Получение количества монет на балансе сотрудника
int has_equal_coins(int*, int*); // Проверка равенства монет на балансах всех сотрудников
int sum_employee_coins(int*, int, int); // Получение суммы монет
    // очередных двоих сотрудников
void set_employee_coins(int*, int, int); // Установка новых занчений баланса двоим сотрудникам
void run(int*, int*, int*, int*); // Основной рабочий цикл программы,
    // проверка исполнения всех условий
//######################################################
int
main()
{
    int list_of_employees[ARRAY_SIZE];
    int merchant_profit;
    int coins_per_employee;
    int number_of_employees;

    merchant_profit = 0;
    coins_per_employee = 0;
    number_of_employees = 0;


    scanf("%d", &number_of_employees);

    assign_initial_coins(
        list_of_employees,
        &number_of_employees
    );

   run(list_of_employees,
       &number_of_employees,
       &merchant_profit,
       &coins_per_employee
   );

   printf("%d %d\n", merchant_profit, coins_per_employee);

   return 0;
}
//#####################################################
//-----------------------------------------------------
int
assign_initial_coins(int *list_of_employees, int *number_of_employees)
{
    // Инициализация баланса монет сотрудников

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
is_coin_sum_even(int *list_of_employees,
                  int employee_index_1,
                  int employee_index_2)
{
    // Проверка на четность
    // суммы монет очередных двоих сотрудников

    int sum_coins=0;

    sum_coins = sum_employee_coins(list_of_employees,
                                   employee_index_1,
                                   employee_index_2);
    return !(sum_coins & 1);
}
//------------------------------------------------------
int
get_employee_coins(int *list_of_employees, int employee_index)
{
    // Получение количества монет на балансе сотрудника
    return list_of_employees[employee_index];
}
//------------------------------------------------------
int
has_equal_coins(int *list_of_employees, int *number_of_employees)
{
    // Проверка равенства монет на балансах всех сотрудников
    int size_list;

    size_list = *number_of_employees;

    for (int i=0; i < size_list; i++) {
        if (list_of_employees[i] != list_of_employees[0]) {
            return 0;
        }
    }
        return 1;
}
//------------------------------------------------------
int sum_employee_coins(int *list_of_employees,
                       int employee_index_1,
                       int employee_index_2)
{
    // Получение суммы монет
    // очередных двоих сотрудников
    int employee_1_balance, employee_2_balance, sum_coins=0;

    employee_1_balance = get_employee_coins(list_of_employees,
                                            employee_index_1);

    employee_2_balance = get_employee_coins(list_of_employees,
                                            employee_index_2);

    sum_coins = employee_1_balance + employee_2_balance;

    return sum_coins;
}
//--------------------------------------------------------------
void set_employee_coins(int *list_of_employees,
                       int employee_index_1,
                       int employee_index_2)
{
    // Установка новых занчений баланса двоим сотрудникам
    int sum_coins=0;
    sum_coins = sum_employee_coins(list_of_employees,
                                   employee_index_1,
                                   employee_index_2);
    sum_coins >>= 1; // Деление нацело на 2 (с округлением вниз)
    /* Записывание значения методом индексации */
    list_of_employees[employee_index_1] = sum_coins;
    /* Записывание значения с помощью адресой арифметики */
    *(list_of_employees + employee_index_2) = sum_coins;
}
//--------------------------------------------------------------
void run(int *list_of_employees,
         int *number_of_employees,
         int *merchant_profit,
         int *coins_per_employee)
{    // Основной рабочий цикл программы, проверка исполнения всех условий
    while (!has_equal_coins(list_of_employees, number_of_employees)) {
        // Цикл while ожидает пока все значения балансов сотрудников не уравняются
        for (int i=0; i < *number_of_employees; i++) {
            if (!is_coin_sum_even(list_of_employees, i, (i % (*number_of_employees-1)) +1)) {
                // Проверяется на равенство банасов очередных двоих сотрудников
               (*merchant_profit)++; // При не равенстве баланс работодателя увеличивается
                set_employee_coins(list_of_employees, i, (i % (*number_of_employees-1))+1);
                continue;
            }
            // Устанавливаются новые значения балансов выбранных сотрудников
            set_employee_coins(list_of_employees, i, (i % (*number_of_employees-1))+1);
        }
    }
    *coins_per_employee = list_of_employees[0]; // Определение значения балансов всех сотрудников
}
