CC = g++

all:
	$(CC) -o main main.c

debug:
	$(CC) -g -gdwarf-2 -gstrict-dwarf -o main main.c

insight:
	make debug
	/usr/local/insight/bin/insight main

recorery_binary_tree:
	$(CC) -o recorery_binary_tree recorery_binary_tree.c

count:
	find . -type f -name "*.[c|h]" -exec cat {} \; | wc -l 

clean:
	rm main recorery_binary_tree  
