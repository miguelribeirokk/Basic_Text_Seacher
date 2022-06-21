all:
	 gcc -o main main.c cores/cores.c funcoes.c tads/patricia.c tads/lista_patricia.c -lm

run:
	./main