all: teste.e

teste.e: teste.o vetores.o
	gcc -o teste.e teste.o vetores.o

vetores.o: vetores.c vetores.h
	gcc -o vetores.o -c vetores.c

clean:
	clear
	rm -f *.o teste.e
