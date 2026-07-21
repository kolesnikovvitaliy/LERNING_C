all: doxygen

DOXYFILE = Doxyfile
DOC_DIR = doc/html/

doxygen:
	doxygen $(DOXYFILE) > /dev/null 2>&1



.PHONY: doxygen
