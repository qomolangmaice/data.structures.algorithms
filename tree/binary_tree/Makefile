CC = g++

all:
	$(CC) -o main main.c

recovery_bin_tree:
	$(CC) -o recovery_bin_tree recovery_bin_tree.c

debug:
	$(CC) -g -o main main.c

count:
	find . -type f -name "*.[c|h]" -exec cat {} \; | wc -l 

clean:
	rm main recovery_bin_tree
