all: compile
	gcc -o bin/MAIN src/main.c tmp/cadastro.o temp/fila.o temp/pilha.o

compile: CADASTRO FILA PILHA
	mv src/*.o temp/

CADASTRO:
	gcc -c src/cadastro.c

FILA: CADASTRO
	gcc -c src/fila.c

PILHA: CADASTRO
	gcc -c src/pilha.c

run:
	./bin/MAIN

clean:
	rm temp/* bin/*
