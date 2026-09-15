# Makefile for Data Structures — Complete Algorithms
# Supports Unit 1, Unit 2, Unit 3, Unit 4, and Unit 5

CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11

UNIT1_SRCS = $(wildcard unit1_arrays_linked_lists/*.c)
UNIT1_EXES = $(UNIT1_SRCS:.c=.exe)

UNIT2_SRCS = $(wildcard unit2_stacks_queues/*.c)
UNIT2_EXES = $(UNIT2_SRCS:.c=.exe)

UNIT3_SRCS = $(wildcard unit3_searching_hashing_sorting/*.c)
UNIT3_EXES = $(UNIT3_SRCS:.c=.exe)

UNIT4_SRCS = $(wildcard unit4_trees/*.c)
UNIT4_EXES = $(UNIT4_SRCS:.c=.exe)

UNIT5_SRCS = $(wildcard unit5_graphs/*.c)
UNIT5_EXES = $(UNIT5_SRCS:.c=.exe)

ALL_EXES = $(UNIT1_EXES) $(UNIT2_EXES) $(UNIT3_EXES) $(UNIT4_EXES) $(UNIT5_EXES)

.PHONY: all unit1 unit2 unit3 unit4 unit5 clean test

all: unit1 unit2 unit3 unit4 unit5

unit1: $(UNIT1_EXES)

unit2: $(UNIT2_EXES)

unit3: $(UNIT3_EXES)

unit4: $(UNIT4_EXES)

unit5: $(UNIT5_EXES)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

test: all
	@echo Running Unit 1 Tests...
	@for exe in $(UNIT1_EXES); do ./$$exe; done
	@echo Running Unit 2 Tests...
	@for exe in $(UNIT2_EXES); do ./$$exe; done
	@echo Running Unit 3 Tests...
	@for exe in $(UNIT3_EXES); do ./$$exe; done
	@echo Running Unit 4 Tests...
	@for exe in $(UNIT4_EXES); do ./$$exe; done
	@echo Running Unit 5 Tests...
	@for exe in $(UNIT5_EXES); do ./$$exe; done
	@echo All Tests Completed Successfully!

clean:
	rm -f unit1_arrays_linked_lists/*.exe
	rm -f unit2_stacks_queues/*.exe
	rm -f unit3_searching_hashing_sorting/*.exe
	rm -f unit4_trees/*.exe
	rm -f unit5_graphs/*.exe
