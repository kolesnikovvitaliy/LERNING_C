# Переменные компилятора и флагов
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = lab_program
SRC = main.c
PREPROCESSED = main.i

# Названия цветов для красивого вывода в консоль
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0;0m

.PHONY: all build run preprocess clean test help

# Цель по умолчанию (вызывается просто по команде make)
all: build test

# Сборка исполняемого файла
build: $(SRC)
	@printf  "$(YELLOW)Компиляция проекта...$(RESET)\n"
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
	@printf  "$(GREEN)Проект успешно собран в файл: $(TARGET)$(RESET)\n"

# Запуск программы в интерактивном режиме
run: build
	@printf  "$(YELLOW)Запуск программы...$(RESET)\n"
	./$(TARGET)

# Генерация вывода препроцессора (для Проверочной работы №1)
preprocess: $(SRC)
	@printf  "$(YELLOW)Генерация файла после препроцессинга (развёртывание макросов)...$(RESET)\n"
	$(CC) -E $(SRC) -o $(PREPROCESSED)
	@printf  "$(GREEN)Готово! Результат записан в $(PREPROCESSED)$(RESET\n)"

# Автоматический запуск тестов и валидация вывода программы
test: build
	@printf  "$(YELLOW)Запуск автоматического тестирования вывода...$(RESET)\n"
	@./$(TARGET) > output.txt
	@echo -e "1\n2\n3\n4\n5\n6\n7\n8\n9\n10" > expected.txt
	@diff -u expected.txt output.txt && \
		(printf  "$(GREEN)[PASS] Тест пройден успешно! Вывод программы совпадает с ожидаемым (1..10).$(RESET)\n"; rm -f output.txt expected.txt) || \
		(printf  "\033[0;31m[FAIL] Тест провален! Вывод программы не совпадает со стандартом.$(RESET)\n"; rm -f output.txt expected.txt; exit 1)

# Очистка всех сгенерированных файлов
clean:
	@printf  "$(YELLOW)Очистка артефактов сборки...$(RESET)\n"
	rm -f $(TARGET) $(PREPROCESSED) output.txt expected.txt
	@printf  "$(GREEN)Очистка завершена.$(RESET)\n"

# Справка по доступным командам
help:
	@printf  "Доступные команды Makefile:\n"
	@printf  "  make            - Собрать проект и запустить тесты (по умолчанию)\n"
	@printf  "  make build      - Скомпилировать исполняемый файл $(TARGET)\n"
	@printf  "  make run        - Скомпилировать и запустить программу\n"
	@printf  "  make test       - Проверить корректность вывода программы (дифф с эталоном)\n"
	@printf  "  make preprocess - Создать файл $(PREPROCESSED) с развёрнутыми макросами\n"
	@printf  "  make clean      - Удалить бинарные и временные файлы\n"
