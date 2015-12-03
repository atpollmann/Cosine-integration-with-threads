CC=gcc
all:th_simpson

INCLUDEDIR=./includes
CFLAGS=-I$(INCLUDEDIR)

Utils.o: src/Utils.c $(INCLUDEDIR)/Utils.h
	gcc $(CFLAGS) -c src/Utils.c -o Utils.o 

Options.o: src/Options.c $(INCLUDEDIR)/Options.h Utils.o
	gcc $(CFLAGS) -c src/Options.c -o Options.o

Summation.o: src/Summation.c $(INCLUDEDIR)/Summation.h
	gcc $(CFLAGS) -c src/Summation.c -o Summation.o

Thread.o: src/Thread.c $(INCLUDEDIR)/Thread.h Summation.o
	gcc $(CFLAGS) -c src/Thread.c -o Thread.o

main.o: src/main.c  Options.o Utils.o Summation.o
	gcc $(CFLAGS) -c src/main.c -o main.o

th_simpson: main.o Options.o Utils.o Summation.o Thread.o
	gcc main.o Options.o Utils.o Summation.o Thread.o -o th_simpson

clean:
	rm -f th_simpson *.o
