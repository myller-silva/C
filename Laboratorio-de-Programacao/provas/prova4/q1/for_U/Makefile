all: main.e

main.e: main.o vec_i.o
	gcc -o main.e main.o vec_i.o

vec_i.o: vec_i.c vec_i.h
	gcc -o vec_i.o -c vec_i.c

clean:
	clear
	rm -f main.e *.o
