CFLAGS = -ggdb -Wall
LIBS = -lm
CC = clang

all: crc hamming dijkstra bellman_ford
crc:
	$(CC) crc.c $(LIBS) -o $@
hamming:
	$(CC) hamming.c $(LIBS) -o $@
dijkstra:
	$(CC) dijkstra.c $(LIBS) -o $@
bellman_ford:
	$(CC) bellman_ford.c $(LIBS) -o $@
distance_vector:
	$(CC) distance_vector.c $(LIBS) -o $@
clean:
	rm -f crc hamming dijkstra bellman_ford distance_vector
