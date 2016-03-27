
CC = gcc

conversion:
	$(CC) -o conversion conversion.c

check_match:
	$(CC) -o check_match check_match.c

line_edit:
	$(CC) -o line_edit line_edit.c

debug:
	$(CC) -g -o conversion conversion.c

count:
	find . -type f -name "*.[c|h]" -exec cat {} \; | wc -l 

clean:
	rm conversion check_match line_edit


