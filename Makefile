CC = gcc
CFLAGS = -std=c11 -Wall -Wextra

.PHONY: all run test clean

all: grafosus

grafosus: main.c grafo.c busca.c grafo.h
	$(CC) $(CFLAGS) main.c grafo.c busca.c -o grafosus

teste-grafo: grafo.c busca.c testes/grafo-teste.c grafo.h
	$(CC) $(CFLAGS) grafo.c busca.c testes/grafo-teste.c -o teste-grafo

run: grafosus
	./grafosus

test: teste-grafo
	./teste-grafo

clean:
	rm -f grafosus teste-grafo
