CFLAGS = -ggdb -Wall
LIBS = -lm
CC = clang

all: bit_stuffing character_count cnc_poynomial checksum crc hamming dijkstra bellman_ford
bit_stuffing:
	$(CC) bit_stuffing.c $(LIBS) -o $@
character_count:
	$(CC) character_count.c $(LIBS) -o $@
cnc_poynomial:
	$(CC) cnc_poynomial.c $(LIBS) -o $@
checksum:
	$(CC) checksum.c $(LIBS) -o $@
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
	rm -f bit_stuffing character_count cnc_poynomial checksum crc hamming dijkstra bellman_ford distance_vector
