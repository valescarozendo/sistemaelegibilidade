CC      = gcc
CFLAGS  = -std=c99 -Wall -Wextra -Wpedantic -Werror -O2

all: elegibilidade test_elegibilidade

elegibilidade: main.c elegibilidade.c elegibilidade.h
	$(CC) $(CFLAGS) main.c elegibilidade.c -o elegibilidade

test_elegibilidade: test_elegibilidade.c elegibilidade.c elegibilidade.h
	$(CC) $(CFLAGS) test_elegibilidade.c elegibilidade.c -o test_elegibilidade

test: test_elegibilidade
	./test_elegibilidade

run: elegibilidade
	./elegibilidade

clean:
	rm -f elegibilidade test_elegibilidade

.PHONY: all test run clean