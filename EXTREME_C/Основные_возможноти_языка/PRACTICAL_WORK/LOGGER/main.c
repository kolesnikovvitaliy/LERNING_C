#include <my_logger.h>

#include <assert.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

#ifdef _WIN32
  SetConsoleOutputCP(65001); // Для Windows
#else
  setlocale(LC_ALL, "Russian");
#endif
#ifdef DEBUG
  DEBUG_LOG("SYSTEM LOGGINGS ACTIVATED :) !!! \n\n", "");
#endif
  PRINT_RESULT("PRINT_RESULT          Основная работа программы. :) !!! \n\n",
               "");
  NONE("NONE          Основная работа программы. !!! \n\n", "");
  ERROR("Основная работа программы. !!! \n\n", "");
  INFO("Основная работа программы. !!! \n\n", "");
  WARNING("Основная работа программы. !!! \n\n", "");
  TRACE("Основная работа программы. !!! \n\n", "");
  printf("printf          Основная работа программы. !!! \n\n");

  return 0;
}
