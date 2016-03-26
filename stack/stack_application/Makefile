
CC = gcc

conversion:
	$(CC) -o conversion conversion.c

debug:
	$(CC) -g -o conversion conversion.c

count:
	find . -type f -name "*.[c|h]" -exec cat {} \; | wc -l 

clean:
	rm conversion 


