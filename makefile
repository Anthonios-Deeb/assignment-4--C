CC=gcc
AR=ar
CFLAGS= -Wall

all: digitcompress

digitcompress: encodemain.o compress.o
	$(CC) $(CFLAGS) encodemain.o compress.o -o digitcompress

encodemain.o: encodemain.c compress.h
	$(CC) -c encodemain.c

compress.o: compress.c compress.h
	$(CC) -c compress.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so digitcompress