all: format_code_webfit_style doxygen

DOXYFILE = Doxyfile
DOC_DIR = doc/html/

clean:
	rm -rf $(DOC_DIR)

format_code_webfit_style:
	$(shell find . -iname "*.c" -o -iname "*.h" | xargs clang-format -i)

doxygen:
	doxygen $(DOXYFILE) > /dev/null 2>&1



.PHONY: all clean format_code_webfit_style doxygen
