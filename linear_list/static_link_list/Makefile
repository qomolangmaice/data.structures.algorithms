CC = gcc

all:
	$(CC) -o main main.c

debug:
	$(CC) -g -gdwarf-2 -gstrict-dwarf -o main main.c

insight:
	make debug
	/usr/local/insight/bin/insight main

count:
	find . -type f -name "*.[c|h]" -exec cat {} \; | wc -l 

clean:
	rm main 
