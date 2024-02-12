# OS identification from: https://stackoverflow.com/questions/714100/os-detecting-makefile
OS := $(shell uname -s)

ifeq ($(OS), Darwin) 
  INCLUDE_PATH := /opt/homebrew/include
  LIB_PATH := /opt/homebrew/lib
endif
ifeq ($(OS), Linux) 
  INCLUDE_PATH := /util/criterion/include
  LIB_PATH := /util/criterion/lib/x86_64-linux-gnu
endif

CC := gcc
CFLAGS := -std=c11 -Wall -ggdb
CPPFLAGS := 

OBJECTS := code.o tests.o runner.o
EXECUTABLES := tests runner code

code.o: code.c code.h
	$(CC) $(CFLAGS) -c code.c

runner.o: runner.c
	$(CC) $(CFLAGS) -c runner.c

runner: code.o runner.o
	$(CC) $(CFLAGS) -o runner code.o runner.o

tests.o: tests.c code.h
	$(CC) $(CFLAGS) -I $(INCLUDE_PATH) -c tests.c

tests: tests.o code.o
	$(CC) $(CFLAGS) -L $(LIB_PATH) -I $(INCLUDE_PATH) -o tests $(OBJECTS) -lcriterion

clean:
	rm -f *~ $(OBJECTS) $(EXECUTABLES)
