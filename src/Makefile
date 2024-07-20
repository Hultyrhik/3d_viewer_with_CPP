
# ------------------------------- VARIABLES ------------------------------------------ #
PROJECT=3d_viewer_v2
WORK_DIR=frontend
CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++17 -g
LIBRARY_SOURCES=$(wildcard back/mvc/*.cc back/mvc/factory_adding/*.cc)
TEST_SOURCES=$(wildcard back/test/*.cc)
LDFLAGS=-lgtest -lgtest_main -lpthread
LIBS = $(PROJECT).a
COV_DIR = html_report

OBJ_LIBRARY = $(patsubst %.cc, %.o, $(LIBRARY_SOURCES))
TEST_OBJ = $(patsubst %.cc, %.o, $(TEST_SOURCES))

DIST_NAME = $(PROJECT)_$(shell date +%Y%m%d).tar.gz

# --------------------------------- TASKS -------------------------------------------- #
all: test

%.o: %.cс
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBS): $(OBJ_LIBRARY)
	@ar rcs $@ $^
	@ranlib $@

cat:
	@chmod +x cat.sh

test: $(LIBS) $(TEST_OBJ)
	@$(CC) $(CFLAGS) $(TEST_OBJ) $(LIBS) -o test.out $(LDFLAGS)
	@rm -f ./back/test/*.o ./back/mvc/*.o
	@./test.out > test_results.txt
	@if grep -q "PASSED" test_results.txt; then \
		./cat.sh "\033[0;32m  UNIT_TESTS PASSED: look test_results.txt  \033[0m" 10; \
	else \
		./cat.sh "\033[0;31m  UNIT_TESTS FAILED: look test_results.txt  \033[0m" 10; \
	fi

style-check:
	@clang-format -n -style=Google */*.h */*/*.h */*/*.cc */*.cpp
	@if [ $$? -eq 0 ]; then ./cat.sh "\033[0;32m  STYLE_TEST PASSED  \033[0m" 15; else ./cat.sh "\033[0;31m  STYLE_TEST FAILED ]\033[0m" 15; fi

style-i:
	@clang-format -i -style=Google */*.h */*/*.h */*/*.cc */*.cpp
	@if [ $$? -eq 0 ]; then ./cat.sh "\033[0;32m  STYLE IS C-LANG FORMATTED  \033[0m" 10; else ./cat.sh "\033[0;31m  STYLE_MAKE FAILED  \033[0m" 10; fi

valgrind: test
	@valgrind --tool=memcheck --leak-check=yes ./test.out 2>&1 | grep -E "ERROR SUMMARY:" > valgrind_summary.txt; \
	if [ $$? -eq 0 ]; then ./cat.sh "\033[0;32m  VALGRIND_TEST PASSED: look valgrind_summary.txt  \033[0m" 30; else ./cat.sh -r "\033[0;31m  VALGRIND_TEST FAILED: look valgrind_summary.txt  \033[0m" 30; cat valgrind_summary.txt; fi;

install:
	@./cat.sh "\033[34m===>    $(PROJECT) installation has started\033[0m" 10
	@chmod 0700 /run/user/1000/
	@rm -rf $(PROJECT) > /dev/null 2>&1
	@mkdir $(PROJECT) > /dev/null 2>&1
	@qmake $(PROJECT).pro -o $(PROJECT) > /dev/null 2>&1
	@cd $(PROJECT) && make > /dev/null 2>&1 & \
	pid=$$!; \
	while ps -p $$pid > /dev/null; do \
		echo -n "\033[34m.\033[0m"; \
		sleep 0.5; \
	done
	echo ""
	@./cat.sh "\033[34m===>    Installation has ended             \033[0m" 10
	@chmod +x ./$(PROJECT)/$(PROJECT) > /dev/null 2>&1
	@rm -f ${HOME}/$(PROJECT) && cp ./$(PROJECT)/$(PROJECT) ${HOME}/$(PROJECT)

run:
	${HOME}/$(PROJECT)

uninstall:
	-rm -rf ${HOME}/$(PROJECT)
	-rm -rf $(PROJECT)

clean: uninstall
	@rm -f */*.o *.a ../*.gz *.user *.conf *.info *.out *.log test_results.txt valgrind_summary.txt
	@rm -rf ./$(COV_DIR)
	@rm -rf ./docs
	@rm -rf ./html
	@rm -rf ./latex
	@rm -rf ./manual
	@rm -rf ../misc/gifs
	@rm -rf ../misc/imgs

dist: $(DIST_NAME)

$(DIST_NAME):
	@cd .. && tar -czf $(DIST_NAME) src
	@echo "Архив успешно создан: $(DIST_NAME)"

dvi:
	# sudo apt-get install texinfo
	@makeinfo ./manual.texi --html
	@if [ -e "gif/animation.gif" ]; then \
		cp gif/animation.gif ./manual/; \
		echo "<img src=\"animation.gif\" alt=\"Animation\">" >> ./manual/index.html; \
	else \
		echo "Файл animation.gif не найден в директории gif."; \
	fi
	@open ./manual/index.html
	@doxygen Doxyfile
