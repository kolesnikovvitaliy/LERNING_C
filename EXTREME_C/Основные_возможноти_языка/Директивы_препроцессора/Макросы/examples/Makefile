# Имя вашего исходного файла
SRC = demo_macro_substitution_in_main.c

# Имя исполняемого файла (опционально)
TARGET = demo

# Имя конфигурационного файла Doxygen
DOXYFILE = Doxyfile

.PHONY: all preprocess doc clean

# По умолчанию выводим препроцессор и собираем PDF
all: preprocess doc

# 1. Вывод кода после препроцессора прямо в консоль
preprocess:
	@echo "===================================================="
	@echo "   ИСХОДНЫЙ КОД ПОСЛЕ РАБОТЫ ПРЕПРОЦЕССОРА (E)      "
	@echo "===================================================="
	@gcc -E $(SRC) | grep -v '^#' | sed '/^[[:space:]]*$$/d'
	@echo "===================================================="

# 2. Генерация Doxygen-документации и сборка в PDF
doc:
	@echo "Генерация конфигурации Doxygen..."
	@doxygen -g $(DOXYFILE) > /dev/null 2>&1 || true
	@# Настройка Doxyfile для генерации LaTeX/PDF и поддержки русского языка
	@sed -i 's/^OUTPUT_LANGUAGE.*/OUTPUT_LANGUAGE = Russian/' $(DOXYFILE)
	@sed -i 's/^GENERATE_LATEX.*/GENERATE_LATEX = YES/' $(DOXYFILE)
	@sed -i 's/^USE_PDFLATEX.*/USE_PDFLATEX = YES/' $(DOXYFILE)
	@echo "Запуск Doxygen..."
	@doxygen $(DOXYFILE)
	@echo "Компиляция LaTeX в PDF..."
	@$(MAKE) -C latex > /dev/null
	@cp latex/refman.pdf ./documentation.pdf
	@echo "👉 Документация успешно сохранена в файл: ./documentation.pdf"

# Очистка временных файлов
clean:
	rm -rf latex html $(DOXYFILE) $(TARGET) documentation.pdf
