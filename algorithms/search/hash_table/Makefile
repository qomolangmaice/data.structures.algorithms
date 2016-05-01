CC = gcc

all:
	$(CC) -o main main.c

bucket_hash_table:
	$(CC) -o bucket_hash_table bucket_hash_table.c

debug_main:
	$(CC) -g -gdwarf-2 -gstrict-dwarf -o main main.c

insight_main:
	make debug
	/usr/local/insight/bin/insight main

debug_bucket:
	$(CC) -g -gdwarf-2 -gstrict-dwarf -o bucket_hash_table bucket_hash_table.c

insight_bucket:
	make debug_bucket
	/usr/local/insight/bin/insight bucket_hash_table 

count:
	find . -type f -name "*.[c|h]" -exec cat {} \; | wc -l 

clean:
	rm main bucket_hash_table
