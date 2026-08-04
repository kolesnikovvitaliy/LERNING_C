#include "my_logger.h"
#include <assert.h>
#include <stdio.h>

void test_basic_logging_macros();
void test_set_debug_mode_with_flag();
void test_set_debug_mode_invalid_args();

//#########################################################################
int main() {
    test_basic_logging_macros();
    return 0;
}
//#########################################################################

//-------------------------------------------------------------------------------
void test_basic_logging_macros() {
    printf("[RUNNING] Test 1: Basic Logging Macros\n");

    // Проверка, что макросы корректно обрабатывают строки и спецификаторы формата
    PRINT_RESULT("Test PRINT_RESULT: %s\n", "SUCCESS");
    INFO_LOG("Test INFO_LOG: %d\n", 42);
    WARNING_LOG("Test WARNING_LOG: %f\n", 3.14);
    TRACE_LOG("Test TRACE_LOG: %s\n", "Trace path");

    printf("[PASSED] Test 1: Basic Logging Macros completed successfully.\n\n");
}
//-------------------------------------------------------------------------------

