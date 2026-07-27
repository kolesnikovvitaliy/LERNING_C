# 1. Определение операционной системы
ifeq ($(OS),Windows_NT)
    # Настройки для Windows (MinGW/Cygwin/MSYS2)
    TARGET_EXT = .exe
    # Проверяем, запущен ли Make в окружении MSYS/Cygwin (где есть rm и mkdir)
    # Если запущен в обычном cmd.exe, используем встроенные команды Windows
    ifeq ($(SHELL),amd64.exe)
        FIX_PATH = $(subst /,\,$1)
        RM = del /Q /F
        RMDIR = rmdir /S /Q
        MKDIR = mkdir
    else ifeq ($(SHELL),cmd.exe)
        FIX_PATH = $(subst /,\,$1)
        RM = del /Q /F
        RMDIR = rmdir /S /Q
        MKDIR = mkdir
    else
        # Окружение со shell-эмуляцией (Cygwin, MSYS2, Git Bash)
        FIX_PATH = $1
        RM = rm -f
        RMDIR = rm -rf
        MKDIR = mkdir -p
    endif
else
    # Настройки для Linux / macOS
    TARGET_EXT =
    FIX_PATH = $1
    RM = rm -f
    RMDIR = rm -rf
    MKDIR = mkdir -p
endif

# Переменные компилятора и флагов
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -Iinclude
TARGET = my_logger$(TARGET_EXT)
MAIN_SRC = main.c
PREPROCESSED = main.i

# Утилита для сборки статических библиотек
AR = ar
ARFLAGS = rcs

# Папки проекта
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
INC_DIR = include

# Имя и путь к статической библиотеке
LIB_NAME = my_logger
STATIC_LIB = $(LIB_DIR)/lib_$(LIB_NAME).a

# Цвета для консоли (работают в Linux и современных терминалах Windows)
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0;0m
BLUE  = \033[34m
RED   = \033[0;31m

# Рекурсивный поиск файлов (функция rwildcard)
rwildcard = $(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

# Рекурсивный поиск всех исходников (.c) в папке src/
LIB_SRCS = $(call rwildcard,$(SRC_DIR),*.c)

# Рекурсивный поиск ВСЕХ заголовочных файлов (.h) в папке include/
LIB_HDRS = $(call rwildcard,$(INC_DIR),*.h)

# Автоматическое формирование путей для .o файлов в папке OBJ_DIR
LIB_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIB_SRCS))

.PHONY: all preprocess build run clean help

# Цель по умолчанию (цель test раскомментирована в списке, чтобы all работал без ошибок)
all: preprocess build run

# 1. Компиляция файлов библиотеки в .o с сохранением структуры папок
# Зависит как от .c файла, так и от всех заголовочных файлов .h
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIB_HDRS)
	@$(MKDIR) $(call FIX_PATH,$(dir $@))
	$(CC) $(CFLAGS) -c $< -o $@

# 2. Упаковка всех .o файлов в статическую библиотеку .a
$(STATIC_LIB): $(LIB_OBJS)
	@$(MKDIR) $(call FIX_PATH,$(LIB_DIR))
	@printf "$(YELLOW)Создание статической библиотеки $@...$(RESET)\n"
	$(AR) $(ARFLAGS) $@ $^
	@printf "$(GREEN)Библиотека успешно создана!$(RESET)\n"

# 3. Сборка финального файла: main.c + линковка с созданной .a библиотекой
# Программа пересоберется, если изменился main.c, библиотека или заголовки
build: $(MAIN_SRC) $(STATIC_LIB) $(LIB_HDRS)
	@printf  "\n$(YELLOW)Компиляция проекта с линковкой .a...$(RESET)\n"
	$(CC) $(CFLAGS) $(MAIN_SRC) -L$(LIB_DIR) -l$(LIB_NAME) -o $(TARGET)
	@printf  "$(GREEN)Проект успешно собран в файл: $(TARGET)$(RESET)\n"

# Запуск программы (работает кроссплатформенно через ./ префикс)
run: build
	@printf  "\n$(YELLOW)Запуск программы...$(RESET)\n"
	@printf  "$(BLUE)###################################$(RESET)\n"
	./$(TARGET)

# Препроцессинг (зависит от заголовков, так как макросы могут измениться)
preprocess: $(MAIN_SRC) $(LIB_HDRS)
	@printf  "$(YELLOW)Генерация файла после препроцессинга ...$(RESET)\n"
	$(CC) $(CFLAGS) -E $(MAIN_SRC) -o $(PREPROCESSED)
	@printf  "$(GREEN)Готово! Результат записан в $(PREPROCESSED)$(RESET)\n"

# Очистка
clean:
	@printf  "$(YELLOW)Очистка артефактов сборки...$(RESET)\n"
	$(RMDIR) $(OBJ_DIR)
	$(RMDIR) $(LIB_DIR)
	$(RM) $(TARGET)
	$(RM) $(PREPROCESSED)
	$(RM) output.txt
	$(RM) expected.txt
	@printf  "$(GREEN)Очистка завершена.$(RESET)\n"

# Справка
help:
	@printf  "Доступные команды Makefile:\n"
	@printf  "  make            - Препроцессинг, сборка .a, линковка и запуск\n"
	@printf  "  make build      - Собрать библиотеку .a и слинковать с $(TARGET)\n"
	@printf  "  make run        - Скомпилировать и запустить программу\n"
	@printf  "  make preprocess - Создать файл $(PREPROCESSED)\n"
	@printf  "  make clean      - Удалить бинарные, объектные, библиотечные и временные файлы\n"
