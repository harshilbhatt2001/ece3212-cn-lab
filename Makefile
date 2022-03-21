CFLAGS = -ggdb -Wall
LIBS = -lm
CC = gcc

all: crc hamming
crc:
	$(CC) crc.c $(LIBS) -o $@
hamming:
	$(CC) hamming.c $(LIBS) -o $@

clean:
	rm -f crc hamming