# Compila e executa o programa do cilindro

all: main

main: main.o cilindro.o
	gcc main.o cilindro.o -lm -o main

main.o: main.c cilindro.h
	gcc -c main.c

cilindro.o: cilindro.c cilindro.h
	gcc -c cilindro.c

run: main
	./main

clean:
	rm -f *.o main
