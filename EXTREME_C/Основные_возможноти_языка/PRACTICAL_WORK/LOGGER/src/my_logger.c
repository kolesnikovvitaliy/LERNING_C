/**
 * @file logger.c
 * @brief Реализация модуля логирования для вывода цветных диагностических
 * сообщений.
 * @details Данный файл содержит функции для управления уровнями логирования,
 * форматированного вывода сообщений в консоль с использованием ANSI-цветов
 * и фильтрации вывода по текущему установленному порогу важности.
 *
 * @author Ваше Имя
 * @date 2026-06-08
 * @version 1.0
 */

#include <my_logger.h>

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

/**
 * @brief Текущий глобальный уровень логирования в системе.
 * @details Все сообщения с уровнем строго выше, чем @p current_log_level,
 * будут автоматически игнорироваться функцией log_message().
 */

log_level_t current_log_level = LOGGER_STATUS;


/**
 * @brief Выводит форматированное сообщение в консоль с учетом уровня
 * логирования.
 *
 * @details Функция проверяет приоритет сообщения. Если он проходит проверку,
 * формируется строка вывода: добавляется временная метка (опционально
 * раскомментируется), текстовое обозначение уровня и цветовой ANSI-код.
 * Поддерживается стандартный синтаксис форматирования `printf`.
 *
 * @param[in] level Уровень важности сообщения (например, ERROR, INFO, DEBUG).
 * @param[in] fmtСтрока форматирования в стиле printf.
 * @param[in] ... Переменное число аргументов, соответствующих строке
 * форматирования.
 *
 * @note Если @p level равен `0` (NONE), сообщение не выводится.
 * @warning Функция не является потокобезопасной (thread-safe), так как
 * использует `static` или глобальные вызовы `printf`.
 */
// void log_message(log_level_t level, const char *fmt, ...) {
void log_message(log_level_t level, const char* file, int line, const char* func, const char* fmt, ...) {
  /** Текстовые представления доступных уровней логирования. */
  const char *levels[] = {"NONE_LOG", "PRINT_RESULT", "ERROR_LOG",    "INFO_LOG",
                          "WARNING_LOG", "TRACE_LOG", "DEBUG_LOG"};

  /** ANSI цветовые коды для визуального разделения уровней в консоли. */
  const char *level_colors[] = {CLR_NONE_LOG, CLR_PRINT_RESULT, CLR_ERROR_LOG,
                                CLR_INFO_LOG, CLR_WARNING_LOG,      CLR_TRACE_LOG,
                                CLR_DEBUG_LOG};
  // Выбираем один поток для всей строки (например, stderr для логов, stdout для результатов)
  FILE* stream = (level == 1) ? stdout : stderr;

  // Если уровень сообщения выше текущего
  // порога, игнорируем его
  if (level > current_log_level) {
    return;
  }
  // Получение текущего времени
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  char time_str[20];
  char date_str[20];
  strftime(time_str, sizeof(time_str), "%H:%M:%S", t);
  strftime(date_str, sizeof(date_str), "%D", t);


  if (level != 0) {
    if (level == 1) {
      fprintf(stream, "%s", level_colors[level]);
    } else {
      fprintf(stream, "%s[%s] [%s] [%s] [%s:%d] %s() --> ", level_colors[level],
               levels[level], date_str, time_str, file, line, func);
      perror(NULL);

    }
  }

  // Обработка переменного числа аргументов
  va_list args;
  va_start(args, fmt);
  vfprintf(stream, fmt, args);
  va_end(args);
  printf(CLR_RESET "");
  return;
}

/**
 * @brief Изменяет глобальный порог фильтрации логов.
 *
 * @details Позволяет динамически переключать детализацию вывода приложения
 * прямо во время его работы.
 *
 * @param[in] level Новый целевой уровень логирования (тип #log_level_t).
 * @return log_level_t Предыдущее значение уровня логирования до вызова
 * функции.
 *
 * @code
 * // Пример временного включения режима отладки:
 * log_level_t prev = set_log_level(DEBUG);
 * log_message(DEBUG, "Поиск сложного бага...");
 * set_log_level(prev); // Возврат к старому режиму
 * @endcode
 */
log_level_t set_log_level(log_level_t level) {
  // Установка нового порогового и возврат
  // предыдущего значения logger;
  log_level_t old_level = current_log_level;
  current_log_level = level;
  return old_level;
}
