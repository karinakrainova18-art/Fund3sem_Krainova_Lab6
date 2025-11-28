CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = brackets_checker
TEST_TARGET = bracket_tests

SRCS = brackets_main.c brackets.c
TEST_SRCS = tests.c brackets.c

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_SRCS)
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all test clean