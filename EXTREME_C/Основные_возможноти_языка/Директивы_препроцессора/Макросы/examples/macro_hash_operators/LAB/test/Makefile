# Настройки компилятора
CC = gcc
# --coverage включает генерацию профилей для gcov
CFLAGS = -Wall -Wextra -Isrc -O0 -g --coverage -DTESTING -fno-builtin

# Флаги линтовщика (добавлена --coverage для сборки исполняемого файла)
LDFLAGS = -lcmocka -Wl,--wrap=scanf --coverage

# Пути
SRC_DIR = src
TEST_DIR = test
OBJ_DIR = obj
REPORT_DIR = coverage_report

SRC = $(SRC_DIR)/interpreter.c
TEST_SRC = $(TEST_DIR)/test_cmocka.c
OBJS = $(OBJ_DIR)/interpreter.o $(OBJ_DIR)/test_cmocka.o

TARGET = run_cmocka_tests

# 1. Запуск тестов по умолчанию
all: $(TARGET)
	@echo "Running CMocka Tests..."
	@./$(TARGET)

# 2. Главная цель для генерации HTML-отчета
coverage: all
	@echo "Generating Code Coverage Report..."
	@mkdir -p $(REPORT_DIR)
	# Собираем данные gcov в один файл coverage.info
	lcov --capture --directory $(OBJ_DIR) --output-file $(REPORT_DIR)/coverage.info --rc lcov_branch_coverage=1
	# (Опционально) Исключаем файлы тестов из финального отчета, чтобы видеть только покрытие src/
	lcov --remove $(REPORT_DIR)/coverage.info '*/test/*' --output-file $(REPORT_DIR)/coverage.info --rc lcov_branch_coverage=1
	# Генерируем HTML-страницы из файла .info
	genhtml $(REPORT_DIR)/coverage.info --output-directory $(REPORT_DIR)/html --rc lcov_branch_coverage=1
	@echo "Done! Report is available at: $(REPORT_DIR)/html/index.html"

# Сборка исполняемого файла
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

# Компиляция c сохранением файлов счетчиков (.gcno) в папку obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Полная очистка, включая отчеты и файлы покрытия (.gcda, .gcno)
clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(REPORT_DIR)

.PHONY: all clean coverage
