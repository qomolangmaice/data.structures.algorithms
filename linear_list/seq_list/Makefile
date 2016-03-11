

CC = gcc

#SOURCE = $(wildcard *.c)

all:
	$(CC) -o main main.c

debug:
	$(CC) -g -o main main.c

merge:
	$(CC) -o merge merge_list.c

count_line:
	find . -type f -name "*.[c|h]" -exec cat {} \; | wc -l
