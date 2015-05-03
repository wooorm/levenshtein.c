TEST = test.c levenshtein.c
EXAMPLE = example.c levenshtein.c
OBJ_TEST = $(TEST:.c=.o)
OBJ_EXAMPLE = $(EXAMPLE:.c=.o)

CFLAGS = -D_GNU_SOURCE -std=c99

LFLAGS = -Wall -Wno-format-y2k -W -Wstrict-prototypes \
    -Wpointer-arith -Wreturn-type -Wcast-qual -Wwrite-strings -Wswitch \
    -Wshadow -Wcast-align -Wbad-function-cast -Wchar-subscripts -Winline \
    -Wnested-externs -Wredundant-decls

COVFLAGS = -Wall -fprofile-arcs -ftest-coverage

test: $(OBJ_TEST)
	$(CC) $(OBJ_TEST) -o $@

example: $(OBJ_EXAMPLE)
	$(CC) $(OBJ_EXAMPLE) -o $@

coverage: $(OBJ_TEST)
	gcc $(COVFLAGS) $(TEST) -o $@

.SUFFIXES: .c .o
.c.o:
	$(CC) $< $(CFLAGS) $(LFLAGS) -c -o $@

run-coverage: coverage
	./coverage && gcov levenshtein

run-test: test
	./test

run-example: example
	./example sitting kitten

clean:
	rm -f coverage test example $(OBJ_TEST) $(OBJ_EXAMPLE) *.gc{ov,da,no}

.PHONY: clean run-coverage run-test
