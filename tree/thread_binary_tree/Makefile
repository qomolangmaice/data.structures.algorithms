CC = g++

all:
	$(CC) -o main main.c

debug:
	$(CC) -g -o main main.c

count:
	find . -type f -name "*.[c|h]" -exec cat {} \; | wc -l 

clean:
	rm main 
