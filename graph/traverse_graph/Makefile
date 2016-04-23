CC = g++

all:
	$(CC) -o main main.c

non_connect_graph_traverse:
	$(CC) -o non_connect_graph_traverse non_connect_graph_traverse.c

debug:
	$(CC) -g -gdwarf-2 -gstrict-dwarf -o main main.c

insight:
	make debug
	/usr/local/insight/bin/insight main

count:
	find . -type f -name "*.[c|h]" -exec cat {} \; | wc -l 

clean:
	rm main non_connect_graph_traverse
