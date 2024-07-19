GCC = g++
CFLAGS = -Wall -Werror -Wextra

WORK_DIR=frontend
INST_DIR=frontend/3DViewer-v2.0
TESTFILE = back/test/3DViewer-v2.0

PROJECT_NAME= 3DViewer-v2.0

SRC_FILES = $(wildcard back/mvc/s21*.cc)
HEADER_FILES = $(wildcard back/mvc/s21*.h)
TEST_FILES = $(wildcard back/test/*.cc)

LEAK_PROGRAMM = valgrind

OS = $(shell uname -s)

ifeq ($(OS), Linux)
	LIBS_OS_CHECK = -lcheck -lsubunit -lm -lpthread -lrt
	OSLINUX = 1
else
	LIBS_OS_CHECK = -lcheck -lm -lpthread
	OSLINUX = 0
	LEAK_PROGRAMM = leaks -atExit --
endif

all: gcov_report install dvi run

tests: clean
	g++ -Wall -g -pthread $(CFLAGS) $(HEADER_FILES) $(SRC_FILES) $(TEST_FILES) -lgtest_main  -lgtest -lpthread -o test
	./test


clean: uninstall
	-rm -rf *.txt back/test/*.o back/test/*.gcno back/test/*.gcda back/test/*.c back/test/*.info
	-rm -rf back/test/test_back_shape_test back/test/test_corrie_test
	-rm -rf frontend/*.o frontend/ui_mainwindow.h frontend/*.stash frontend/Makefile
	-rm -rf report
	-rm -rf *.tar *.tgz *.conf ./a.out *.log
	-rm -rf manual *test* s21_3dparser.o $(PROJECT_NAME)
	-rm -rf frontend/build-frontend* frontend/3DViewer-v1.0
	-rm -rf ../misc/gif/ ../misc/img/

install:
	@echo "\033[34m===>    Installation has started     <===\033[0m"
	cd $(WORK_DIR) && exec qmake $(WORK_DIR).pro
	cd $(WORK_DIR) && exec make 
	@echo ""
	@echo "\033[34m===>    Installation has ended       <===\033[0m"
	cd $(WORK_DIR) && exec make clean > /dev/null 2>&1
	cd $(WORK_DIR) && exec rm -rf Makefile > /dev/null 2>&1
	cd $(WORK_DIR) && exec rm -rf .qmake.stash > /dev/null 2>&1
	if [ ! -d "$(INST_DIR)" ]; then \
		mkdir $(INST_DIR); \
	fi
	cd $(WORK_DIR) && exec mv frontend 3DViewer-v1.0/s21_3Dviewer_v1  > /dev/null 2>&1

run:
	cd $(INST_DIR) &&	./s21_3Dviewer_v1

uninstall:
	if [ -e "manual/animation.gif" ]; then \
		mv manual/animation.gif ./gif/; \
	else \
		echo "Файл animation.gif не найден в директории manual."; \
	fi
	-rm -rf $(INST_DIR)
	-rm -rf ./manual/


leak_test: clean tests
	$(LEAK_PROGRAMM) back/test/test_back_shape_test
	$(LEAK_PROGRAMM) back/test/test_corrie_test


dvi:
	# sudo apt-get install texinfo
	makeinfo ./manual.texi --html
	if [ -e "gif/animation.gif" ]; then \
		mv gif/animation.gif ./manual/; \
		echo "<img src=\"animation.gif\" alt=\"Animation\">" >> ./manual/index.html; \
	else \
		echo "Файл animation.gif не найден в директории gif."; \
	fi
	open ./manual/index.html


dist:
	mkdir $(PROJECT_NAME)
	cp Makefile manual.texi $(PROJECT_NAME)
	cp -r frontend back  gif $(PROJECT_NAME)
	tar cvzf $(PROJECT_NAME).tgz $(PROJECT_NAME)
	rm -rf $(PROJECT_NAME)
