CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = src/string.c src/strview.c src/error.c
OBJ = $(SRC:.c=.o)

EXAMPLE_DIR = build/examples

examples: string_example strview_example

string_example: $(OBJ) examples/string.c
	@mkdir -p $(EXAMPLE_DIR)
	$(CC) $(CFLAGS) $(OBJ) examples/string.c \
		-o $(EXAMPLE_DIR)/string

strview_example: $(OBJ) examples/strview.c
	@mkdir -p $(EXAMPLE_DIR)
	$(CC) $(CFLAGS) $(OBJ) examples/strview.c \
		-o $(EXAMPLE_DIR)/strview

run-examples: examples
	@echo "=== STRING EXAMPLE ==="
	@./$(EXAMPLE_DIR)/string

	@echo ""
	@echo "=== STRVIEW EXAMPLE ==="
	@./$(EXAMPLE_DIR)/strview

TEST_SRC = \
	tests/main.c \
	tests/string/* \
	tests/strview/* \

TEST_EXE = tests_runner

all: $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

tests: $(OBJ) $(TEST_SRC)
	$(CC) $(CFLAGS) $(OBJ) $(TEST_SRC) -o $(TEST_EXE)

test: tests
	./$(TEST_EXE)

format:
	find src include tests examples \
	\( -name "*.c" -o -name "*.h" \) \
	-exec clang-format -i {} \;

format-check:
	@find src include tests examples \
	\( -name "*.c" -o -name "*.h" \) \
	-exec clang-format --dry-run --Werror {} \;

BENCH_SRC = \
	bench/main.c \
	bench/string_bench.c \
	bench/strview_bench.c

BENCH_EXE = bench_runner

$(BENCH_EXE): $(OBJ) $(BENCH_SRC)
	$(CC) $(CFLAGS) $(OBJ) $(BENCH_SRC) -o $(BENCH_EXE)

bench: $(BENCH_EXE)
	./$(BENCH_EXE)

clean:
	rm -f $(OBJ)
	rm -f $(EXAMPLE_EXE)
	rm -f $(TEST_EXE)