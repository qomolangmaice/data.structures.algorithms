
CC = gcc

conversion_8:
	$(CC) -o conversion_8 conversion_8.c

debug:
	$(CC) -g -o conversion_8 conversion_8.c

count:
	find . -type f -name "*.[c|h]" -exec cat {} \; | wc -l 

clean:
	rm conversion_8 


