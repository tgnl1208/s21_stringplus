CC=gcc
FLAGS=-Wall -Wextra -Werror -std=c11
CHECK_FLAGS_LINUX=-lcheck -lsubunit -lrt -lpthread -lm
CHECK_FLAGS_MAC=-lcheck

OS := $(shell uname -s)

SOURCE = s21_string.c s21_sprintf.c
OBJECTS = s21_string.o

all: s21_string.a

test: s21_string.a
ifeq ($(OS), Darwin)
	$(CC) $(FLAGS) s21_tests.c s21_string.a -o s21_tests $(CHECK_FLAGS_MAC)
	./s21_tests
else
	$(CC) $(FLAGS) s21_tests.c s21_string.a -o s21_tests $(CHECK_FLAGS_LINUX)
	./s21_tests
endif

s21_string.a: clean
	$(CC) -c $(FLAGS) $(SOURCE) -lm
	ar rcs s21_string.a *.o
	ranlib s21_string.a

valgrind: s21_string.a
	$(CC) $(FLAGS) s21_tests.c s21_string.a -o s21_tests $(CHECK_FLAGS_LINUX)
	valgrind --tool=memcheck --leak-check=yes  ./s21_tests

gcov_report: clean
ifeq ($(OS), Darwin)
	$(CC) -fprofile-arcs -ftest-coverage -fPIC -O0 s21_tests.c s21_string.c s21_sprintf.c -o s21_tests $(CHECK_FLAGS_MAC)
else
	$(CC) -fprofile-arcs -ftest-coverage -fPIC -O0 s21_tests.c s21_string.c s21_sprintf.c -o s21_tests $(CHECK_FLAGS_LINUX)
endif
	./s21_tests
	~/.local/bin/gcovr -r . --exclude-unreachable-branches --html-details -o gcov_report.html
	firefox gcov_report.html

clean:
	rm -f *.o *.a s21_tests *.gcno *.gcda
	rm -f *.css *.html