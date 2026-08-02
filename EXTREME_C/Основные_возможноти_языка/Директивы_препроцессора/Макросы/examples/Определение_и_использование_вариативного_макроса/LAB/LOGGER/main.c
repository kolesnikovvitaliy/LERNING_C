#include <my_logger.h>

#include <assert.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int set_debug_mode(int argc, char **argv);

//##################################################################################
int main(int argc, char **argv) {

  set_debug_mode(argc, argv);

#ifdef _WIN32
  SetConsoleOutputCP(65001); // Для Windows
#else
  setlocale(LC_ALL, "Russian");
#endif
#ifdef DEBUG
  DEBUG_LOG("SYSTEM LOGGINGS ACTIVATED :) !!! \n\n", "");
#endif
  PRINT_RESULT("PRINT_RESULT          Основная работа программы. :) !!! \n\n","");
  //
  NONE_LOG("NONE_LOG          Основная работа программы. !!! \n\n", "");
  //
  ERROR_LOG("Основная работа программы. !!! \n\n", "");
  INFO_LOG("Основная работа программы. !!! \n\n", "");
  WARNING_LOG("Основная работа программы. !!! \n\n", "");
  TRACE_LOG("Основная работа программы. !!! \n\n", "");
  //
  printf("printf          Основная работа программы. !!! \n\n");

  return 0;
}
//##################################################################################

//----------------------------------------------------------------
int set_debug_mode(int argc, char **argv)
{
  if (argv == NULL || argc < 1) {
        return 0;
    }
    for (int i = 0; i < argc; i++) {
        if (strcmp("-d", argv[i]) == 0) {
          log_level_t log_level = set_log_level(DEBUG_LOG);
          (void)log_level;
            return 0;
        }
    }
    return 0;
}
//----------------------------------------------------------------
